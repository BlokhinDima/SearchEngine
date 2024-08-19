#pragma once

#include <string>

#include "config.h"
#include "configparser.h"
#include "crawler.h"
#include "database.h"

namespace search_engines
{
	class SearchEngine
	{
	public:
		SearchEngine(const std::string& configFile = "");
		~SearchEngine();
		void run();

	private:
		config_parsers::ConfigFileParser configParser;
		configs::Config* config;
		crawlers::Crawler crawler;
		databases::ConnectionData connectionData;
		databases::SearchDatabase* database;

	private:
		void setDatabaseConnectionData(const configs::Config& config);
	};
}