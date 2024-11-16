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

#include "GraphTask_02.h"
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
#include "MovingSemantic.h"
#include "Think_cell.h"

#include <iostream>
#include <type_traits>
//#include <boost/algorithm/string.hpp>
//
//#include <boost/asio.hpp>
//#include <boost/beast.hpp>
//#include <boost/beast/ssl.hpp>
//#include <boost/beast/http.hpp>

//#include "HTTPS.h"

constexpr int square(int x) {
    return x * x;
}

class Widget
    {
        public:
            Widget() { cout << "default" << endl; }
            Widget(int i, bool b) { cout << "int bool" << endl; }
            Widget(int i, double d) { cout << "int double" << endl; }
            Widget(std::initializer_list<std::string> list) { cout << "initializer_list" << endl; }
    };

int main()
{
    
    Widget w1(10, true);
                Widget w2{10, true};
                Widget w3(10, 5.0);
                Widget w4{10, 5.0};

              Widget w5;
                Widget w6(); // function call
                Widget w7{};
    Widget w8P{"", "", ""};
    
    constexpr int result = square(5); // Compile-time evaluation
    
    
    // RTTI
    // virtula method
    // type safer
    // run time
//    dynamic_cast<Base&>(Derived);
//
//    // compile time
//    // uses with digits casts
//    // inharitance
//    static_cast<>
//
//    // to skip the const
//    const_cast<>
    
    // pinter to void
    // pointers to functions
    // pointers
//    reinterpret_cast<<#type#>>(<#expression#>)
//
//    //c style cast
//    int a;
//    double b;
//    int c = (int)b;
    
    
//    char a = 'a';
//    char b = 'b';
//    const char *i = &a;
//
//    char const *j = &a;
//
//    char * const c  = &a;
//
//    for (unsigned int i = 1; i >= 0; i--)
//    {
//        cout << i << " ";
//
//        printf("%i", i);
//        cout << " ";
//
//        printf("%d", i);
//        cout << " ";
//
//        printf("%u", i);
//
//        cout << endl;
//    }

//    int arr[]{170, 45, 75, 90, 802, 24, 2, 66};
//    int arraySize = sizeof(arr) / sizeof(arr[0]);
//
//    //boubleSort(arr, 4);
//
//    //quickSort(arr, 0, 4);
//
//    //mergeSort(arr, 0, 4);
//
//    //heapSort(arr, arraySize);
//
//    radixSort(arr, arraySize);
//
//    for (int i = 0; i < arraySize; i++)
//    {
//        cout << arr[i] << " ";
//    }
//
//    cout << endl;

//    std::string s = "Boost Library Example";
//    std::vector<std::string> results;
//    boost::split(results, s, boost::is_any_of(" "));
//
//    for (const auto& word : results)
//    {
//           std::cout << word << std::endl;
//    }
    
    std::shared_ptr<int> f = std::make_shared<int>(int(5));
    std::shared_ptr<int> test(new int(6));
    
    vector<int> v1(10, 20);

    vector<int> v2{10, 20};
    
    for (auto i: v1)
    {
        cout << i << ' ';
    }
    
    cout << endl;
    
    for (auto i: v2)
    {
        cout << i << ' ';
    }
    
    cout << endl;
    
    return 0;
}
