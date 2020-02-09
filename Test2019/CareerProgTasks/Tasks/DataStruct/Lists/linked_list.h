//
//  linked_list.h
//  Test2019
//
//  Created by Denys Risukhin on 7/24/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

template<typename T>
struct LinkedNode
{
    LinkedNode(const T& data) noexcept
        : m_data(data), m_next(nullptr) {}
    
    T m_data;
    LinkedNode* m_next = nullptr;
};

template<class T>
class linked_list
{
public:
    linked_list() noexcept { m_first = m_last = nullptr; }
    
    linked_list(const linked_list<T>& ref) noexcept
    {
        if (!ref.m_first)
        {
            m_first = m_last = nullptr;
        }
        else
        {
            copy(m_first, ref.m_first);
        }
    }
    
    linked_list(linked_list<T>&& ref) noexcept
    {
        if (!ref.m_first)
        {
            m_first = m_last = nullptr;
        }
        else
        {
            copy(m_first, ref.m_first);
        }
        
        // is this correct?
        ref.m_first = nullptr;
        ref.m_last = nullptr;
    }
    
    ~linked_list()
    {
        if (isEmpty())
        {
            return;
        }
        
        LinkedNode<T>* currentNodePtr = m_first;
        LinkedNode<T>* tempNodePtr = nullptr;
        
        while (currentNodePtr)
        {
            tempNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->m_next;
            delete tempNodePtr;
        }
    }
    
    const linked_list<T>& operator=(const linked_list<T>& ref) noexcept
    {
        if (*this == ref)
        {
            return;
        }
        
        if (ref.isEmpty())
        {
            m_first = nullptr;
        }
        else
        {
            copy(m_first, ref.m_first);
        }
        
        return *this;
    }
    
    const linked_list<T>& operator=(linked_list<T>&& ref) noexcept
    {
        if (*this == ref)
        {
            return;
        }
        
        if (ref.isEmpty())
        {
            m_first = nullptr;
        }
        else
        {
            copy(m_first, ref.m_first);
        }
        
        // is this correct?
        ref.m_first = nullptr;
        ref.m_last = nullptr;
        
        return *this;
    }
    
    bool operator==(const linked_list<T>& ref) noexcept
    {
        return isCompared(m_first, ref.m_first);
    }
    
    friend std::ostream& operator<<(std::ostream& output, const linked_list<T>& ref);
    
    void pushFront(const T& data) noexcept
    {
        LinkedNode<T>* newNodePtr = getNewNode(data);
        
        if (isEmpty())
        {
            m_first = m_last = newNodePtr;
            return;
        }
        
        newNodePtr->m_next = m_first;
        m_first = newNodePtr;
    }
    
    void pushBack(const T& data) noexcept
    {
        LinkedNode<T>* newNodePtr = getNewNode(data);
        
        if (isEmpty())
        {
            m_first = m_last = newNodePtr;
            return;
        }
        
        m_last->m_next = newNodePtr;
        m_last = newNodePtr;
    }
    
    void popFront() noexcept
    {
        if (isEmpty())
        {
            return;
        }
        
        if (m_first == m_last)
        {
            m_first = m_last = nullptr;
            return;
        }
        
        LinkedNode<T>* tempNodePtr = m_first;
        m_first = m_first->m_next;
        delete tempNodePtr;
    }
    
    void popBack() noexcept
    {
        if (isEmpty())
        {
            return;
        }
        
        if (m_first == m_last)
        {
            m_first = m_last = nullptr;
            return;
        }
        
        LinkedNode<T>* curNodePtr = m_first;
        LinkedNode<T>* tempNodePtr = m_last;
        
        while (curNodePtr != m_last)
        {
            curNodePtr = curNodePtr->m_next;
        }
        
        m_last = curNodePtr;
        delete tempNodePtr;
    }
    
