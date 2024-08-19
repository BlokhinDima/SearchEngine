#include <iostream>
#include <string>
#include <algorithm>

#include "indexer.h"
#include "boost/algorithm/string.hpp"


namespace indexers
{
	std::string Indexer::indexPage(const std::string& url, std::string& htmlText)
	{
		auto formattedText = formatText(htmlText);
		conutWords(formattedText);
		return formattedText;
	}


	std::string Indexer::formatText(std::string& text)
	{
		auto clearedText = removeHTMLTags(text);
		removeTabs(clearedText);
		removeNewlines(clearedText);
		setLowercase(clearedText);
		removePunctuationMarks(clearedText);
		removeExtraSpaces(clearedText);
		return clearedText;
	}


	std::string Indexer::removeHTMLTags(std::string& htmlText)
	{
		std::regex tags("<[^>]*>");
		std::string remove{};
		return std::regex_replace(htmlText, tags, remove);
	}


	void Indexer::removeTabs(std::string& text)
	{
		boost::replace_all(text, "\t", " ");
	}


	void Indexer::removeNewlines(std::string& text)
	{
		boost::replace_all(text, "\r\n", " ");
	}


	void Indexer::setLowercase(std::string& text)
	{
		boost::algorithm::to_lower(text);
	}


	void Indexer::removeExtraSpaces(std::string& text)
	{
		boost::trim(text);
		while (text.find("  ") != text.npos)
		{
			boost::replace_all(text, "  ", " ");
		}
	}


	void Indexer::removePunctuationMarks(std::string& text)
	{
		text.erase(std::remove_if(text.begin(), text.end(), ispunct), text.end());
	}


	WordsCount Indexer::conutWords(std::string& text)
	{
		WordsCount wordsCount;
		std::istringstream stringStream(text);
		std::string word;
		
		while (stringStream >> word) 
		{ 
			wordsCount[word]++;
		}

		for (const auto& it : wordsCount)
		{ 
			std::cout << it.first << ": Occurs " << it.second << std::endl; 
		}

		return wordsCount;
	}
}