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
            response.result(http::status::ok);
            response.set(http::field::server, "Beast");
            std::cout << boost::beast::buffers_to_string(request.body().data());
            createResponse();
            break;

        case http::verb::post:
            std::cout << boost::beast::buffers_to_string(request.body().data());
            createResponse();
            break;

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
        else if (request.method() != http::verb::post)
        {
            response.set(http::field::content_type, "text/html");
            beast::ostream(response.body())
                << "<html>\n"
                << "<style>\n"
                << "input{\n"
                << "border - radius: 24px;\n"
                << "border: 1px solid #dfe1e5;\n"
                << "background: #fff;\n"
                << "padding: 20px;\n"
                << "display: flex;\n"
                << "z - index: 3;\n"
                << "width: 638px;\n"
                << "height: 44px;\n"
                << "margin: 20px;}\n"
                << "input:hover{\n"
                << "box - shadow: 0 0 8px 1px #e1e1e1;}\n"
                << "</style>\n"
                << "<form action=\"127.0.0.1\"\n"
                << "method=\"post\" target=\"_blank\" id=\"search - form\">\n"
                << "<input name = \"q\" type = \"text\" placeholder = \"Search\"\n"
                << "autocomplete=\"off\" autofocus></form>\n"
                << "</html>\n";
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

    void httpServer(tcp::acceptor& acceptor, tcp::socket& socket)
    {
        acceptor.async_accept(socket,
            [&](beast::error_code ec)
            {
                if (!ec)
                    std::make_shared<HTTPConnection>(std::move(socket))->start();
                httpServer(acceptor, socket);
            });
    }
}