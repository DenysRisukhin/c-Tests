//
//  DataStruct.h
//  Test2019
//
//  Created by Denys Risukhin on 7/10/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef DataStruct_h
#define DataStruct_h

#include <iostream>

template <typename T>
class dynamic_array
{
public: // Interface
    dynamic_array();
    dynamic_array(int size = 0, int maxSize = 0, T* array = nullptr);
    dynamic_array(const dynamic_array<T>& array);
    dynamic_array(dynamic_array<T>&& array);
    ~dynamic_array();
    
    T& operator[](unsigned int index);
    dynamic_array<T>& operator=(const dynamic_array<T>& array);
    friend std::ostream& operator<<(std::ostream  output, const dynamic_array<T>& array);
    friend bool operator==(const dynamic_array<T>& lhs, const dynamic_array<T>& rhs);
    
    void push_back(const T& value);
    void insert(unsigned int index, const T& value);
    void erase(unsigned int index);
    int search(const T& value);
    void clear();
    unsigned int size() const; // Get array size
    void resize(int delta);    // Increase or decrease the size of the array by a cpecified number of elements
    void print() const;
    
protected:
    // Number of elements in an array
    int m_curSize;
    int m_maxSize;
    
    T* m_array = nullptr;
    
private:
    // Increase array size
    void enlarge(int delta);
    void shrink(int delta);
};

#endif /* DataStruct_h */
