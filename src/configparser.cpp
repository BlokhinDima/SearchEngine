#include <iostream>
#include <fstream>
#include <string>

#include "configparser.h"

namespace config_parsers
{
    configs::Config* ConfigFileParser::parseConfigFile(const std::string& configFile)
    {
        try
        {
            std::ifstream file(configFile);
            config_parsers::configData_t configData;
            std::string currentSection;
            std::string line;

            if (!file.is_open())
            {
            }

            while (std::getline(file, line))
            {
                processLine(line, currentSection, configData);
            }

            return createConfig(configData);
        }
        catch (const std::exception& e)
        {
            throw e;
        }
    }


    void ConfigFileParser::processLine(std::string& line, std::string& configSection, configData_t& configData)
    {
        if (line.empty() || line[0] == ';')
        {
            return;
        }

        if (line[0] == '[' && line.back() == ']')
        {
            configSection = line.substr(1, line.size() - 2);
        }
        else
        {
            auto equalsPos = line.find('=');
            if (equalsPos != std::string::npos)
            {
                auto key = line.substr(0, equalsPos);
                auto value = line.substr(equalsPos + 1);
                configData[configSection][key] = value;
            }
        }
    }


    configs::Config* ConfigFileParser::createConfig(configData_t& configData)
    {
        configs::DatabaseSettings databaseSettings;
        databaseSettings.databaseHost = configData["database"]["host"];
        databaseSettings.databasePort = configData["database"]["port"];
        databaseSettings.databaseName = configData["database"]["name"];
        databaseSettings.username = configData["database"]["username"];
        databaseSettings.password = configData["database"]["password"];

        configs::EngineSettings engineSettings;
        engineSettings.recursionDepth = configData["settings"]["recursiondepth"];
        engineSettings.startPage = configData["settings"]["startpage"];
        engineSettings.port = configData["settings"]["port"];

        configs::Config* config = new configs::Config();
        config->setEngineSettings(engineSettings);
        config->setDatabaseSettings(databaseSettings);

        return config;
    }
}