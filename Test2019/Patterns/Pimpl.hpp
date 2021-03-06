//
//  Pimpl.hpp
//  Test2019
//
//  Created by Denys Risukhin on 1/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Pimpl_hpp
#define Pimpl_hpp

#include <stdio.h>

// Pimpl Problems
// 1) нарушение const корректности
//    - используем smart pointer - deep_const_ptr<Private>
//    - можно обойтись без смартов путем создания 2-ух методо
// 2) доступ к классу контейнеру (в методах Private не вызыватся non static методы TestPimpl)
//    - используем back link

template<typename T>
class deep_const_ptr
{
public:
    explicit deep_const_ptr(T* ptr): m_ptr(ptr) {}
    const T& operator*() const { return m_ptr; }
    T& operator*() { return m_ptr; }
    const T* operator->() const { return m_ptr; }
    T* operator->() { return m_ptr; }
    
private:
    T* m_ptr = nullptr;
};

class TestPimpl
{
    TestPimpl();
    ~TestPimpl();
    
    void someMethod(double num);
    
private:
    class Private;
    
    // dPointer
    Private* m_dPtr = nullptr;
    
    // 2 сп устраняет проблему нарушения const корректности
    const Private* dMethod() const { return m_dPtr; }
    Private* dMethod() {return m_dPtr; }
    
    // замена
    // Private* m_dPtr
    // на
    //deep_const_ptr<Private> m_dPtr;
    // 1 сп устраняет проблему нарушения const корректност
};

#endif /* Pimpl_hpp */
