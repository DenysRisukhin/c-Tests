//
//  arrays_6.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_6_h
#define arrays_6_h

void getMaxSubSum(int* arr, int size) {
    int firstIdx = 0;
    int lastIdx = 0;
    int curFirstIdx = 0;
    
    int bestSum = 0;
    int curSum = 0;
    
    int i = 0;
    
    for (i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (bestSum < curSum)
            {
                firstIdx = curFirstIdx;
                lastIdx = i - 1;
                bestSum = curSum;
            }
            
            curSum += arr[i];
            
            if (curSum <= 0)
            {
                curFirstIdx = i + 1;
                curSum = 0;
            }
        }
        else
        {
            curSum += arr[i];
        }
    }
    
    if (bestSum < curSum)
    {
        firstIdx = curFirstIdx;
        lastIdx = i - 1;
    }
    
    cout << firstIdx << ' ' << lastIdx;
}

//int main() {
//    
//    int arr[]{-1, 2, 3, -10, 5};
//    getMaxSubSum(arr, 5);
//    
//    std::cout << std::endl;
//    
#endif /* arrays_6_h */
