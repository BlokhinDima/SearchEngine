#pragma once

#include <string>
#include <vector>
#include <regex>
#include <unordered_set>

#include "queue_ts.h"
#include "downloader.h"
#include "indexer.h"
#include "database.h"


namespace crawlers
{
	class Crawler
	{
	public:
		Crawler(indexers::Indexer& indexer) : indexer(indexer) {};
		void crawlWebPage(const std::string& url);
		std::vector<std::string> findLinks(std::string const& htmlBody);
		void crawl(const std::string& startUrl, int depth);
		std::string downloadWebPage(const std::string& url); // FOR TEST

	private:
		queue_ts::Queue linksQueue;
		std::unordered_set<std::string> downloadedLinks;
		downloaders::BoostBeastDownloader downloader;
		indexers::Indexer indexer;

	private:
		void createThread();
		void linksToAbsolute(std::string const& parentUrl, std::vector<std::string>& foundLinks);
	};
}