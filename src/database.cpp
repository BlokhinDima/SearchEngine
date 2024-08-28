#include <iostream>
#include "database.h"

namespace databases
{
	SearchDatabase::SearchDatabase(const ConnectionData& connectionData)
	{
		try
		{
			conn = std::make_unique<pqxx::connection>(
				"dbname=" + connectionData.databaseName +
				" user=" + connectionData.login +
				" password=" + connectionData.pass +
				" host=" + connectionData.host +
				" port=" + connectionData.port);

			createTables();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			throw e;
		}
	}


	void SearchDatabase::createTables()
	{
		createDocumentsTable();
		createWordsTable();
		createLinksWordsCountTable();
	}
	

	void SearchDatabase::createDocumentsTable() 
	{
		try
		{
			std::string query =
				"CREATE TABLE IF NOT EXISTS links"
				"(id SERIAL primary key, "
				"link VARCHAR(2048));";

			pqxx::transaction tx{ *conn };
			tx.exec(query);
			tx.commit();
		}
		catch (const std::exception& e)
		{
			throw e;
		}
	}


	void SearchDatabase::createWordsTable()
	{
		try
		{
			std::string query =
				"CREATE TABLE IF NOT EXISTS words"
				"(id SERIAL primary key, "
				"word VARCHAR(32));";

			pqxx::transaction tx{ *conn };
			tx.exec(query);
			tx.commit();
		}
		catch (const std::exception& e)
		{
			throw e;
		}
	}


	void SearchDatabase::createLinksWordsCountTable()
	{
		try
		{
			std::string query =
				"CREATE TABLE IF NOT EXISTS links_words_count"
				"(link_id integer references links(id) ON DELETE CASCADE, "
				"word_id integer references words(id), "
				"word_count integer not null, "
				"constraint links_words_pk primary key (link_id, word_id) );";

			pqxx::transaction tx{ *conn };
			tx.exec(query);
			tx.commit();
		}
		catch (const std::exception& e)
		{
			throw e;
		}
	}


	pqxx::result SearchDatabase::addUrl(const std::string& url)
	{
		try
		{
			pqxx::transaction tx{ *conn };

			std::string query =
				"INSERT INTO links (id, link)"
				"VALUES (DEFAULT, '" + tx.esc(url) + "') RETURNING id; ";

			pqxx::result result = tx.exec(query);
			tx.commit();
			return result;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
			throw e;
		}
	}


	pqxx::result SearchDatabase::addWord(const std::string& word)
	{
		try
		{
			pqxx::transaction tx{ *conn };

			std::string query =
				"INSERT INTO words (id, word)"
				"VALUES (DEFAULT, '" + tx.esc(word) +"') RETURNING id; ";

			pqxx::result result = tx.exec(query);
			tx.commit();
			return result;
		}
		catch (const std::exception& e)
		{
			throw e;
		}
	}

	
	void SearchDatabase::addUrlWordCount(const std::string& urlId, const std::string& wordId, const std::string& wordCount)
	{
		try
		{
			pqxx::transaction tx{ *conn };

			std::string query =
				"INSERT INTO links_words_count (link_id, word_id, word_count)"
				"VALUES ('" + tx.esc(urlId) + "', '" + tx.esc(wordId) + "', '" + tx.esc(wordCount) + "'); ";

			pqxx::result result = tx.exec(query);
			tx.commit();
		}
		catch (const std::exception& e)
		{
			throw e;
		}
	}
}