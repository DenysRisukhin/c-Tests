//
//  linked_list.h
//  Test2019
//
//  Created by Denys Risukhin on 7/24/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

template<class T>
struct Node {
    Node(const T& data)
    : m_data(data), m_next(nullptr) {}
    
    int m_data;
    Node* m_next = nullptr;
};

template<class T>
class linked_list {
public:
    linked_list() {}
    linked_list(const linked_list<T>& list) {}
    linked_list(linked_list<T>&& list) {}
    ~linked_list() {}
    
    const linked_list<T>& operator=(const linked_list<T> list) {}
    const bool operator==(const linked_list<T> list) {}
    friend std::ostream& operator<<(std::ostream& stream, const linked_list<T>& list) {}
    
    void inserAtFront(const T& data) {}
    void insertAtBack(const T& data) {}
    void removeFromFront(const T& data) {}
    void removeFromBack(const T& data) {}
    
    bool search(const T& data) const {}
    void insert(const T& data) {}
    void remove(const T& data) {}
    
    void reverse() {}
    bool isEmpty() const {}
    void print() const {}
    
private:
    Node<T>* m_first = nullptr;
    Node<T>* m_last = nullptr;
    
private:
    Node<T> getNewNode(const T data);
    void copy(const Node<T>*& firstList, const Node<T>* secondList);
    bool compare(const Node<T>* firstList, const Node<T>* secondList);
};

#endif /* linked_list_h */
