#include <boost/algorithm/string.hpp>
#include <boost/beast/http/string_body.hpp>

#include "server.h"


namespace my_program_state
{
    std::size_t request_count()
    {
        static std::size_t count = 0;
        return ++count;
    }

    std::time_t now()
    {
        return std::time(0);
    }
}


namespace http_servers
{
    void HTTPConnection::start()
    {
        readRequest();
        checkDeadline();
    }


    void HTTPConnection::readRequest()
    {
        auto self = shared_from_this();

        http::async_read(
            socket,
            buffer,
            request,
            [self](beast::error_code ec,
                std::size_t bytes_transferred)
            {
                boost::ignore_unused(bytes_transferred);
                if (!ec)
                {
                    self->processRequest();
                }
            });
    }


    void HTTPConnection::processRequest()
    {
        response.version(request.version());
        response.keep_alive(false);

        switch (request.method())
        {
        case http::verb::get:
        {
            response.result(http::status::ok);
            response.set(http::field::server, "SearchEngine");
            createResponse();
            break;
        }
        case http::verb::post:
        {
            auto searchQuery = boost::beast::buffers_to_string(request.body().data());
            auto searchRequestWords = getSearchWords(searchQuery);
            database.selectRankedPages(searchRequestWords);
            createResponse();
            break;
        }
        default:
            // We return responses indicating an error if
            // we do not recognize the request method.
            response.result(http::status::bad_request);
            response.set(http::field::content_type, "text/plain");
            beast::ostream(response.body())
                << "Invalid request-method '"
                << std::string(request.method_string())
                << "'";
            break;
        }

        writeResponse();
    }


    void HTTPConnection::createResponse()
    {
        if (request.target() == "/count")
        {
            response.set(http::field::content_type, "text/html");
            beast::ostream(response.body())
                << "<html>\n"
                << "<head><title>Request count</title></head>\n"
                << "<body>\n"
                << "<h1>Request count</h1>\n"
                << "<p>There have been "
                << my_program_state::request_count()
                << " requests so far.</p>\n"
                << "</body>\n"
                << "</html>\n";
        }
        else if (request.target() == "/time")
        {
            response.set(http::field::content_type, "text/html");
            beast::ostream(response.body())
                << "<html>\n"
                << "<head><title>Current time</title></head>\n"
                << "<body>\n"
                << "<h1>Current time</h1>\n"
                << "<p>The current time is "
                << my_program_state::now()
                << " seconds since the epoch.</p>\n"
                << "</body>\n"
                << "</html>\n";
        }
        else if (request.method() == http::verb::post)
        {
            response.set(http::field::content_type, "text/html");
            beast::ostream(response.body()) << html::mainPage;
        }
        else
        {
            response.set(http::field::content_type, "text/html");
            beast::ostream(response.body()) << html::mainPage;
        }
    }


    void HTTPConnection::writeResponse()
    {
        auto self = shared_from_this();

        response.content_length(response.body().size());

        http::async_write(
            socket,
            response,
            [self](beast::error_code ec, std::size_t)
            {
                self->socket.shutdown(tcp::socket::shutdown_send, ec);
                self->deadline.cancel();
            });
    }


    void HTTPConnection::checkDeadline()
    {
        auto self = shared_from_this();

        deadline.async_wait(
            [self](beast::error_code ec)
            {
                if (!ec)
                {
                    // Close socket to cancel any outstanding operation.
                    self->socket.close(ec);
                }
            });
    }


    std::vector<std::string> HTTPConnection::getSearchWords(std::string& searchQuery)
    {
        std::vector<std::string> searchRequestWords;
        searchQuery.erase(0, 2);
        boost::split(searchRequestWords, searchQuery, boost::is_any_of("+"));

        for (const auto& word : searchRequestWords)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;

        return searchRequestWords;
    }


    void httpServer(tcp::acceptor& acceptor, tcp::socket& socket, databases::SearchDatabase& database)
    {
        acceptor.async_accept(socket,
            [&](beast::error_code ec)
            {
                if (!ec)
                {
                    auto httpConnection = std::make_shared<http_servers::HTTPConnection>(std::move(socket), database);
                    httpConnection->start();
                }
                httpServer(acceptor, socket, database);
            });
    }
}