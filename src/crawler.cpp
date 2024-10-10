#include <iostream>

#include <vector>
#include <regex>
#include <thread>
#include <mutex>
#include <algorithm>

#include "crawler.h"
#include "queue_ts.h"
#include "downloader.h"


namespace crawlers
{
	void Crawler::crawl(const std::string& startUrl, int depth)
	{
		linksQueue.push(queue_ts::linkLevelPair_t(startUrl, depth));

		for (;;)
		{
			if (linksQueue.size() != 0)
			{
				if (workingThreads < maxThreads)
				{
					createThread();
				}
			}
			else if (workingThreads == 0)
			{
				break;
			}
		}

		std::cout << "\nCrawl done!\n";
	}


	void Crawler::createThread()
	{
		auto linkLevelPair = linksQueue.pop();
		auto currentUrl = linkLevelPair.first;
		auto pageLevel = linkLevelPair.second;

		if (downloadedLinks.count(currentUrl) == 0)
		{
			std::thread* thread = new std::thread(&Crawler::crawlWebPage, this, currentUrl, pageLevel);
			(*thread).detach();
			workingThreads++;
		}
	}


	void Crawler::linksToAbsolute(std::string const& parentUrl, std::vector<std::string>& foundLinks)
	{
		std::smatch sm;

		for (auto& link : foundLinks)
		{
			if (link.find("//") == 0) // relatively to protocol
			{
				std::regex_search(parentUrl, sm, std::regex{ "^[^/]+" });
				link = sm.str() + link;
			}
			else if (link.find('/') == 0) // relatively to host name
			{
				std::regex_search(parentUrl, sm, std::regex{ "^[^/]+//[^/]+" });
				link = sm.str() + link;
			}
			else if (link.find("../") == 0) // ralatively to parent directory
			{
				int ind = std::string::npos;
				int cnt = (link.rfind("../") + 3) / 3;
				for (int i = 0; i < cnt + 1; ++i)
				{
					ind = parentUrl.rfind('/', ind - 1);
				}
				link = std::string{ parentUrl.begin(), parentUrl.begin() + ind + 1 } + std::string{ link.begin() + cnt * 3, link.end() };
			}
			else if (std::regex_match(link, std::regex{ "(?:[^/]+/)+[^/]+" }) || (link.find("#") == 0)) // anchor link
			{
				link = " ";
			}
		}

		foundLinks.erase(std::remove(foundLinks.begin(), foundLinks.end(), " "), foundLinks.end());
	}


	std::vector<std::string> Crawler::findLinks(std::string const& htmlBody)
	{
		const std::regex regexURL(R"!!(<\s*A\s+[^>]*href\s*=\s*"([^"]*)")!!", std::regex::icase);
		std::vector<std::string> links;
		std::copy(std::sregex_token_iterator(htmlBody.begin(), htmlBody.end(), regexURL, 1),
			std::sregex_token_iterator(),
			std::back_inserter(links));

		return links;
	}


	void Crawler::crawlWebPage(std::string url, int pageLevel)
	{
		auto htmlText = downloader.loadWebPage(url);

		if (pageLevel - 1 != 0)
		{
			auto foundedLinks = findLinks(htmlText);
			linksToAbsolute(url, foundedLinks);

			m.lock();
			std::cout << "Links added: " << foundedLinks.size() << std::endl;
			m.unlock();

			for (auto& link : foundedLinks)
			{
				if (downloadedLinks.count(link) == 0)
				{
					linksQueue.push(queue_ts::linkLevelPair_t(link, pageLevel - 1));
				}
			}
		}

		m.lock();
		indexer.indexPage(url, htmlText);
		downloadedLinks.insert(url);
		workingThreads--;
		std::cout << "Link crawled: " << url << " Level: " << pageLevel << " Working threads: " << workingThreads << " Links to crawl: " << linksQueue.size() << std::endl;
		m.unlock();
	}


	std::string Crawler::downloadWebPage(const std::string& url) // FOR TEST
	{
		auto htmlText = downloader.loadWebPage(url);
		auto foundLinks = findLinks(htmlText);

		std::cout << "Founded links: " << std::endl;
		for (const auto& link : foundLinks) std::cout << link << std::endl;

		std::cout << std::endl;

		linksToAbsolute(url, foundLinks);

		std::cout << "Founded links: " << std::endl;
		for (const auto& link : foundLinks) std::cout << link << std::endl;

		return indexer.indexPage(url, htmlText);
	}
}