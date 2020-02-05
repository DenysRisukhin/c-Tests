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
class HashNode {
public:
    T m_drink;
    T m_name;
    HashNode<T>* m_next = nullptr;
};

template <class T>
class hash_table {
public:
    hash_table() {}
    
    ~hash_table() {}
    
    int getHash(const T& key) {}
    
    void addItem(const T& name, const T& drink) {}
    
    int numberOfItemsInIndex(int idx) { }
    
    void search(const T&) {}
    
    void deleteNode(const T&) {}
    
private:
    static int const m_tableSize = 4;
    HashNode<T>* m_hashTable[m_tableSize];
};


#endif /* hash_table_h */
