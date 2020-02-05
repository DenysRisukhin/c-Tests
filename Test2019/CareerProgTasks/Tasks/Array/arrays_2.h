//
//  arrays_2.h
//  Test2019
//
//  Created by Denys Risukhin on 1/21/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_2_h
#define arrays_2_h

void merge(int* arrA, int sizeA, int* arrB, int sizeB) {
    int cursizeB = sizeB;
    
    for (int i = sizeA - 1; i > sizeB; i--)
    {
        arrA[i] = arrB[--cursizeB];
    }
}

//Test
//
//    int arrA[10]{1, 2, 3, 4, 5};
//    int arrB[5]{6, 7, 8, 9, 10};
//
//    merge(arrA, 10, arrB, 5);
//
//    std::cout << std::endl;
//
//    for (int i = 0; i < 10; i++) {
//        cout << arrA[i] << ' ';
//    }

#endif /* arrays_2_h */
