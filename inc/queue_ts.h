#pragma once

#include <queue>
#include <mutex>
#include <string>

namespace queue_ts
{
	class Queue
	{
	public:
		void push(std::string& str);
		std::string pop();
		int size();

	private:
		std::queue<std::string> q;
		std::mutex m;
	};
}