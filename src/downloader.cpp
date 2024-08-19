#include "downloader.h"

namespace downloaders
{
	std::string BoostBeastDownloader::loadWebPage(const std::string& url)
	{
		std::smatch sm;
		if (std::regex_match(url, sm, regexURL))
		{
			const std::string host = sm[2].str();
			const std::string target = sm[3].length() == 0 ? "/" : sm[3].str();

			std::string port;
			if (sm[1].str() == "http")
			{
				port = "80";
			}
			if (sm[1].str() == "https")
			{
				port = "443";
			}

			return load(host, port, target);
		}
		else
		{
			return "";
		}
	}

	std::string BoostBeastDownloader::load(const std::string& host, const std::string& port, const std::string& target)
	{
		try
		{
			int version = 11;

			tcp::resolver resolver(ioc);
			auto const results = resolver.resolve(host, port);

			beast::tcp_stream stream(ioc);
			stream.connect(results);

			http::request<http::string_body> req{ http::verb::get, target, version };
			req.set(http::field::host, host);
			req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

			http::write(stream, req);

			beast::flat_buffer buffer;

			http::response<http::dynamic_body> res;

			http::read(stream, buffer, res);

			//std::cout << res << std::endl;

			beast::error_code ec;
			stream.socket().shutdown(tcp::socket::shutdown_both, ec);

			return boost::beast::buffers_to_string(res.body().data());

		}
		catch (std::exception const& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}