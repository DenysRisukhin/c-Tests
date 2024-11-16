//
//  Stack.h
//  Test2019
//
//  Created by Denys Risukhin on 7/22/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <cstdio>
#include <cstdlib>
#include <exception>
#include <memory>
#include <iostream>

//*******
//*Stack*
//*******
//std:: cout << "\n\n*Stack*\n";
//Stack<int> stackTest;
//stackTest.push(1 + 3);
//int i1 = 3;
//stackTest.push(i1);
//std::cout << stackTest.top() << std::endl;

template <typename T>
class Stack
{
public:
    Stack() : m_size(0), m_head(new Node()), m_tail(new Node())
    {
        m_head->m_before = nullptr;
        m_tail->m_after = nullptr;
        m_head->m_after = m_tail;
        m_tail->m_before = m_head;
    }

    ~Stack()
    {
        Node* ptr = m_tail;
        while(ptr != m_head)
        {
            ptr = ptr->m_before;
            delete ptr->m_after;
        }
        delete ptr;
    }

    void clear()
    {
        Node *node = m_tail->before;
        m_head->m_after = m_tail;
        m_tail->m_before = m_head;
        
        while(node->m_before != m_head)
        {
            node = node->m_before;
            delete node->m_after;
        }
        delete node;
        m_size = 0;
    }

    constexpr bool empty() { return m_size == 0; }

    void push(T const &element)
    {
        auto node = new Node();
        node->m_data = element;
        node->m_before = m_tail->m_before;
        node->m_before->m_after = node;
        node->m_after = m_tail;
        
        m_tail->m_before = node;
        ++m_size;
    }
    void push(T &&element) noexcept
    {
        auto node = new Node();
        node->m_data = std::move(element);
        node->m_before = m_tail->m_before;
        node->m_before->m_after = node;
        node->m_after = m_tail;
        m_tail->m_before = node;
        ++m_size;
    }
    
    void pop()
    {
        if (empty())
            throw std::runtime_error("Empty stack!");

        Node *node = m_tail->m_before;
        m_tail->m_before = node->m_before;
        m_tail->before->m_after = m_tail;

        delete node;
        --m_size;
    }
    
    constexpr std::size_t size() const
    {
        return m_size;
    }
    
    void swap(Stack &stack)
    {
        std::swap(this->head, stack.head);
        std::swap(this->tail, stack.tail);
        std::swap(this->_size, stack._size);
    }
    
    T const &top() const
    {
        return m_tail->m_before->m_data;
    }
    
    T top()
    {
        return m_tail->m_before->m_data;
    }
    
private:
    struct Node
    {
        T m_data;
        Node* m_before;
        Node* m_after;
    };
    
    std::size_t m_size;
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
};


#endif /* Stack_h */
