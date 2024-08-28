#include <iostream>

#include "crawler.h"


namespace crawlers
{
	std::vector<std::string> Crawler::findLinks(std::string const& htmlBody)
	{
		const std::regex regexURL(R"!!(<\s*A\s+[^>]*href\s*=\s*"([^"]*)")!!", std::regex::icase);
		std::vector<std::string> links;
		std::copy(std::sregex_token_iterator(htmlBody.begin(), htmlBody.end(), regexURL, 1),
			std::sregex_token_iterator(),
			std::ostream_iterator<std::string>(std::cout, "\n"));

		return links;
	}

	std::string Crawler::downloadWebPage(const std::string url)
	{
		auto htmlText = downloader.loadWebPage(url);
		return indexer.indexPage(url, htmlText);
	}
}