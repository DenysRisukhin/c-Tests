//
//  OOP_2.h
//  Test2019
//
//  Created by Denys Risukhin on 2/17/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef OOP_2_h
#define OOP_2_h

#include "iostream"
#include <map>
#include <exception>

#pragma mark - Buffer

class Buffer {
public:
    // c-tor
    explicit Buffer(const std::string& buff) noexcept: m_buff(nullptr), m_buffSize(buff.length()) {
        m_buff = new char[m_buffSize];
        memcpy(m_buff, buff.c_str(), m_buffSize);
        std::cout << "c-tor\n";
    }
    
    // copy c-tor
    Buffer(const Buffer& obj) noexcept: m_buff(nullptr), m_buffSize(obj.m_buffSize) {
        m_buff = new char[m_buffSize];
        memcpy(m_buff, obj.m_buff, m_buffSize);
        std::cout << "copy c-tor\n";
    }
    
    // moving c-tor
    Buffer(Buffer&& obj) noexcept: m_buff(obj.m_buff), m_buffSize(obj.m_buffSize) {
        obj.m_buff = nullptr;
        std::cout << "moving c-tor\n";
    }
    
    ~Buffer() noexcept { destroy(); }
    
    Buffer& operator=(const Buffer& obj) noexcept {
        std::cout << "operator= \n";
        if (obj.m_buff == m_buff) {
            return *this;
        }
        
        destroy();
        m_buffSize = obj.m_buffSize;
        m_buff = new char[m_buffSize];
        memcpy(m_buff, obj.m_buff, m_buffSize);
        
        return *this;
    }
    
    Buffer& operator=(Buffer&& obj) noexcept {
        std::cout << "moving operator= \n";
        if (obj.m_buff == m_buff) {
            return *this;
        }
        
        destroy();
        m_buffSize = obj.m_buffSize;
        m_buff = obj.m_buff;
        
        obj.m_buff = nullptr;
    }
    
private:
    char* m_buff = nullptr;
    size_t m_buffSize;
    
    void destroy() noexcept {
        if (m_buff) {
            delete[] m_buff;
            m_buff = nullptr;
        }
    }
};

Buffer createBuff(const std::string& buff) {
    Buffer retBuff("123");
    return std::move(retBuff);
}


//test

//QCoreApplication a(argc, argv);
//
//Buffer buff1 = createBuff("123");
//Buffer buff2 = buff1;
//
//buff2 = createBuff("123");
//buff2 = buff1;
//
//auto buff3 = createBuff("123");
//
//return a.exec();



#endif /* OOP_2_h */
