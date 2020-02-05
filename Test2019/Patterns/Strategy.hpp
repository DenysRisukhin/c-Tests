//
//  Strategy.hpp
//  Test2019
//
//  Created by Denys Risukhin on 8/13/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Strategy_hpp
#define Strategy_hpp

#include <stdio.h>
#include <iostream>

#pragma mark - tests (inharitance version)

#pragma mark - step 3

class Compression {
public:
    virtual void compress(const std::string& file) = 0;
    virtual ~Compression() {}
};

#pragma mark - step 4

class ZipCompression: public Compression {
public:
    void compress(const std::string& file) override {}
};

class RarCompression: public Compression {
public:
    void compress(const std::string& file) override {}
};

#pragma mark - step 2

class Compressor {
public:
    Compressor(Compression* ptr): m_ptr(ptr) {}
    
    ~Compressor() { delete m_ptr; }
    
    void compress(const std::string& file) {
        m_ptr->compress(file);
    }

private:
    Compression* m_ptr = nullptr;
};

#pragma mark - step 1 tests

//Compressor zip(new ZipCompression());
//zip.compress("filename");
//
//Compressor rar(new RarCompression());
//rar.compress("filename");

#endif /* Strategy_hpp */
