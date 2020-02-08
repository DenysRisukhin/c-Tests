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
    DoubleNode(const T& data)
        : m_data(data), m_next(nullptr), m_prev(nullptr) {}
    
    int m_data;
    DoubleNode* m_next = nullptr;
    DoubleNode* m_prev = nullptr;
};

template<typename T>
class double_list
{
public:
    double_list() { m_head = nullptr; }
    
    double_list(const double_list<T>& list) {}
    
    double_list(double_list<T>&& list) {}
    
    ~double_list() {}
    
    const double_list<T>& operator=(const double_list<T> list) {}
    
    const bool operator==(const double_list<T> list) {}
    
    bool isEmpty() const { return m_head == nullptr; }
    
    void pushFront(const T& data)
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
    
    void pushBack(const T& data)
    {
        DoubleNode<T>* newNodePtr = getNewNode(data);
        DoubleNode<T>* curNodePtr = m_head;
        
        if (isEmpty())
        {
            m_head = newNodePtr;
            return;
        }
        
        while (curNodePtr)
        {
            curNodePtr = curNodePtr->m_next;
        }
        
        curNodePtr->m_next = newNodePtr;
        newNodePtr->m_prev = curNodePtr;
        m_head = newNodePtr;
    }
    
    void remove(const T& data)
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
    
    bool search(const T& data) const
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
    
    void reversePrint() const
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
    
    void print() const
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
    
    void copy(const DoubleNode<T>*& nodeA, const DoubleNode<T>* nodeB)
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
    
    bool isSame(const DoubleNode<T>* curList, const DoubleNode<T>* secondList)
    {
        bool isSame = false;
        
        if (!curList && !secondList)
        {
            isSame = true;
        }
        else
        {
            if (!curList || !secondList)
            {
                isSame = false;
            }
            else if (curList->m_data != secondList->m_data)
            {
                isSame = false;
            }
            else
            {
                isSame(curList->m_next, secondList->m_next);
            }
        }
        
        return isSame;
    }
};

#endif /* double_list_h */
