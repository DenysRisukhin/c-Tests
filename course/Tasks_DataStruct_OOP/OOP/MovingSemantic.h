//
//  MovingSemantic.h
//  Test2019
//
//  Created by Risukhin Denys on 1/29/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MovingSemantic_h
#define MovingSemantic_hc If you want to handle the case where the allocation fails without using exceptions, you can use nothrow.

class Buffer
{
public:
    Buffer() noexcept: m_buff(nullptr), m_buffSize(0) {}
    
    Buffer(const string& buff): m_buff(nullptr), m_buffSize(buff.length()) {
        m_buff = new char[m_buffSize];
        memcpy(m_buff, buff.c_str(), m_buffSize);
        cout << "c-tor" << endl;
    }
    
    ~Buffer() { destroy(); }
    
    Buffer(const Buffer& buffer) {
        cout << "copy_c-tor" << endl;

        if (this != &buffer)
        {
            m_buff = new (nothrow) char[m_buffSize];


//            If the memory allocation is successful, new returns a pointer to the allocated memory as usual.
//            If the memory allocation fails, instead of throwing an exception, new returns a nullptr.
//            Using nothrow allows you to check the result of the memory allocation directly:
            
            if (m_buff)
            {
                memcpy(m_buff, buffer.m_buff, m_buffSize);
            }
            else
            {
                // Handle memory allocation failure
                cerr << "Memory allocation failed in copy constructor." << endl;
                // Potentially throw an exception or handle it in an appropriate way
            }
        }
    }
    
    Buffer(Buffer&& buffer) noexcept :
        m_buff(buffer.m_buff),
        m_buffSize(std::move(buffer.m_buffSize)) {
        cout << "moving_c-tor" << endl;
        
        buffer.m_buff = nullptr;
        buffer.m_buffSize = 0;
    }

    Buffer& operator=(const Buffer& buffer) {
        cout << "operator=" << endl;

        if (this != &buffer)
        {
            destroy();
            
            m_buffSize = buffer.m_buffSize;
            m_buff = new char[m_buffSize];
            memcpy(m_buff, buffer.m_buff, m_buffSize);
        }
        
        return *this;
    }

    Buffer& operator=(Buffer&& buffer) {
        cout << "moving_operator=" << endl;
        
        if (this != &buffer)
        {
            destroy();
            
            m_buffSize = std::move(buffer.m_buffSize);
            m_buff = std::move(buffer.m_buff);
            
            buffer.m_buff = nullptr;
            buffer.m_buffSize = 0;
        }
        
        return *this;
    }

private:
    void destroy() {
        delete [] m_buff;
        m_buff = nullptr;
    }

private:
    char* m_buff;
    int m_buffSize;
};

Buffer createBuffer(const string& data)
{
    Buffer buf(data);
    
//  the compiler will automatically apply move semantics where appropriate without explicit use of std::move,
//  so you often don't need to use it explicitly unless you have specific reasons to do so.
    return std::move(buf); // Explicitly using std::move
}

// Test
//Buffer bufFirst = createBuffer("123");
//Buffer bufSecond = bufFirst;
//
//bufSecond = createBuffer("123");
//bufSecond = bufFirst;
//
//auto bufThird = createBuffer("123");
//
//// Create another Buffer using move constructor
//Buffer bufFive = std::move(bufFirst);

#endif /* MovingSemantic_h */
