#pragma once

#include <queue>
#include <mutex>
#include <string>

namespace queue_ts
{
	typedef std::pair<std::string, int> linkLevelPair_t;

	class LinksQueue
	{
	public:
		void push(const linkLevelPair_t& linkLevelPair);
		std::pair<std::string, int> pop();
		int size();

	private:
		std::queue<std::pair<std::string, int>> q;
		std::mutex m;
	};
}