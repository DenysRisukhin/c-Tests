//
//  arithmetic_8.h
//  Test2019
//
//  Created by Denys Risukhin on 2/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_8_h
#define arithmetic_8_h

int factorsOf5(int i)
{
    int ctr = 0;
    
    while (i % 5 == 0)
    {
        ctr++;
        i /= 5;
    }
    
    return ctr;
}

int countFactZeros(int num)
{
    int cnt = 0;
    for (int i = 2; i <= num; i++)
    {
        cnt += factorsOf5(i);
    }
    return cnt;
}

//test
//    factorsOf5(5);
//    
//    cout << endl;

#endif /* arithmetic_8_h */
