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
				"link VARCHAR(2048), "
				"UNIQUE (link) "
				"); ";

			pqxx::transaction tx{ *conn };
			tx.exec(query);
			tx.commit();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
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
				"word VARCHAR(32), "
				"UNIQUE (word)"
				"); ";

			pqxx::transaction tx{ *conn };
			tx.exec(query);
			tx.commit();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
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
			std::cout << e.what();
			throw e;
		}
	}


	pqxx::result SearchDatabase::addUrl(const std::string& url)
	{
		try
		{
			pqxx::transaction tx{ *conn };

			std::string query =
				"WITH e AS( "
				"INSERT INTO links (id, link)"
				"VALUES (DEFAULT, '" + tx.esc(url) + "') "
				"ON CONFLICT(link) DO NOTHING RETURNING id) "
				"SELECT * FROM e "
				"UNION SELECT id FROM links WHERE link='" + tx.esc(url) + "';";

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
				"WITH e AS( "
				"INSERT INTO words (id, word)"
				"VALUES (DEFAULT, '" + tx.esc(word) + "') "
				"ON CONFLICT(word) DO NOTHING RETURNING id) "
				"SELECT * FROM e "
				"UNION SELECT id FROM words WHERE word='" + tx.esc(word) + "';";

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

	
	void SearchDatabase::addUrlWordCount(const std::string& urlId, const std::string& wordId, const std::string& wordCount)
	{
		try
		{
			pqxx::transaction tx{ *conn };

			std::string query =
				"INSERT INTO links_words_count (link_id, word_id, word_count)"
				"VALUES ('" + tx.esc(urlId) + "', '" + tx.esc(wordId) + "', '" + tx.esc(wordCount) + "')"
				"ON CONFLICT(link_id, word_id) DO NOTHING; ";

			pqxx::result result = tx.exec(query);
			tx.commit();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
			throw e;
		}
	}


	std::vector<std::string> SearchDatabase::selectRankedPages(const std::vector<std::string>& searchRequest)
	{
		try
		{
			std::string whereCondition = "(";

			for (int i = 0; i < searchRequest.size(); i++)
			{
				whereCondition += searchRequest.at(i);
				if (i < searchRequest.size() - 1) whereCondition += ")|(";
			}
			whereCondition += ") ";
			
			std::cout << whereCondition << std::endl;

			pqxx::transaction tx{ *conn };

			std::string query =
				"SELECT link, SUM(word_count) as sum_words_count FROM links_words_count "
				"LEFT JOIN links ON links.id = links_words_count.link_id "
				"LEFT JOIN words ON words.id = links_words_count.word_id "
				"WHERE word ~ '" + tx.esc(whereCondition) + "' "
				"GROUP BY link "
				"ORDER BY sum_words_count DESC "
				"LIMIT " + tx.esc(std::to_string(rankPositionsLimit)) + ";";

			pqxx::result result = tx.exec(query);

			std::size_t const num_rows = std::size(result);
			std::size_t const num_cols = result.columns();

			for (std::size_t rownum = 0; rownum < num_rows; ++rownum)
			{
				pqxx::row const row = result[rownum];
				for (std::size_t colnum = 0; colnum < num_cols; ++colnum)
				{
					pqxx::field const field = row[colnum];
					std::cout << field.c_str() << '\t';
				}

				std::cout << '\n';
			}

			return searchRequest;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
			throw e;
		}
	}
}