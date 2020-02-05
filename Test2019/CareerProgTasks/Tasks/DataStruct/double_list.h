//
//  double_list.h
//  Test2019
//
//  Created by Denys Risukhin on 7/24/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef double_list_h
#define double_list_h

template<class T>
struct Node {
    Node(const T& data)
    : m_data(data), m_next(nullptr), m_prev(nullptr) {}
    
    int m_data;
    Node* m_next = nullptr;
    Node* m_prev = nullptr;
};

template<class T>
class double_list {
public:
    double_list() {}
    double_list(const double_list<T>& list) {}
    double_list(double_list<T>&& list) {}
    ~double_list() {}
    
    const double_list<T>& operator=(const double_list<T> list) {}
    const bool operator==(const double_list<T> list) {}
    friend std::ostream& operator<<(std::ostream& stream, const double_list<T>& list) {}
    
    void inserAtFront(const T& data) {}
    void insertAtBack(const T& data) {}
    void removeFromFront(const T& data) {}
    void removeFromBack(const T& data) {}
    
    bool search(const T& data) const {}
    void insert(const T& data) {}
    void remove(const T& data) {}
    void sort() {}
    
    void reverse() {}
    bool isEmpty() const {}
    void print() const {}
    
private:
    Node<T>* m_head = nullptr;
    
private:
    Node<T> getNewNode(const T data);
    void copy(const Node<T>*& firstList, const Node<T>* secondList);
    bool compare(const Node<T>* firstList, const Node<T>* secondList);
};

#endif /* double_list_h */
