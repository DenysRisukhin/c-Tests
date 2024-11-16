//
//  arrays_16.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_16_h
#define arrays_16_h

#pragma mark - solution 1 with O(n^2)

int getSeparateArrIdx1(int* arr, int size)
{
    if (size < 3)
    {
        cout << "array size empty or low" << endl;
        return -1;
    }
    
    int leftSum = 0;
    int rightSum = 0;
    
    for(int j = 0; j < size; j++)
    {
        int lCtr = j - 1;
        int rCtr = j + 1;
        
        while (lCtr >= 0)
        {
            leftSum += arr[lCtr];
            lCtr--;
        }
        
        while (rCtr < size)
        {
            rightSum += arr[rCtr];
            rCtr++;
        }
        
        if (leftSum == rightSum)
        {
            return arr[j];
        }
        
        leftSum = 0;
        rightSum = 0;
    }
    return -1;
}

#pragma mark - solution 2 with O(???)

int getSeparateArrIdx2(int* arr, int size)
{
    if (size < 2)
    {
        cout << "array size empty or low" << endl;
        return -1;
    }
    
    int commonSum = 0;
    
    int lIdx = 0;
    int rIdx = size - 1;
    
    int lSum = arr[lIdx];
    int rSum = arr[rIdx];
    
    lIdx++;
    rIdx--;
    
    // if array has 3 elements and first == last
    if (size == 3 && lSum == rSum)
    {
        return arr[lIdx];
    }
    
    for (int i = 0; i < size; i++)
    {
        commonSum += arr[i];
    }
    
    while(lIdx < rIdx)
    {
        for (int i = lIdx; i < size; i++)
        {
            if (lSum >= rSum)
            {
                break;
            }
            lSum += arr[i];
            lIdx++;
        }
        
        for (int j = rIdx; j >= 0; j--)
        {
            if (lSum <= rSum)
            {
                break;
            }
            rSum += arr[j];
            rIdx--;
        }
        
        if (lSum == rSum)
        {
            int siparateVal = commonSum - lSum - rSum;
            
            if ((arr[lIdx] == siparateVal) && (arr[rIdx] == siparateVal))
            {
                return arr[lIdx];
            }
            
            // continue
            lSum += arr[++lIdx];
        }
    }
    
    return -1;
}

// Tests

//int arr[2]{20, 5};
//int size = sizeof(arr) / sizeof(int);
//
//cout << "idx: " << getSeparateArrIdx1(arr, size);
//cout << "idx: " << getSeparateArrIdx2(arr, size);

#endif /* arrays_16_h */
