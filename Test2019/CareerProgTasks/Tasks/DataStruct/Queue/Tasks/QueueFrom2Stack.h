//
//  QueueFrom2Stack.h
//  Test2019
//
//  Created by Denys Risukhin on 1/6/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef QueueFrom2Stack_h
#define QueueFrom2Stack_h

template <typename T>
class queue {
public:
    
    void push_back(const T elem) {
        m_lifo.push(elem);
    }
    
    T front() {
        if (m_fifo.empty()) {
            updateFifoStack();
        }
        
        return m_fifo.top();
    }
    
    void pop() {
        if (m_fifo.empty()) {
            updateFifoStack();
        }
        
        m_fifo.pop();
    }
    
    bool empty() const { return m_lifo.empty() && m_fifo.empty(); }
    
private:
    std::stack<T> m_lifo;
    std::stack<T> m_fifo;
    
    void updateFifoStack() {
        while ( !m_lifo.empty() ) {
            m_fifo.push(m_lifo.top());
            m_lifo.pop();
        }
    }
};

#endif /* QueueFrom2Stack_h */
