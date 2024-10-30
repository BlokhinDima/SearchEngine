#pragma once

#include <string>
#include <iostream>


namespace configs
{
	struct DatabaseSettings
	{
		std::string databaseHost;
		std::string databasePort;
		std::string databaseName;
		std::string username;
		std::string password;
	};

	struct SearchEngineSettings
	{
		std::string startPage;
		std::string recursionDepth;
		std::string port;
	};

	class Config
	{
	public:
		Config() {}
		DatabaseSettings getDatabaseSettings() const { return databaseSettings; }
		SearchEngineSettings getSearchEngineSettings() const { return searchEngineSettings; }
		void setDatabaseSettings(DatabaseSettings& databaseSettings) { this->databaseSettings = databaseSettings; }
		void setEngineSettings(SearchEngineSettings& engineSettings) { this->searchEngineSettings = engineSettings; }

	private:
		DatabaseSettings databaseSettings;
		SearchEngineSettings searchEngineSettings;
	};
}

std::ostream& operator<<(std::ostream& stream, const configs::Config& config);
