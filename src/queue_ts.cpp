#include "queue_ts.h"

namespace queue_ts
{
	void LinksQueue::push(const linkLevelPair_t& linkLevelPair)
	{
		std::lock_guard<std::mutex> guard(m);
		q.push(linkLevelPair);
	}


	linkLevelPair_t LinksQueue::pop()
	{
		std::lock_guard<std::mutex> guard(m);

		if (q.size() == 0) 
		{
			return linkLevelPair_t("", 0);
		}
		linkLevelPair_t linkLevelPair = q.front();
		q.pop();
		return linkLevelPair;
	}


	int LinksQueue::size()
	{
		std::lock_guard<std::mutex> guard(m);
		return q.size();
	}
}