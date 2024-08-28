#pragma once

#include <string>
#include <vector>
#include <regex>

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
		std::string downloadWebPage(const std::string url);
		std::vector<std::string> findLinks(std::string const& htmlBody);

	private:
		queue_ts::Queue linksQueue;
		downloaders::BoostBeastDownloader downloader;
		indexers::Indexer indexer;
	};
}