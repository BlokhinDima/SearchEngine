#pragma once

#include <string>
#include <utility>
#include <pqxx/pqxx>

namespace databases
{
	struct ConnectionData
	{
		std::string host;
		std::string databaseName;
		std::string login;
		std::string pass;
		std::string port;
	};

	class SearchDatabase
	{
	public:
		SearchDatabase(const ConnectionData& connectionData);
		SearchDatabase(const SearchDatabase&) = delete;
		~SearchDatabase() {}
		SearchDatabase& operator=(const SearchDatabase&) = delete;

	private:
		std::unique_ptr<pqxx::connection> conn;

	private:
		void createTables();
		void createDocumentsTable();
		void createWordsTable();
		void createDocumentsWordsCountTable();
	};
}