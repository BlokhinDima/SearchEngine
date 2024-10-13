#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <string>
#include <memory>

#include "config.h"
#include "configparser.h"
#include "crawler.h"
#include "database.h"
#include "indexer.h"
#include "server.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

namespace search_engines
{
	class SearchEngine
	{
	public:
		SearchEngine(const std::string& configFile = "");
		~SearchEngine();
		void run();

	private:
		const std::string serverHost = "127.0.0.1";
		uint16_t serverPort;
		const std::string configFile;
		config_parsers::ConfigFileParser configParser;
		configs::Config* config;
		crawlers::Crawler* crawler;
		indexers::Indexer* indexer;
		databases::ConnectionData connectionData;
		databases::SearchDatabase* indexerDatabaseConn;
		databases::SearchDatabase* serverDatabaseConn;
		net::io_context serverIoc{1};
		std::shared_ptr<http_servers::HTTPConnection> httpConnection;
		tcp::socket* socket;
		tcp::acceptor* acceptor;
		tcp::endpoint* ep;

	private:
		void setDatabaseConnectionData(const configs::Config& config);
		void runServer();
		void sendErrorMessage(const std::string& message);
	};
}