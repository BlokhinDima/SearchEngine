#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>

#include "configparser.h"

namespace config_parsers
{
    std::unique_ptr<configs::Config> ConfigFileParser::createConfigFromFile(const std::string& configFile)
    {
        try
        {
            std::ifstream file(configFile);
            config_parsers::configData_t configData;
            std::string currentSection;
            std::string line;

            if (!file.is_open())
            {
                throw std::runtime_error("Could not open configuration file");
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


    std::unique_ptr<configs::Config> ConfigFileParser::createConfig(configData_t& configData)
    {
        configs::DatabaseSettings databaseSettings;
        databaseSettings.databaseHost = configData["database"]["host"];
        databaseSettings.databasePort = configData["database"]["port"];
        databaseSettings.databaseName = configData["database"]["name"];
        databaseSettings.username = configData["database"]["username"];
        databaseSettings.password = configData["database"]["password"];

        configs::SearchEngineSettings searchEngineSettings;
        searchEngineSettings.recursionDepth = configData["settings"]["recursiondepth"];
        searchEngineSettings.startPage = configData["settings"]["startpage"];
        searchEngineSettings.port = configData["settings"]["port"];

        std::unique_ptr<configs::Config> config(new configs::Config());
        config->setEngineSettings(searchEngineSettings);
        config->setDatabaseSettings(databaseSettings);

        return config;
    }
}