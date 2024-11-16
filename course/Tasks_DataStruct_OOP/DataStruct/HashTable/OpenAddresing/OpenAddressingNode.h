//
//  Header.h
//  Test2019
//
//  Created by Risukhin Denys on 6/18/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Header_h
#define Header_h
//
//To implement a hash table with open addressing, we'll use linear probing to resolve collisions. This means that when a collision occurs, we'll look for the next available slot in the array. Here's the modified version of your hash table class using open addressing:

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class HashNode
{
public:
    T m_name;
    T m_drink;
    bool m_isOccupied = false; // To check if a slot is occupied
    bool m_isDeleted = false;  // To handle deletion
};

template <typename T>
class hash_table
{
public:
    hash_table();
    ~hash_table();
    
    void addItem(const T& name, const T& drink);
    void search(const T& name) const;
    void deleteNode(const T& name);
    
    void printTable() const;
    
private:
    int hashFunction(const T& key) const;
    int findSlot(const T& key) const; // Find slot for key

private:
    static const int m_tableSize = 4;
    HashNode<T>* m_hashTable[m_tableSize];
};

template <typename T>
hash_table<T>::hash_table()
{
    for (int i = 0; i < m_tableSize; i++)
    {
        m_hashTable[i] = new HashNode<T>;
    }
}

template <typename T>
hash_table<T>::~hash_table()
{
    for (int i = 0; i < m_tableSize; i++)
    {
        delete m_hashTable[i];
    }
}

template <typename T>
int hash_table<T>::hashFunction(const T& key) const
{
    int hash = 0;
    for (size_t i = 0; i < key.length(); i++)
    {
        hash = (hash + static_cast<int>(key[i])) * 17;
    }
    return hash % m_tableSize;
}

template <typename T>
int hash_table<T>::findSlot(const T& key) const
{
    int idx = hashFunction(key);
    int originalIdx = idx;
    bool firstRun = true;

    while (m_hashTable[idx]->m_isOccupied && !m_hashTable[idx]->m_isDeleted && m_hashTable[idx]->m_name != key)
    {
        idx = (idx + 1) % m_tableSize;
        if (idx == originalIdx && !firstRun)
        {
            return -1; // Table is full
        }
        firstRun = false;
    }
    return idx;
}

template <typename T>
void hash_table<T>::addItem(const T& name, const T& drink)
{
    int idx = findSlot(name);
    if (idx == -1)
    {
        std::cout << "Hash table is full. Cannot add more items." << std::endl;
        return;
    }

    m_hashTable[idx]->m_name = name;
    m_hashTable[idx]->m_drink = drink;
    m_hashTable[idx]->m_isOccupied = true;
    m_hashTable[idx]->m_isDeleted = false;
}

template <typename T>
void hash_table<T>::search(const T& name) const
{
    int idx = hashFunction(name);
    int originalIdx = idx;
    bool foundName = false;
    T drink;

    while (m_hashTable[idx]->m_isOccupied)
    {
        if (!m_hashTable[idx]->m_isDeleted && m_hashTable[idx]->m_name == name)
        {
            foundName = true;
            drink = m_hashTable[idx]->m_drink;
            break;
        }
        idx = (idx + 1) % m_tableSize;
        if (idx == originalIdx)
        {
            break;
        }
    }
    
    if (foundName)
    {
        std::cout << name << "'s favorite drink is " << drink << std::endl;
    }
    else
    {
        std::cout << name << " not found" << std::endl;
    }
}

template <typename T>
void hash_table<T>::deleteNode(const T& name)
{
    int idx = hashFunction(name);
    int originalIdx = idx;

    while (m_hashTable[idx]->m_isOccupied)
    {
        if (!m_hashTable[idx]->m_isDeleted && m_hashTable[idx]->m_name == name)
        {
            m_hashTable[idx]->m_isDeleted = true;
            std::cout << name << " was removed from the Hash Table" << std::endl;
            return;
        }
        idx = (idx + 1) % m_tableSize;
        if (idx == originalIdx)
        {
            break;
        }
    }
    std::cout << name << " was not found in the Hash Table" << std::endl;
}

template <typename T>
void hash_table<T>::printTable() const
{
    for (int i = 0; i < m_tableSize; i++)
    {
        std::cout << "------------------\n";
        if (m_hashTable[i]->m_isOccupied && !m_hashTable[i]->m_isDeleted)
        {
            std::cout << "Index " << i << " contains:\n";
            std::cout << "Name: " << m_hashTable[i]->m_name << "\n";
            std::cout << "Drink: " << m_hashTable[i]->m_drink << "\n";
        }
        else
        {
            std::cout << "Index " << i << " is empty\n";
        }
        std::cout << "------------------\n";
    }
}

//int main()
//{
//    hash_table<std::string> ht;
//
//    // Adding items to the hash table
//    ht.addItem("John", "Coffee");
//    ht.addItem("Jane", "Tea");
//    ht.addItem("Jim", "Juice");
//    ht.addItem("Jack", "Water");
//
//    // Printing the hash table
//    std::cout << "Hash table after adding items:\n";
//    ht.printTable();
//
//    // Searching for items in the hash table
//    std::cout << "\nSearching for Jane:\n";
//    ht.search("Jane");
//    
//    std::cout << "\nSearching for Jack:\n";
//    ht.search("Jack");
//    
//    std::cout << "\nSearching for Bob (not in table):\n";
//    ht.search("Bob");
//
//    // Deleting an item
//    std::cout << "\nDeleting Jane:\n";
//    ht.deleteNode("Jane");
//
//    // Printing the hash table after deletion
//    std::cout << "\nHash table after deleting Jane:\n";
//    ht.printTable();
//
//    // Adding an item to the previously deleted spot
//    ht.addItem("Jerry", "Soda");
//
//    // Printing the hash table after adding a new item
//    std::cout << "\nHash table after adding Jerry:\n";
//    ht.printTable();
//
//    return 0;
//}



#endif /* Header_h */
