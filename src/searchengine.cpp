#include "searchengine.h"

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
	}


	SearchEngine::~SearchEngine()
	{
		delete config;
		delete database;
		delete indexer;
		delete crawler;
	}


	void SearchEngine::run()
	{
		auto engine_settings = config->getEngineSettings();
		auto result = crawler->downloadWebPage(engine_settings.startPage);
		std::cout << result;
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