//
//  arithmetic_3.h
//  Test2019
//
//  Created by Denys Risukhin on 2/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_3_h
#define arithmetic_3_h

#pragma mark - difference

//int a = 9;
//int b = 5;
//
//a = a - b;
//b = a + b;
//a = b - a;

#pragma mark - XOR (better, becasue works for different types) page 498

//int a = 101;
//int b = 110;
//
//a = a - b; a = 101^110 = 011
//b = a + b; b = 011^110 = 101
//a = b - a; c = 101^011 = 110

template <typename T>
void mySwap(T& x, T& y)
{
    x = x ^ y; // return 1 if x!=y, тоесть проверяет имеют ли x y разные значения
    y = x ^ y;
    x = x ^ y;
}

//test
//    char a = 'a';
//    char b = 'b';
//    mySwap(a, b);
//    cout << a << ' ' << b << endl;

#endif /* arithmetic_3_h */
