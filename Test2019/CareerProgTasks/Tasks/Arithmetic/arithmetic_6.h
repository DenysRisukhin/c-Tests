//
//  arithmetic_6.h
//  Test2019
//
//  Created by Denys Risukhin on 2/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_6_h
#define arithmetic_6_h

void printFib(int a, int b)
{
    int sum = a + b;
    std::cout << sum << std::endl;
    a = b;
    b = sum;
    
    if (INT_MAX - a > b)
    {
        printFib(a, b);
    }
}

//test
//
//    printFib(1, 2);
//    cout << endl;

#endif /* arithmetic_6_h */
