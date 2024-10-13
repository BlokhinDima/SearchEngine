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

	struct EngineSettings
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
		EngineSettings getEngineSettings() const { return engineSettings; }
		void setDatabaseSettings(DatabaseSettings& databaseSettings) { this->databaseSettings = databaseSettings; }
		void setEngineSettings(EngineSettings& engineSettings) { this->engineSettings = engineSettings; }

	private:
		DatabaseSettings databaseSettings;
		EngineSettings engineSettings;
	};
}

std::ostream& operator<<(std::ostream& stream, const configs::Config& config);
