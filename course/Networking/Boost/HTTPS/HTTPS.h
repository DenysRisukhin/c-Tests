//
//  HTTPS.h
//  Test2019
//
//  Created by Risukhin Denys on 9/26/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef HTTPS_h
#define HTTPS_h

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/http.hpp>
#include <iostream>
#include <memory>
#include <unordered_map>

// client

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;

using tcp = asio::ip::tcp;
namespace ssl = asio::ssl;

//HttpsClient: The concrete class that handles the HTTPS request and response using Boost.Beast and SSL. The method sendRequest performs all the steps to establish a connection, send an HTTP request, and read the response.
//HttpsClientProxy: A proxy class that intercepts calls to the real HTTPS client (HttpsClient). It can be extended to add functionality like logging, caching, or security checks.
//IHttpClient Interface: Defines the contract for HTTP clients, making it easy to extend or replace the underlying HTTPS implementation while keeping the same interface.

// Interface for HTTP client (IHttpClient)
class IHttpClient
{
public:
    virtual std::string sendRequest(const std::string& host, const std::string& target) = 0;
    
    virtual ~IHttpClient() = default;
};

// Concrete implementation of HTTP client using Boost.Beast (HttpsClient)

//Uses Boost.Beast to perform an HTTPS GET request.
//Resolves the host, establishes an SSL connection, sends an HTTP GET request, and handles the response.

class HttpsClient : public IHttpClient
{
public:
    HttpsClient(asio::io_context& ioc, ssl::context& sslCtx)
        : m_resolver(ioc), m_stream(ioc, sslCtx) {}

    std::string sendRequest(const std::string& host, const std::string& target) override
    {
        try {
            // Resolve the domain name
            auto const results = m_resolver.resolve(host, "https");

            // Make the connection on the IP address we get from a lookup
            beast::get_lowest_layer(m_stream).connect(results);

            // Perform the SSL handshake
            m_stream.handshake(ssl::stream_base::client);

            // Set up an HTTP GET request
            http::request<http::string_body> req{http::verb::get, target, 11};
            req.set(http::field::host, host);
            req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

            // Send the HTTP request
            http::write(m_stream, req);

            // Buffer for reading
            beast::flat_buffer buffer;

            // Container to hold the response
            http::response<http::string_body> res;

            // Receive the HTTP response
            http::read(m_stream, buffer, res);

            // Gracefully close the SSL stream
            beast::error_code ec;
            m_stream.shutdown(ec);
            
            if (ec == asio::error::eof)
            {
                ec = {};
            }
            
            if (ec)
            {
                throw beast::system_error{ec};
            }

            return res.body();
        } catch (std::exception const& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return "";
        }
    }

private:
    tcp::resolver m_resolver;
    beast::ssl_stream<beast::tcp_stream> m_stream;
};

// Proxy for controlling access to the real HTTP client (HttpsClientProxy)
// Acts as a mediator between the client and the real HTTP implementation.
// Adds functionality (logging in this case), which can be expanded to include caching, security, or request filtering.

// Proxy for controlling access to the real HTTP client (HttpsClientProxy)
class HttpsClientProxy : public IHttpClient
{
public:
    HttpsClientProxy(std::shared_ptr<IHttpClient> realClient)
        : m_realClient(realClient) {}

    std::string sendRequest(const std::string& host, const std::string& target) override {
        // Check if the response is cached
        std::string cacheKey = host + target;
        if (m_cache.find(cacheKey) != m_cache.end()) {
            std::cout << "Proxy: Cache hit for " << cacheKey << std::endl;
            return m_cache[cacheKey]; // Return cached response
        }

        std::cout << "Proxy: Sending HTTPS request to " << host << std::endl;

        // Log the request
        logRequest(host, target);

        // Forward the request to the real client
        std::string response = m_realClient->sendRequest(host, target);

        // Cache the response
        m_cache[cacheKey] = response;

        // Log the response
        logResponse(response);

        return response;
    }

private:
    // Logging function for requests
    void logRequest(const std::string& host, const std::string& target)
    {
        std::cout << "Logging: Requesting " << "https://" << host << target << std::endl;
    }

    // Logging function for responses
    void logResponse(const std::string& response)
    {
        std::cout << "Logging: Response received (length: " << response.size() << " characters)" << std::endl;
    }
    
private:
    std::shared_ptr<IHttpClient> m_realClient;
    std::unordered_map<std::string, std::string> m_cache; // Simple cache for storing responses
};


// Main function to demonstrate usage
//int main() {
//    try {
//        asio::io_context ioc;
//        ssl::context sslCtx(ssl::context::sslv23_client);
//
//        // Create real HTTPS client
//        std::shared_ptr<IHttpClient> httpsClient = std::make_shared<HttpsClient>(ioc, sslCtx);
//
//        // Create proxy and inject real client
//        HttpsClientProxy proxy(httpsClient);
//
//        // Send request via proxy
//        std::string result1 = proxy.sendRequest("www.example.com", "/");
//
//        // Simulate another identical request to demonstrate caching
//        std::string result2 = proxy.sendRequest("www.example.com", "/");
//
//        // Output the result
//        std::cout << "Response body: " << result1 << std::endl;
//    } catch (const std::exception& e) {
//        std::cerr << "Exception: " << e.what() << std::endl;
//    }
//    return 0;
//}

#endif /* HTTPS_h */
