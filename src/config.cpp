#include "config.h"


configs::Config::Config()
{
}


std::ostream& operator<<(std::ostream& stream, const configs::Config& config)
{
	auto databaseSettings = config.getDatabaseSettings();
	auto engineSettings = config.getEngineSettings();

	return stream 
		<< "Database Host: " << databaseSettings.databaseHost << std::endl
		<< "Database Port: " << databaseSettings.databasePort << std::endl
		<< "Database Name: " << databaseSettings.databaseName << std::endl
		<< "User: " << databaseSettings.username << std::endl
		<< "Password: " << databaseSettings.password << std::endl
		<< "Start Page: " << engineSettings.startPage << std::endl
		<< "Recursion Depth: " << engineSettings.recursionDepth << std::endl
		<< "Port: " << engineSettings.port << std::endl;
}