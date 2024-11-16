//
//  SeparateChaining.h
//  Test2019
//
//  Created by Risukhin Denys on 6/7/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef SeparateChaining_h
#define SeparateChaining_h

#include <iostream>
#include <list>
#include <vector>
#include <utility>

// Separate chaining handles collisions by maintaining a list of all elements (сохраняя список всех элементов) that hash to the same value. Each bucket of the
// hash table is a linked list (or another collection) of entries.

class HashTable {
public:
    HashTable(int size);
    void insertItem(int key, const std::string& value);
    void deleteItem(int key);
    std::string searchItem(int key);
    void displayHash();

private:
    int hashFunction(int key);
    int bucketSize;
    std::vector<std::list<std::pair<int, std::string>>> table;
};

HashTable::HashTable(int size) {
    bucketSize = size;
    table.resize(bucketSize);
}

int HashTable::hashFunction(int key) {
    return key % bucketSize;
}

void HashTable::insertItem(int key, const std::string& value) {
    int index = hashFunction(key);
    table[index].emplace_back(key, value);
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    auto& chain = table[index];
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (it->first == key) {
            chain.erase(it);
            return;
        }
    }
    std::cout << "Key not found\n";
}

std::string HashTable::searchItem(int key)
{
    int index = hashFunction(key);
    auto& chain = table[index];
    for (auto& item : chain)
    {
        if (item.first == key)
        {
            return item.second;
        }
    }
    return "Key not found";
}

void HashTable::displayHash() {
    for (int i = 0; i < bucketSize; ++i)
    {
        std::cout << "Bucket " << i << ": ";
        
        for (auto& item : table[i])
        {
            std::cout << "[" << item.first << ", " << item.second << "] ";
        }
        std::cout << std::endl;
    }
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



#endif /* SeparateChaining_h */
