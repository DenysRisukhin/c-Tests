//
//  Queue.h
//  Test2019
//
//  Created by Denys Risukhin on 7/17/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <cstdio>
#include <cstdlib>
#include <exception>
#include <memory>
#include <iostream>

#include <vector>
#include <queue>
#include <stack>

//*******
//*Queue*
//*******
//std:: cout << "\n\n*Queue*\n";
//Queue<int> queueTest;
//queueTest.push(3);
//std::cout << queueTest.front() << std::endl;
//
//int i = 2;
//queueTest.push(i);
//queueTest.pop();
//std::cout << queueTest.front() << std::endl;
//
//queueTest.clear();
//
//// std::cout << queueTest.front() << std::endl; // err
//
//std::cout << queueTest.size();

template<class T>
class Queue {
public:
    Queue(): m_head(new Node()), m_tail(new Node())
    {
        m_tail->m_next = m_head;
    }
    
    Queue(const Queue<T>& queue) noexcept
    {
        m_head = queue.m_head;
        m_tail = queue.m_tail;
        m_size = queue.m_size;
    }
    
    Queue(Queue<T>&& queue) noexcept
    {
        m_head = queue.m_head;
        m_tail = queue.m_tail;
        m_size = queue.m_size;
        
        queue.m_head = nullptr;
        queue.m_tail = nullptr;
    }
    
    ~Queue()
    {
        clear();
        delete m_head;
        delete m_tail;
    }
    
    void push(const T& data) noexcept
    {
        auto node = new Node();
        node->m_data = data;
        node->m_next = nullptr;
        
        m_tail->m_next->m_next = node;
        m_tail->m_next = node;
    }
    
    void push(const T&& data) noexcept
    {
        auto node = new Node();
        node->m_data = std::move(data);
        node->m_next = nullptr;
        
        m_tail->m_next->m_next = node;
        m_tail->m_next = node;
    }
    
    void pop() 
    {
        if (isEmpty()) {
            std::runtime_error("Empty queue");
        }
        auto curNode = m_head;
        m_head = m_head->m_next;
        delete curNode;
    }
    
    T const & front() const noexcept { return m_head->m_next->m_data; }
    T front() noexcept { return m_head->m_next->m_data; }
    
    T const & back() const noexcept { return m_tail->m_next->m_data; }
    T back() noexcept { return m_tail->m_next->m_data; }
    
    void swap(Queue& queue) noexcept
    {
        std::swap(m_head, queue.m_head);
        std::swap(m_tail, queue.m_tail);
        std::swap(m_size, queue.m_size);

    }
    
    constexpr std::size_t size() const noexcept { return m_size; }
    
    void clear() noexcept
    {
        while (m_tail->m_next != m_head)
        {
            auto temp = m_head;
            m_head = m_head->m_next;
            delete temp;
        }
        m_size = 0;
    }
    
    constexpr bool isEmpty() noexcept { return m_head == nullptr; }
    
private:
    struct Node {
        T m_data;
        Node* m_next = nullptr;
    };
    
    std::size_t m_size;
    
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
};
#endif /* Queue_h */
