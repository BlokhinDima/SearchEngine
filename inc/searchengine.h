#pragma once

#include <string>
#include <memory>

#include "config.h"
#include "configparser.h"
#include "crawler.h"
#include "database.h"
#include "indexer.h"
#include "server.h"


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
		crawlers::Crawler* crawler;
		indexers::Indexer* indexer;
		databases::ConnectionData connectionData;
		databases::SearchDatabase* database;
		net::io_context serverIoc{ 1 };
		std::shared_ptr<http_servers::HTTPConnection> httpConnection;
		tcp::socket* socket;
		tcp::acceptor* acceptor;
		tcp::endpoint* ep;

	private:
		void setDatabaseConnectionData(const configs::Config& config);
	};
}