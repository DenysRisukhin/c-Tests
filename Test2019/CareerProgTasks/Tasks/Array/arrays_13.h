//
//  arrays_13.h
//  Test2019
//
//  Created by Denys Risukhin on 1/23/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_13_h
#define arrays_13_h

int sum(int* arr, int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return sum;
}

void findSwapValues(int* arrA, int sizeA, int* arrB, int sizeB) {
    int sum1 = sum(arrA, sizeA);
    int sum2 = sum(arrB, sizeB);
    
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            int newSum1 = sum1 - arrA[i] + arrB[j];
            int newSum2 = sum2 - arrB[j] + arrA[i];
            
            if (newSum1 == newSum2)
            {
                //int values[2]{i, j};
                //return values;
                cout << arrA[i] << ' ' << arrB[j] << endl;
                return;
            }
        }
    }
    // return nullptr;
}

// Test
//    int arrA[]{4, 1, 2, 1, 1, 2};
//    int arrB[]{3, 6, 3, 3};
//    // 4 6
//    // 1 3
//
//    int sizeA = sizeof(arrA)/sizeof(int);
//    int sizeB = sizeof(arrB)/sizeof(int);
//
//    findSwapValues(arrA, sizeA, arrB, sizeB);
//
//    std::cout << std::endl;

#endif /* arrays_13_h */
