//
//  arithmetic_10.h
//  Test2019
//
//  Created by Denys Risukhin on 1/21/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_10_h
#define arithmetic_10_h

int missingValue(int* arr, int size)
{
    int sum = (size + 1) * (size + 2) / 2;
    
    for (int i = 0; i < size; i++)
    {
        sum -= arr[i];
    }
    return sum;
}


#endif /* arithmetic_10_h */
