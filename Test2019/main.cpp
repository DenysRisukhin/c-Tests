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

#pragma mark - init

void initVec(vector<int>& numbers, const int size)
{
    numbers.reserve(size);
    numbers.resize(size);
    
    for (auto& number: numbers)
    {
        number = 1 + rand() % 9;
    }
}

void initMap(map<int, int>& numbersMap, const int size)
{
    for (int i = 0; i < size; i++)
    {
        numbersMap.emplace(i, 1 + rand() % 9);
    }
}

#pragma mark - remove

void removeFromVec(vector<int>& numbers)
{
    int ctr = 0;
    int elemAmount = 0 + rand() % 14;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        int elemIdx = 0 + rand() % numbers.size() - 1;
        
        for(auto pos = numbers.begin(); pos != numbers.end();)
        {
            if((*pos) == numbers[elemIdx])
            {
                if (ctr > elemAmount)
                {
                    break;
                }
                
                pos = numbers.erase(pos);
                ctr++;
            }
            else
            {
                ++pos;
            }
        }
    }
}

void removeFromMap(map<int, int>& myMap)
{
    int ctr = 0;
    int elemAmount = 0 + rand() % 14;

    for (int i = 0; i < myMap.size(); i++)
    {
        int elemIdx = 0 + rand() % myMap.size() - 1;

        for(auto pos = myMap.begin(); pos != myMap.end();)
        {
            if(pos->second == elemIdx)
            {
                if (ctr > elemAmount)
                {
                    break;
                }

                pos = myMap.erase(pos);
                ctr++;
            }
            else
            {
                ++pos;
            }
        }
    }
}

#pragma mark - print

void printVec(vector<int>& numbers)
{
    for (auto& number: numbers)
    {
        cout << number << ' ';
    }
    
    cout << endl;
}

void printMap(map<int, int>& myMap)
{
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;
}

#pragma mark - synchronization

void synchronization(map<int, int>& numbersMap, vector<int>& numbers)
{
    bool isFound = false;
    
    for (auto posVec = numbers.begin(); posVec != numbers.end();)
    {
        isFound = false;
        
        for (auto pos = numbersMap.begin(); pos != numbersMap.end(); ++pos)
        {
            
            if ((*posVec) == pos->second)
            {
                isFound = true;
                break;
            }
        }
        
        if (!isFound)
        {
            posVec = numbers.erase(posVec);
        }
        else
        {
            ++posVec;
        }
    }
    
    // clear map
    for (auto pos = numbersMap.begin(); pos != numbersMap.end();)
    {
        pos = numbersMap.erase(pos);
    }
    
    // init map
    for (int i = 0; i < numbers.size(); i++)
    {
        numbersMap[i] = numbers[i];
    }
}

#pragma pack(push, 4)
struct Foo
{
    char a;
    short int value;
    int b;
};
#pragma pack(pop)

int main()
{
    
    Foo obj;
    
    cout << sizeof(Foo) << endl;
    
    return 0;
}























