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
		pqxx::result addWord(const std::string& word);
		pqxx::result addUrl(const std::string& url);
		void addUrlWordCount(const std::string& urlId, const std::string& wordId, const std::string& wordCount);
		std::vector<std::string> selectRankedPages(const std::vector<std::string>& searchRequest);

	private:
		std::unique_ptr<pqxx::connection> conn;

	private:
		int rankPositionsLimit = 10;
		void createTables();
		void createDocumentsTable();
		void createWordsTable();
		void createLinksWordsCountTable();
	};
}