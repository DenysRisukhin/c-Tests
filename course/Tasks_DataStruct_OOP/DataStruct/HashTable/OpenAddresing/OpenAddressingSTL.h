//
//  OpenAddressing.h
//  Test2019
//
//  Created by Risukhin Denys on 6/7/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef OpenAddressing_h
#define OpenAddressing_h

#include <iostream>
#include <vector>

// Open addressing handles collisions by probing (путем поиска) for the next available slot. Common probing methods include linear probing,
// quadratic probing, and double hashing.

class HashTable
{
public:
    HashTable(int size);

    void insertItem(const int key, const std::string& value);
    void deleteItem(const int key);

    std::string searchItem(int key);
    void displayHash();

private:
    int hashFunction(int key);

private:
    std::vector<std::pair<int, std::string>> table;
    std::vector<bool> occupied; // оккупированный

    int m_bucketSize;
};

HashTable::HashTable(const int size)
    : m_bucketSize(size)
{
    table.resize(m_bucketSize, {-1, ""});
    occupied.resize(m_bucketSize, false);
}

int HashTable::hashFunction(int key)
{
    return key % m_bucketSize;
}

void HashTable::insertItem(const int key, const std::string& value)
{
    int index = hashFunction(key);
    int originalIndex = index;

    bool isIndexValid = occupied[index];
    while (isIndexValid)
    {
        index = (index + 1) % m_bucketSize;
        if (index == originalIndex)
        {
            std::cout << "Hash table is full\n";
            return;
        }
    }

    table[index] = {key, value};
    occupied[index] = true;
}

void HashTable::deleteItem(const int key)
{
    int index = hashFunction(key);
    int originalIndex = index;
    
    while (occupied[index])
    {
        if (table[index].first == key)
        {
            occupied[index] = false;
            table[index] = {-1, ""};
            return;
        }
        
        index = (index + 1) % m_bucketSize;
        if (index == originalIndex)
        {
            break;
        }
    }
    std::cout << "Key not found\n";
}

std::string HashTable::searchItem(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;
    
    while (occupied[index])
    {
        if (table[index].first == key)
        {
            return table[index].second;
        }
        
        index = (index + 1) % m_bucketSize;
        if (index == originalIndex)
        {
            break;
        }
    }
    return "Key not found";
}

void HashTable::displayHash()
{
    for (int i = 0; i < m_bucketSize; ++i)
    {
        if (occupied[i])
        {
            std::cout << "[" << table[i].first << ", " << table[i].second << "] ";
        }
        else
        {
            std::cout << "[EMPTY] ";
        }
    }
    std::cout << std::endl;
}

//int main() {
//    HashTable ht(7);
//
//    ht.insertItem(15, "Value1");
//    ht.insertItem(11, "Value2");
//    ht.insertItem(27, "Value3");
//    ht.insertItem(8, "Value4");
//    ht.insertItem(12, "Value5");
//
//    ht.displayHash();
//
//    std::cout << "Search for key 27: " << ht.searchItem(27) << std::endl;
//
//    ht.deleteItem(11);
//    ht.displayHash();
//
//    return 0;
//}


#endif /* OpenAddressing_h */
