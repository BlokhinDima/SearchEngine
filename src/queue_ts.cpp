#include "queue_ts.h"

namespace queue_ts
{
	void Queue::push(std::string& str)
	{
		std::lock_guard<std::mutex> guard(m);
		q.push(str);
	}


	std::string Queue::pop()
	{
		std::lock_guard<std::mutex> guard(m);

		if (q.size() == 0) 
		{
			return "";
		}
		std::string str = q.front();
		q.pop();
		return str;
	}


	int Queue::size()
	{
		std::lock_guard<std::mutex> guard(m);
		return q.size();
	}
}