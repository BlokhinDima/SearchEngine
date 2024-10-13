#pragma once

#include <map>
#include <string>
#include "config.h"

namespace config_parsers
{
	typedef std::map<std::string, std::map<std::string, std::string>> configData_t;

	class ConfigFileParser
	{
	public:
		ConfigFileParser() {}
		configs::Config* parseConfigFile(const std::string& configFile);

	private:
		void processLine(std::string& line, std::string& configSection, configData_t& configData);
		configs::Config* createConfig(configData_t& configData);
	};
}