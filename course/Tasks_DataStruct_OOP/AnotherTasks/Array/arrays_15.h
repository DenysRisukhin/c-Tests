//
//  arrays_15.h
//  Test2019
//
//  Created by Denys Risukhin on 1/23/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_15_h
#define arrays_15_h

void getPairSums(int* arr, int size, int val) {
    int first = 0;
    int last = size - 1;
    
    while (first < last)
    {
        int curSum = arr[first] + arr[last];
        
        if (curSum == val)
        {
            cout << arr[first] << ' ' << arr[last] << endl;
            first++;
            last--;
        }
        else
        {
            if (curSum < val)
            {
                first++;
            }
            else
            {
                last--;
            }
        }
    }
}

// Test

//    int arr[]{1, 2, 5, 6, 7, 9, 12};
//
//    int size = sizeof(arr)/sizeof(int);
//    getPairSums(arr, size, 7);
//
//    std::cout << std::endl;

#endif /* arrays_15_h */
