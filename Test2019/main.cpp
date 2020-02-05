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

#include "MiddleTasks.h"
#include "DelegateCocos.h"

using namespace std;

//#include "AbstractFactory.h"
//#include "Singleton.h"
//#include "Builder.h"
//#include "Strategy.hpp"
//using namespace std;

//struct C {int* data;};

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    Song(const std::wstring& artist_, const std::wstring& title_)
    : artist{ artist_ }, title{ title_ } {}
    
    std::wstring artist;
    std::wstring title;
};

struct Photo : public MediaAsset
{
    Photo(const std::wstring& date_,
          const std::wstring& location_,
          const std::wstring& subject_)
    : date{ date_ }, location{ location_ }, subject{ subject_ } {}
    
    std::wstring date;
    std::wstring location;
    std::wstring subject;
};

// unsigned short
// unsigned int

char* f() {
//    char buff[100];
//
//    strcpy(buff, "Test");
    char* ss = "dsdsdsd";
    return ss;
}

bool isSubString(std::string resStr, std::string s2) {
    
//    for (auto idx = 0; idx < resStr.size(); idx += s2.size()) {
//        idx = resStr.find(s2, idx);
//    }
    if (resStr.find(s2) != -1){
        return true;
    } else {
        return false;
    }
}



void f(int** arr, int size) {
    std::vector<int> row;
    std::vector<int> column;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 0) {
                row.push_back(i);
                column.push_back(j);
            }
        }
    }
    
    if (!row.empty()) {
        for (auto r: row) {
            for (int j = 0; j < size; j++) {
                arr[r][j] = 0;
            }
        }
    }
    
    if (!column.empty()) {
        for (int i = 0; i < size; i++) {
            for (auto c: column) {
                arr[i][c] = 0;
            }
        }
    }
}





bool isChangedString(std::string s1, std::string s2) {
    std::sort(s1.begin(),s1.end());
    std::sort(s2.begin(),s2.end());
    return strcmp(s1.c_str(), s2.c_str());
}

char* strRevert(char* str) {
    
    char* ss = "advartagement";
    char* end = ss;
   // char* start = str;
    
    while(*end++ != '\0') {}
    
    *end-- = '\0';
    
    char temp;
    while(str < end) {
        temp = *ss;
        
        *ss = 't';
        *ss = *end;
        *end = temp;
        
        ++ss;
        --end;
    }
    
    return ss;
}






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

// Проверить есть ли простое число в диапазоне 0 да size - 1
bool checkPrime(int size) {
    if (size < 2) {
        return false;
    }
  
    for (int i = 0; i <= sqrt(size); i++) {
        if (i % 2 == 0) {
            return false;
        }
    }
    return true;
}

// найти все простые числа
int getNextPrime(bool* flags, int prime, int size) {
    int next = prime + 1;
    
    while (next < size && flags[next]) {
        next++;
    }
    return next;
}

// sieve - решето
void sieveOfEratosthenes(bool* flags, int size) {
    int prime = 2;
    
    while (prime <= sqrt(size)) {
        // crossOff - вычеркнуть оставшиеся числа кратные prime
        // начиная с prime * prime
        for (int i = prime * prime; i < size; i += prime) {
            flags[i] = true;
        }
        
        prime = getNextPrime(flags, prime, size);
    }
}

int NOD(int a,int b) {
    if (b == 0) {
        return a;
    }
    return NOD(b, a % b);
}

int NOK(int a, int b) {
   // return a*b/NOD(a, b);
    return a / NOD(a, b) * b;
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



int main()
{
   
    cout << endl;
    
    // 1
    //int mas[10000]{0};
    
    //Eratosfen(mas, 10000 - 1);
    
    // 2
//    const int size = 100;
//    bool flags[size]{false};
//    flags[0] = true;
//    flags[1] = true;
//
//    sieveOfEratosthenes(flags, size);
//
//    for (auto i = 0; i < size; i++) {
//        std::cout << flags[i] << ' ';
//    }
//

    
    return 0;
}























