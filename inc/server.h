#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

namespace beast = boost::beast;      
namespace http = beast::http;       
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

namespace http_servers
{
	class HTTPConnection : public std::enable_shared_from_this<HTTPConnection>
	{
	public:
		HTTPConnection(tcp::socket socket) : socket(std::move(socket)) {}

	public:
		void start();

	private:
		tcp::socket socket;
		beast::flat_buffer buffer{ 8192 };
		http::request<http::dynamic_body> request;
		http::response<http::dynamic_body> response;
		net::steady_timer deadline{ socket.get_executor(), std::chrono::seconds(60) };

	private:
		void readRequest();
		void processRequest();
		void createResponse();
		void writeResponse();
		void checkDeadline();
	};


	void httpServer(tcp::acceptor& acceptor, tcp::socket& socket);
}