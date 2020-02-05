//
//  arrays_12.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_12_h
#define arrays_12_h

int findEndOfLeftSubsequence(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i-1])
        {
            return i - 1;
        }
    }
    return size - 1;
}

int findStartOfRightSubsequence(int* arr, int size) {
    for (int i = size - 2; i >= 0; i--) {
        if (arr[i] > arr[i+1])
        {
            return i + 1;
        }
    }
    return 0;
}

int shrinkLeft(int* arr, int size, int minIdx, int start) {
    int comp = arr[minIdx];
    for (int i = start - 1; i >= 0; i--) {
        if (arr[i] <= comp)
        {
            return i + 1;
        }
    }
    return 0;
}

int shrinkRight(int* arr, int size, int maxIdx, int start) {
    int comp = arr[maxIdx];
    for (int i = start; i < size; i++) {
        if (arr[i] >= comp)
        {
            return i - 1;
        }
    }
    return size - 1;
}

void findUnsortedSequence(int* arr, int size) {
    int endLeft = findEndOfLeftSubsequence(arr, size);
    
    if (endLeft >= size - 1)
    {
        return;
    }
    
    int startRight = findStartOfRightSubsequence(arr, size);
    
    int maxIdx = endLeft;    // 5
    int minIdx = startRight; // 8
    
    for (int i = endLeft + 1; i < startRight; i++) {
        if (arr[i] < arr[minIdx])
        {
            minIdx = i;
        }
        
        if (arr[i] > arr[maxIdx])
        {
            maxIdx = i;
        }
    }
    
    int leftIdx = shrinkLeft(arr, size, minIdx, endLeft);
    int rightIdx = shrinkRight(arr, size, maxIdx, startRight);
    
    cout << leftIdx << ' ' << rightIdx;
    //
    //    for (int i = 0; i < size; i++) {
    //        cout << arr[i] << ' ';
    //    }
    //
    //    std::cout << std::endl;
    std::sort(arr + leftIdx, arr + rightIdx + 1);
}

// Tests
//
//    int arrA[]{1, 2, 4, 7, 10, 11, 8, 12, 5, 6, 16, 18, 19};
//
//    int sizeA = sizeof(arrA)/sizeof(int);
//
//    findUnsortedSequence(arrA, sizeA);
//
//    std::cout << std::endl;
//
//    for (int i = 0; i < sizeA; i++) {
//        cout << arrA[i] << ' ';
//    }
//
//    std::cout << std::endl;

#endif /* arrays_12_h */
