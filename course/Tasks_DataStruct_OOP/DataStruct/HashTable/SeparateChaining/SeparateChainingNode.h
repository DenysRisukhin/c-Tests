//
//  hash_table.h
//  Test2019
//
//  Created by Denys Risukhin on 7/24/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef hash_table_h
#define hash_table_h

template <class T>
class HashNode
{
public:
    T m_drink;
    T m_name;
    HashNode<T>* m_next = nullptr; // This makes it a linked list node
};

template <typename T>
class hash_table
{
public:
    hash_table();
    ~hash_table();
    
    void addItem(const T& name, const T& drink);
    void search(const T&);
    void deleteNode(const T&);
    
    int getNumberOfItemsInIndex(const int idx);
    
    void printTable();
    void printItemsInIndex(const int index);
    
private:
    int hashFunction(const T& key);
    
private:
    static int const m_tableSize = 4;
    HashNode<T>* m_hashTable[m_tableSize]; // Array of pointers to HashNode
};

template<typename T>
hash_table<T>::~hash_table()
{
    for (int i = 0; i < m_tableSize; i++)
    {
        HashNode<T>* current = m_hashTable[i];
        while (current != nullptr)
        {
            HashNode<T>* next = current->m_next;
            delete current;
            current = next;
        }
    }
}

template<typename T>
int hash_table<T>::hashFunction(const T& key)
{
    int hash = 0;
    int idx = 0;
    
    for (int i = 0; i < key.length(); i++)
    {
        hash = (hash + (int)key[i]) * 17;
    }
    
    idx = hash % m_tableSize;
    return idx;
}

template <typename T>
hash_table<T>::hash_table()
{
    for (int i = 0; i < m_tableSize; i++)
    {
        m_hashTable[i] = new HashNode<T>;
        m_hashTable[i]->m_name = "empty";
        m_hashTable[i]->m_drink = "empty";
        m_hashTable[i]->m_next = nullptr;
    }
}

template<typename T>
void hash_table<T>::addItem(const T& name, const T& drink)
{
    int idx = hashFunction(name);
    
    if (m_hashTable[idx]->m_name == "empty")
    {
        m_hashTable[idx]->m_name = name;
        m_hashTable[idx]->m_drink = drink;
    }
    else
    {
        HashNode<T>* curNode = m_hashTable[idx];
        
        HashNode<T>* newNode = new HashNode<T>;
        newNode->m_name = name;
        newNode->m_drink = drink;
        newNode->m_next = nullptr;
        
        while (curNode->m_next != nullptr)
        {
            curNode = curNode->m_next;
        }
            
        curNode->next = newNode;
    }
}

template<typename T>
int hash_table<T>::getNumberOfItemsInIndex(const int idx)
{
    int counter = 0;
    
    if (m_hashTable[idx]->m_name == "empty")
    {
        return 0;
    }
    else
    {
        counter++;
        HashNode<T>* newNode = m_hashTable[idx];
        
        while (newNode->m_next != nullptr)
        {
            counter++;
            newNode = newNode->m_next;
        }
    }
    
    return counter;
}

template<typename T>
void hash_table<T>::search(const T& name)
{
    int idx = hashFunction(name);
    bool foundName = false;
    std::string drink;
    
    HashNode<T>* ptr = m_hashTable[idx];
    while (ptr != nullptr)
    {
        if (ptr->m_name == name)
        {
            foundName = true;
            drink = ptr->m_drink;
        }
        
        ptr = ptr->m_next;
    }
    
    if (foundName == true)
    {
        cout << "favorite drink is " << drink << endl;
    }
    else
    {
        cout << "not found";
    }
}

template<typename T>
void hash_table<T>::deleteNode(const T& name)
{
    int index = hashFunction(name);
    HashNode<T>* delPtr;
    HashNode<T>* p1;
    HashNode<T>* p2;

    // case 0 - bucket is empty
    if (m_hashTable[index]->m_name == "empty" && m_hashTable[index]->m_drink == "empty")
    {
        std::cout << name << "was not found in the Hash Table";
    }
    // case 1 - only 1 item contained in bucket and that iteam has matching the name
    else if (m_hashTable[index]->m_name == name && m_hashTable[index]->m_next == nullptr)
    {
        m_hashTable[index]->m_name = "empty";
        m_hashTable[index]->m_drink = "drink";
        cout << name << " was removed from the Hash Table\n";
    }
    // case 2 - match locates in the first item in the bucket but there are more iteam in the bucket
    else if (m_hashTable[index]->m_name == name)
    {
        delPtr = m_hashTable[index];
        m_hashTable[index] = m_hashTable[index]->m_next;
        delete delPtr;
        
        cout << name << " was removed from the Hash Table\n";
    }
    // case 3 - bucket contains iteam but first iteam is not a match
    else
    {
        p1 = m_hashTable[index]->m_next;
        p2 = m_hashTable[index];
        
        while (p1 != nullptr && p1->m_name != name)
        {
            p2 = p1;
            p1 = p1->m_next;
        }

        // case - not match
        if (p1 == nullptr)
        {
            cout << name << " was not found in the Hash Table\n";
        }
        // case - match is found
        else
        {
            delPtr = p1;
            p1 = p1->m_next;
            p2->m_next = p1;

            delete delPtr;

            cout << name << " was removed from the Hash Table\n";
        }
    }
}

template<typename T>
void hash_table<T>::printTable()
{
    int number;
    for (int i = 0; i < m_tableSize; i++)
    {
        number = getNumberOfItemsInIndex(i);
        cout << "------------------\n" << endl;
        cout << m_hashTable[i]->name << endl;
        cout << m_hashTable[i]->drink << endl;
        cout << "# of items = " << number << endl;
    }
}

template<typename T>
void hash_table<T>::printItemsInIndex(const int index)
{
    HashNode<T>* ptr = m_hashTable[index];
    
    if (ptr->m_name == "empty")
    {
        cout << "index = " << index << " is empty";
    }
    else
    {
        while(ptr != nullptr)
        {
            cout << "------------------\n" << endl;
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "------------------\n" << endl;
            ptr = ptr->m_next;
        }
    }
}

#endif /* hash_table_h */
