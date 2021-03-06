//
//  main.cpp
//  Test2019
//
//  Created by Denys Risukhin on 6/25/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#include <ctime>
#include <iostream>
//#include <memory>
#include <thread>
//#include "auto_ptr.h"
//#include "smart_ptr.h"
//#include "shared_ptr.h"
//#include "weak_ptr.h"
//#include "iterator"

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "Queue.h"
#include "Stack.h"
#include "Tree.h"

#include <queue>
#include <stack>

#include "graph.h"
#include "dynamic_array.h"
#include <exception>

#include <iostream>
#include <fstream>
#include <algorithm>

#include <functional>
#include <list>
#include <set>
#include <map>
#include <iomanip>
#include <exception>
#include <ctime>
#include "Delegate.h"
#include "Observer2.h"

#include "DelegateCocos.h"

#include "linked_list.h"
#include "double_list.h"

using namespace std;

//#include "AbstractFactory.h"
//#include "Singleton.h"
//#include "Builder.h"
//#include "Strategy.hpp"
//using namespace std;

int closestToZero(int* arr, int size) {
//    if (size) {
//        return 0;
//    }
    
    int b = 0;//arr[0];
    int x = 0;
    int min = x;
    
    for (int i = 0; i < size; i++) {
        if (x - arr[i] < min) {
            if (x - arr[i] > 0) {
                min = x - arr[i];
                b = arr[i];
            }
        }
    }
    
    return b;
}


// TestOOP_X
// TestSyntax_X
// TestTemplates_X

// Task: What do we get as result on the console?
// Task: Is there any error?
//*************

// TestSyntax_15 Quizful
// Task: What do we get as result on the console?
//       Is there any error?




//class Integer {
//    int m_val;
//public:
//    Integer(int val = 0) { m_val = val; }
//
//    friend Integer operator++(Integer* obj);
//
//    void print() {cout << m_val; }
//};
//
//Integer operator++(Integer* obj) {
//    obj->m_val++;
//    return obj;
//}

//Integer obj(5);
////obj++;
//(&obj)++;
//obj.print();

#pragma mark - subtraction

int myNegate(int a)
{
    int neg = 0;
    int newSign = a < 0 ? 1 : -1;
    
    while (a != 0)
    {
        neg += newSign;
        a += newSign;
    }
    
    return neg;
}

int myMinus(int a, int b) {
    return a + myNegate(5);
}

#pragma mark - multiple

int multiply(int a, int b)
{
    if (a < b)
    {
        return multiply(b, a);
    }
    int sum = 0;
    
    for (int i = abs(b); i > 0; i = myMinus(i, 1)) {
        sum += a;
    }
    
    if (b < 0) {
        sum = myNegate(sum);
    }
    return sum;
}

int abs(int a) {
    if (a < 0)
    {
        return myNegate(a);
    }
    else
    {
        return a;
    }
}


class A {
public:
    A() {}
    virtual void foo() { cout << "foo A()" << endl; }
    ~A() {}
};


class B: public A {
public:
     virtual void foo() { cout << "foo B()" << endl; }
};

#pragma mark - global logic

class Foo
{
public:
    Foo(int val = 0): mBar(val) {} // fix: c-tor (c_tor and c-tor) by default added
    
    int getBar()
    {
        return mBar;
    }
    
    void setBar(int bar)  // fix: return type edded
    {
        mBar = bar;
    }

private:
    int mBar;
};


// fix: approach 1
// weak side: we must release memory in main()
//Foo* make_foo(int val) // fix: correct argument added
//{
//    Foo* ptr = new Foo;
//    ptr->setBar(val);
//    return ptr;
//}

// fix: approach 2
// be carefully: we cant use &
// std::shared_ptr<Foo>& make_foo(int val)
// because ptr - local variable, so we will get memory leak
// we can't use links or pointers here as return value
std::shared_ptr<Foo> make_foo(int val) // fix: correct argument added
{
    std::shared_ptr<Foo> ptr = std::make_shared<Foo>();
    ptr->setBar(val);
    return ptr;
}

void bar(Foo* foo) // fix: correct argument - pointer
{
    foo->setBar(10);
}

// a) with functor
struct AAA
{
    float operator() (int x, int y) const { return float(x)/y; }
};

void testAAA()
{
    function<float(int, int)> f = AAA();
    cout << f(5,3);
}

// b) with pointers to mathods
struct BBB
{
    int foo(int i) { return i * i; }
};

void testBBB()
{
    function<int(BBB*, int)> f = &BBB::foo;
    BBB b;
    f(&b, 5);
}



int main()
{
  
    
    return 0;
}

//    std::unique_ptr<A> ptr = std::make_unique<B>();
//    vector<A> vec;
//
//    B b;
//    vec.push_back(b);
//    vec.push_back(b);
//    vec.push_back(b);
//
//    for (auto item: vec)
//        item.foo();
//    cout << endl;























