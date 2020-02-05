//
//  arithmetic_7.h
//  Test2019
//
//  Created by Denys Risukhin on 2/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_7_h
#define arithmetic_7_h

#pragma mark - a_1 рекурсия

int add(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add(sum, carry);
}

#pragma mark - а_2 итеративная

int add(int a, int b)
{
    while (b != 0)
    {
        int sum = a ^ b; // суммирование без переноса
        int carray = (a & b) << 1; // перенос без суммирования
        a = sum;
        b = carry;
    }
    return a;
}


#endif /* arithmetic_7_h */
