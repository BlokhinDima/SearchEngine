#pragma once

#include <string>
#include <vector>
#include <regex>
#include <unordered_set>
#include <mutex>

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
		void crawlWebPage(std::string url, int pageLevel);
		std::vector<std::string> findLinks(std::string const& htmlBody);
		void crawl(const std::string& startUrl, int depth);

	private:
		std::mutex m;
		int workingThreads = 0;
		const int maxThreads = 4;
		queue_ts::LinksQueue linksQueue;
		std::unordered_set<std::string> downloadedLinks;
		downloaders::BoostBeastDownloader downloader;
		indexers::Indexer indexer;

	private:
		void createThread();
		void linksToAbsolute(std::string const& parentUrl, std::vector<std::string>& foundLinks);
	};
}