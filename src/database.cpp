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
		createDocumentsWordsCountTable();
	}
	

	void SearchDatabase::createDocumentsTable() 
	{
		try
		{
			std::string query =
				"CREATE TABLE IF NOT EXISTS documents"
				"(id SERIAL primary key, "
				"link VARCHAR(2048), "
				"page_text TEXT);";

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


	void SearchDatabase::createDocumentsWordsCountTable()
	{
		try
		{
			std::string query =
				"CREATE TABLE IF NOT EXISTS documents_words_count"
				"(document_id integer references documents(id) ON DELETE CASCADE, "
				"word_id integer references words(id), "
				"word_count integer not null, "
				"constraint documents_words_pk primary key (document_id, word_id) );";

			pqxx::transaction tx{ *conn };
			tx.exec(query);
			tx.commit();
		}
		catch (const std::exception& e)
		{
			throw e;
		}
	}
}