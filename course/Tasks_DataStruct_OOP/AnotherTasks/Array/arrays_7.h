//
//  arrays_7.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_7_h
#define arrays_7_h

#pragma mark - 16.17

int getMaxSumOfSuccessiveInArray()
{
    int arr[]{2, -8, 3, -2, 4, -10};
    int size = sizeof(arr) / sizeof(int);
    
    int curSum = 0;
    int maxSum = 0;
    
    for (auto i = 0; i < size; i++)
    {
        curSum += arr[i];
        
        if (curSum > maxSum)
        {
            maxSum = curSum;
        }
        else if (curSum < 0)
        {
            curSum = 0;
        }
    }
    
    return maxSum;
}

#endif /* arrays_7_h */
