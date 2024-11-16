//
//  Proxy.h
//  Test2019
//
//  Created by Risukhin Denys on 1/15/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Proxy_h
#define Proxy_h

//The Proxy pattern is a structural design pattern where a surrogate or placeholder object controls access to another object. This is useful when you want to add some level of control or functionality to the access of an object
//Proxy pattern is commonly used in networking scenarios. In the context of networking, a proxy acts as an intermediary between a client and a server, facilitating communication between them. There are various types of proxies used in networking, each serving different purposes:

//1 Forward Proxy:
//Acts on behalf of clients and forwards requests to servers. (действует от имени клиентов и перенаправляет запросы на серверы.)
//Used for controlling access to the internet, caching, and logging.

//2 Reverse Proxy:
//Acts on behalf of servers and handles requests from clients.
//Used for load balancing, security, and caching.

//3 Caching Proxy:
//Stores copies of frequently requested resources locally to reduce latency and improve performance.
//Used for speeding up access to frequently accessed content.

//4 Security Proxy:
//Adds an extra layer of security by filtering and monitoring traffic.
//Used for protecting against malicious requests and unauthorized access.

//5 Gateway:
//Provides a bridge between different protocols or networks.
//Used for enabling communication between clients and servers using different communication protocols.

// Forward Proxy:

// Subject interface
class Internet {
public:
    virtual void connectTo(const std::string& serverHost) = 0;
};

// RealInternet class
class RealInternet : public Internet {
public:
    void connectTo(const std::string& serverHost) override {
        std::cout << "Connecting to " << serverHost << std::endl;
    }
};

// ProxyInternet class
class ProxyInternet : public Internet {
private:
    RealInternet* realInternet;

public:
    ProxyInternet() : realInternet(nullptr) {}

    void connectTo(const std::string& serverHost) override {
        if (realInternet == nullptr)
        {
            realInternet = new RealInternet();
        }
        std::cout << "Proxy: Performing additional checks before connecting." << std::endl;
        realInternet->connectTo(serverHost);
    }
};

//int main() {
//    // Using RealInternet directly
//    RealInternet* realInternet = new RealInternet();
//    realInternet->connectTo("www.example.com");
//
//    // Using ProxyInternet to control access
//    ProxyInternet* proxyInternet = new ProxyInternet();
//    proxyInternet->connectTo("www.example.com");
//
//    delete realInternet;
//    delete proxyInternet;
//
//    return 0;
//}

#endif /* Proxy_h */
