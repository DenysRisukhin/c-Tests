//
//  double_list.h
//  Test2019
//
//  Created by Denys Risukhin on 7/24/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef double_list_h
#define double_list_h

template<typename T>
struct DoubleNode
{
    DoubleNode(const T& data) noexcept
        : m_data(data), m_next(nullptr), m_prev(nullptr) {}
    
    int m_data;
    DoubleNode* m_next = nullptr;
    DoubleNode* m_prev = nullptr;
};

template<typename T>
class double_list
{
public:
    double_list() noexcept { m_head = nullptr; }
    
    double_list(const double_list<T>& ref) noexcept
    {
        if (!ref.m_head)
        {
            m_head = nullptr;
        }
        else
        {
            copy(m_head, ref.m_head);
        }
    }
    
    double_list(double_list<T>&& ref) noexcept
    {
        if (!ref.m_head)
        {
            m_head = nullptr;
        }
        else
        {
            copy(m_head, ref.m_head);
        }
        
        // is this correct?
        ref.m_head = nullptr;
    }
    
    ~double_list() noexcept
    {
        if (isEmpty())
        {
            return;
        }
        
        DoubleNode<T>* curNodePtr = m_head;
        DoubleNode<T>* tempNodePtr = nullptr;
        
        while (curNodePtr)
        {
            tempNodePtr = curNodePtr;
            curNodePtr = curNodePtr->m_next;
            delete tempNodePtr;
        }
    }
    
    const double_list<T>& operator=(const double_list<T>& ref) noexcept
    {
        if (*this == ref)
        {
            return;
        }
        
        if (ref.isEmpty())
        {
            m_head = nullptr;
        }
        else
        {
            copy(m_head, ref.m_head);
        }
        
        return *this;
    }
    
    const double_list<T>& operator=(double_list<T>&& ref) noexcept
    {
        if (*this == ref)
        {
            return;
        }
        
        if (ref.isEmpty())
        {
            m_head = nullptr;
        }
        else
        {
            copy(m_head, ref.m_head);
        }
        
        // is this correct?
        ref.m_head = nullptr;
        
        return *this;
    }
    
    const bool operator==(const double_list<T>& ref) noexcept
    {
        return isCompared(m_head, ref.m_head);
    }
    
    bool isEmpty() const noexcept { return m_head == nullptr; }
    
    void pushFront(const T& data) noexcept
    {
        DoubleNode<T>* newNodePtr = getNewNode(data);
        
        if (isEmpty())
        {
            m_head = newNodePtr;
            return;
        }
        
        newNodePtr->m_next = m_head;
        m_head->m_prev = newNodePtr;
        m_head = newNodePtr;
    }
    
    void pushBack(const T& data) noexcept
    {
        DoubleNode<T>* newNodePtr = getNewNode(data);
        DoubleNode<T>* curNodePtr = m_head;
        
        if (isEmpty())
        {
            m_head = newNodePtr;
            return;
        }
        
        while (curNodePtr->m_next)
        {
            curNodePtr = curNodePtr->m_next;
        }
        
        newNodePtr->m_prev = curNodePtr;
        curNodePtr->m_next = newNodePtr;
    }
    
    void remove(const T& data) noexcept
    {
        if (isEmpty())
        {
            return;
        }
        
        DoubleNode<T>* curNodePtr = m_head;
        
        while (curNodePtr)
        {
            if (curNodePtr->m_data == data)
            {
                if (curNodePtr == m_head)
                {
                    m_head = m_head->m_next;
                    m_head->m_prev = nullptr;
                }
                else
                {
                    // if last node
                    if (curNodePtr->m_next == nullptr)
                    {
                        curNodePtr->m_prev->m_next = nullptr;
                    }
                    else // is anything between?
                    {
                        curNodePtr->m_prev->m_next = curNodePtr->m_next;
                        curNodePtr->m_next->m_prev = curNodePtr->m_prev;
                    }
                }
                delete curNodePtr;
                return;
            }
            curNodePtr = curNodePtr->m_next;
        }
    }
    
    bool search(const T& data) const noexcept
    {
        if (isEmpty())
        {
            return false;
        }
        
        DoubleNode<T>* curNodePtr = m_head;
        
        while (curNodePtr)
        {
            if (curNodePtr->m_data == data)
            {
                return true;
            }
            
            curNodePtr = curNodePtr->m_next;
        }
        
        return false;
    }
    
    void reversePrint() const noexcept
    {
        if (isEmpty())
        {
            return;
        }
        
        DoubleNode<T>* curNodePtr = m_head;
        
        while (curNodePtr->m_next)
        {
            curNodePtr = curNodePtr->m_next;
        }
        
        while (curNodePtr)
        {
            curNodePtr = curNodePtr->m_prev;
        }
    }
    
    void print() const noexcept
    {
        if (isEmpty())
        {
            return;
        }
        
        DoubleNode<T>* curNodePtr = m_head;
        
        while (curNodePtr)
        {
            cout << curNodePtr->m_data << ' ';
            curNodePtr = curNodePtr->m_next;
        }
        
        cout << endl;
    }
    
private:
    DoubleNode<T>* m_head = nullptr;
    
private:
    
    DoubleNode<T>* getNewNode(const T data)
    {
        DoubleNode<T>* newNode = new DoubleNode<T>(data);
        assert(newNode);
        return newNode;
    }
    
    void copy(const DoubleNode<T>*& nodeA, const DoubleNode<T>* nodeB) noexcept
    {
        if (!nodeB)
        {
            return;
        }
        
        nodeA = getNewNode(1);
        nodeA->m_data = nodeB->m_data;
        nodeA->m_next = nullptr;
        copy(nodeA->m_next, nodeB->m_next);
    }
    
    bool isCompared(const DoubleNode<T>* curList, const DoubleNode<T>* secondList) noexcept
    {
        bool compared = false;
        
        if (!curList && !secondList)
        {
            compared = true;
        }
        else
        {
            if (!curList || !secondList)
            {
                compared = false;
            }
            else if (curList->m_data != secondList->m_data)
            {
                compared = false;
            }
            else
            {
                isCompared(curList->m_next, secondList->m_next);
            }
        }
        
        return compared;
    }
};

//test

//double_list<int> list;
//list.pushBack(5);
//list.pushBack(6);
//list.pushBack(8);
//
//list.pushFront(3);
//list.pushFront(1);
//list.pushFront(99);
//
//list.print();

#endif /* double_list_h */
