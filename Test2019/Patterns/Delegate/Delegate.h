//
//  Delegate.h
//  Test2019
//
//  Created by Denys Risukhin on 1/2/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Delegate_h
#define Delegate_h

#include <iostream>

// https://habr.com/ru/sandbox/48020/?mobile=no%3Fmobile%3Dno
// https://habr.com/en/post/78299/

using namespace std;

// Variadric Templates» — шаблоны с переменным количеством аргументов
// добавлена возможность подключать несколько методов и функций
// Обновил реализацию для метода
// Обновил реализацию для обычной функции

#pragma mark - Interfaces

template<typename... Args>
class IContainer
{
public:
    virtual void Call(Args...) {} //Вызов функции
    
    virtual ~IContainer() {}
    
    IContainer<Args...>* next = nullptr; //Указатель на следующий элемент для односвязного списка
};

#pragma mark - MContainer

// Обновил реализацию для метода
template< typename T, typename M, typename... Args >
class MContainer : public IContainer<Args...>
{
public:
    MContainer( T* c, M m ) : mClass( c ), mMethod( m ) {}
    void Call(Args... args)
    {
        (mClass->*mMethod)( args... );
    }
    
private:
    T *mClass;
    M mMethod;
};

// Обновил реализацию для обычной функции
template< typename M, typename... Args >
class FContainer : public IContainer<Args...>
{
public:
    FContainer( M m ) : mMethod( m ) {}
    void Call(Args... args)
    {
        (mMethod)( args... );
    }
    
private:
    M mMethod;
};

#pragma mark - delegate

template<typename... Args>
class Delegate
{
public:
    Delegate()
    {
        mContainerHead = new IContainer<Args...>(); //Создаем начальный элемент
        mContainerTail = mContainerHead; //Назначаем конец списка для быстрого добавления новых элементов
        mContainerHead->next = nullptr;
    }
    
    ~Delegate()
    {
        //Тут мы полностью удаляем все элементы
        IContainer<Args...>* container = mContainerHead;
        
        while(container)
        {
            IContainer<Args...>* temp = container->next;
            delete container;
            container = temp;
        }
    }
    
    //Удаление всех связей
    void Clear()
    {
        IContainer<Args...> *container = mContainerHead->next;
        while(container)
        {
            IContainer<Args...> *temp = container->next;
            delete container;
            container = temp;
        }
        
        mContainerHead->next = nullptr;
        mContainerTail = mContainerHead;
    }
    
    //Подключение метода
    template<typename T, typename M>
    void Connect(T *c, M m)
    {
        mContainerTail->next = new MContainer< T, M, Args... >(c,m);
        mContainerTail->next->next = nullptr;
        mContainerTail = mContainerTail->next;
    }
    
    //Подключение функции
    template<typename M>
    void Connect(M m)
    {
        mContainerTail->next = new FContainer< M, Args... >(m);
        mContainerTail->next->next = nullptr;
        mContainerTail = mContainerTail->next;
    }
    
    //Отключение метода
    template<typename T, typename M>
    void Disconnect(T *c, M m)
    {
        IContainer<Args...> *container = mContainerHead;
        while(container->next)
        {
            //Тут я использовал dynamic_cast для нахождения нужного элемента.
            //Возможно не лучший спосо, но ничего другого не придумал.
            MContainer<T, M, Args...> *temp = dynamic_cast< MContainer<T, M, Args...>* >(container->next);
            
            if(temp)
            {
                if(container->next == mContainerTail)
                {
                    mContainerTail = container;
                }
                container->next = container->next->next;
                delete temp;
                break;
            }
            container = container->next;
        }
    }
    
    //Отключение функции
    template<typename M>
    void Disconnect(M m)
    {
        IContainer<Args...> *container = mContainerHead;
        while(container->next)
        {
            FContainer<M, Args...> *temp = dynamic_cast< FContainer<M, Args...>* >(container->next);
            
            if(temp)
            {
                if(container->next == mContainerTail)
                {
                    mContainerTail = container;
                }
                container->next = container->next->next;
                delete temp;
                break;
            }
            container = container->next;
        }
    }
    
    //Перегружаем оператор вызова функции
    void operator ()(Args... args)
    {
        Call(args...);
    }
    
    //Ну и сам вызов делегата
    void Call(Args... args)
    {
        IContainer<Args...>* container = mContainerHead;
        while(container)
        {
            container->Call(args...);
            container = container->next;
        }
    }
    
private:
    IContainer<Args...>* mContainerHead = nullptr;
    IContainer<Args...>* mContainerTail = nullptr;
};

// test

//#include <iostream>
//#include "Delegate.h"
//
//using namespace std;
//
////Простой класс для примера
//class A
//{
//public:
//    void f(int a, int b, int c)
//    {
//        cout << "a+b+c = " << a+b+c << endl;
//    }
//};
//
////И простая функция
//void f2(int a, int b, int c)
//{
//    cout << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;
//}
//
//int main()
//{
//    //Создаем делегат принмающий фукнции с тремя переменными типа int
//    Delegate<int,int,int> d;
//
//    //Тестовый класс
//    A testA;
//
//    //Подключаем метод и функцию
//    d.Connect(&testA, &A::f);
//    d.Connect(f2);
//
//    //Вызываем
//    d.Call(1,2,3);
//
//    //Отключаем функцию
//    d.Disconnect(f2);
//    //Вызываем делегат еще раз
//    d.Call(2,4,5);
//
//    return 0;
//}

//В выводе у нас будет:
//a+b+c = 6
//a = 1
//b = 2
//c = 3
//a+b+c = 11


#endif /* Delegate_h */
