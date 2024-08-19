// Search Engine
#include <string>
#include <iostream>

#include "searchengine.h"

const std::string CONFIG_FILE = "./config.ini";

int main()
{
	search_engines::SearchEngine searchEngine(CONFIG_FILE);
	searchEngine.run();
	std::cin.get();
}