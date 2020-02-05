//
//  arrays_14.h
//  Test2019
//
//  Created by Denys Risukhin on 1/23/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_14_h
#define arrays_14_h

void getPairSums(int* arr, int size, int sum) {
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == sum) {
                // put to some structure or matrix;
            }
        }
    }
}


    
//    int arr[]{4, 1, 2, 1, 1, 2};
//    
//    int size = sizeof(arr)/sizeof(int);
//    getPairSums(arr, size, 3);
//    
//    std::cout << std::endl;

#endif /* arrays_14_h */
