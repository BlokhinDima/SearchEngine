#include "searchengine.h"
#include "server.h"


namespace search_engines
{
	SearchEngine::SearchEngine(const std::string& configFile)
	{
		config = configParser.parseConfigFile(configFile);
		std::cout << *config;

		setDatabaseConnectionData(*config);
		database = new databases::SearchDatabase(connectionData);

		indexer = new indexers::Indexer(*database);
		crawler = new crawlers::Crawler(*indexer);

		auto engine_settings = config->getEngineSettings();
		socket = new tcp::socket{ serverIoc };

		auto const address = net::ip::make_address("127.0.0.1");
		
		ep = new tcp::endpoint{ address,  80};
		acceptor = new tcp::acceptor{ serverIoc, *ep };
	}


	SearchEngine::~SearchEngine()
	{
		delete config;
		delete database;
		delete indexer;
		delete crawler;
		delete socket;
		delete acceptor;
		delete ep;
	}


	void SearchEngine::run()
	{
		auto engine_settings = config->getEngineSettings();
		auto result = crawler->downloadWebPage(engine_settings.startPage);
		std::cout << "\nCleared HTML:\n" << result << std::endl;
		http_servers::httpServer(*acceptor, *socket);
		serverIoc.run();
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

}