    bool search(const T& data) const noexcept
    {
        if (isEmpty())
        {
            return false;
        }
        
        LinkedNode<T>* curNodePtr = m_first;
        
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
    
    void insert(const T& data) noexcept
    {
        LinkedNode<T>* newNodePtr = getNewNode(data);
        
        if (isEmpty())
        {
            m_first = m_last = newNodePtr;
            return;
        }
        
        if (newNodePtr->m_data < m_first->m_data)
        {
            newNodePtr->m_next = m_first;
            m_first = newNodePtr;
            return;
        }
        
        LinkedNode<T>* tempNodePtr = m_first;
        LinkedNode<T>* tempNextNodePtr = tempNodePtr->m_next;
        
        while (tempNextNodePtr)
        {
            if (tempNodePtr->m_data < newNodePtr->m_data && newNodePtr->m_data <= tempNextNodePtr->m_data)
            {
                tempNodePtr->m_next = newNodePtr;
                newNodePtr->m_next = tempNextNodePtr;
                return;
            }
            
            tempNodePtr = tempNextNodePtr;
            tempNextNodePtr = tempNextNodePtr->m_next;
        }
        
        m_last->m_next = newNodePtr;
        m_last = newNodePtr;
    }
    
    void remove(const T& data) noexcept
    {
        if (isEmpty())
        {
            return;
        }
        
        LinkedNode<T>* tempNodePtr = m_first;
        LinkedNode<T>* tempNextNodePtr = tempNodePtr->m_next;
        
        if (tempNodePtr->m_data == data)
        {
            m_first = tempNodePtr->m_next;
            delete tempNodePtr;
            return;
        }
        
        while (tempNextNodePtr)
        {
            if (tempNextNodePtr->m_data == data)
            {
                tempNodePtr->m_next = tempNextNodePtr->m_next;
                delete tempNextNodePtr;
                return;
            }
            tempNodePtr = tempNextNodePtr;
            tempNextNodePtr = tempNextNodePtr->m_next;
        }
    }
    
    bool isEmpty() const noexcept { return m_first == nullptr; }
    
    void reverse()
    {
        LinkedNode<T>* parentNodePtr = m_first;
        LinkedNode<T>* meNodePtr = parentNodePtr->m_next;
        LinkedNode<T>* childNodePtr = meNodePtr->m_next;
        
        parentNodePtr->m_next = nullptr;
        
        while (childNodePtr)
        {
            meNodePtr->m_next = parentNodePtr;
            parentNodePtr = meNodePtr;
            meNodePtr = childNodePtr;
            childNodePtr = childNodePtr->m_next;
        }
        
        meNodePtr->m_next = parentNodePtr;
        m_first = meNodePtr;
    }
    
    void print() const noexcept
    {
        if (isEmpty())
        {
            return;
        }
        
        LinkedNode<T>* curNodePtr = m_first;
        
        while (curNodePtr)
        {
            cout << curNodePtr->m_data << ' ';
            curNodePtr = curNodePtr->m_next;
        }
        
        cout << endl;
    }
    
private:
    LinkedNode<T>* m_first = nullptr;
    LinkedNode<T>* m_last = nullptr;
    
private:
    
    LinkedNode<T>* getNewNode(const T data)
    {
        LinkedNode<T>* newNode = new LinkedNode<T>(data);
        assert(newNode);
        return newNode;
    }
    
    void copy(const LinkedNode<T>*& nodeA, const LinkedNode<T>* nodeB) noexcept
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
    
    bool isCompared(const LinkedNode<T>* curList, const LinkedNode<T>* secondList) noexcept
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

template<typename T>
std::ostream& operator<<(std::ostream& output, const linked_list<T>& ref)
{
    if (ref.isEmpty())
    {
        output << "empty list" << endl;
    }
    
    LinkedNode<T>* curNodePtr = nullptr;
    for (curNodePtr = ref.m_first; curNodePtr != ref.m_last; curNodePtr = curNodePtr->m_next)
    {
        output << curNodePtr->m_data << ' ';
    }
    
    return output;
}

//tests

//linked_list<int> list;
//list.insert(5);
//list.insert(6);
//list.insert(8);
//
//list.print();

#endif /* linked_list_h */
