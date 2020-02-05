//
//  arithmetic_9.h
//  Test2019
//
//  Created by Denys Risukhin on 2/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_9_h
#define arithmetic_9_h

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

#pragma mark - divide

int divide(int a, int b)
{
    if (b == 0)
    {
        cout << "thow exception" << endl;
    }
    
    int absa = abs(a);
    int absb = abs(b);
    
    int product = 0;
    int x = 0;
    
    while (product + absb <= absa)
    {
        product += absb;
        x++;
    }
    
    if ((a < 0 && b < 0) || (a > 0 && b > 0))
    {
        return x;
    } else {
        return myNegate(x);
    }
    
}

#endif /* arithmetic_9_h */
