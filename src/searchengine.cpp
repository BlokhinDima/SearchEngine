#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <chrono>
#include <thread>

#include "searchengine.h"
#include "server.h"

namespace beast = boost::beast;	               // from <boost/beast.hpp>
namespace http = beast::http;	               // from <boost/beast/http.hpp>
namespace websocket = beast::websocket;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;					   // from <boost/asio/ip/tcp.hpp>

namespace search_engines
{
	using namespace std::chrono_literals;

	SearchEngine::SearchEngine(const std::string& configFile) : configFile(configFile)
	{
		try
		{
			config = configParser.parseConfigFile(configFile);
			std::cout << "Search Engine Configuration:/n" << *config;
		}
		catch (const std::exception& e)
		{
			std::cout << "Configuration file error: " << e.what();
		}

		setDatabaseConnectionData(*config);
		indexerDatabaseConn = new databases::SearchDatabase(connectionData);
		serverDatabaseConn = new databases::SearchDatabase(connectionData);

		indexer = new indexers::Indexer(*indexerDatabaseConn);
		crawler = new crawlers::Crawler(*indexer);

		auto engineSettings = config->getEngineSettings();
		serverPort = std::stoul(engineSettings.port);

		socket = new tcp::socket{serverIoc};
		auto const address = net::ip::make_address(serverHost);
		ep = new tcp::endpoint{address,  serverPort};
		acceptor = new tcp::acceptor{serverIoc, *ep};
	}


	SearchEngine::~SearchEngine()
	{
		delete config;
		delete indexerDatabaseConn;
		delete serverDatabaseConn;
		delete indexer;
		delete crawler;
		delete socket;
		delete acceptor;
		delete ep;
	}

	
	void SearchEngine::run()
	{
		try 
		{
			std::thread* thread = new std::thread(&SearchEngine::runServer, this);
			(*thread).detach();

			auto engine_settings = config->getEngineSettings();
			crawler->crawl(engine_settings.startPage, stoi(engine_settings.recursionDepth));
		}
		catch (const std::exception& e)
		{
			sendErrorMessage(e.what());
		}
	}

	
	void SearchEngine::setDatabaseConnectionData(const configs::Config& config)
	{
		auto databaseConfig = config.getDatabaseSettings();

		connectionData.host = databaseConfig.databaseHost;
		connectionData.port = databaseConfig.databasePort;
		connectionData.databaseName = databaseConfig.databaseName;
		connectionData.login = databaseConfig.username;
		connectionData.pass = databaseConfig.password;
	}


	void SearchEngine::runServer()
	{
		http_servers::httpServer(*acceptor, *socket, *serverDatabaseConn);
		serverIoc.run();
	}


	void SearchEngine::sendErrorMessage(const std::string& message)
	{
		asio::io_context context;
		beast::tcp_stream stream(context);

		stream.connect(tcp::resolver(context).resolve(*ep));
		http::request<http::string_body> request;
		request.version(11);
		request.method(http::verb::post);
		request.target("/error");
		request.set(http::field::host, serverHost);
		request.set(http::field::content_type, "text/plain");
		request.body() = message;
		request.prepare_payload();

		boost::beast::http::write(stream, request);
	}
}