//
//  arrays_10.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_10_h
#define arrays_10_h

#pragma mark - simple solutions(наивное): O(n^2) or O(AB)

int getMinDifference(int* arrA, int sizeA, int* arrB, int sizeB) {
    int minDif = INT_MAX;
    
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            int diff = abs(arrA[i] - arrB[j]);
            if (diff < minDif)
            {
                minDif = diff;
            }
        }
    }
    
    return minDif;
}

#pragma mark - - good solutions: O(AlogA + BlogB)

int getMinDifference(int* arrA, int sizeA, int* arrB, int sizeB) {
    //int minDif = 1000;
    
    std::sort(arrA, arrA + sizeA);
    std::sort(arrB, arrB + sizeB);
    
    // 1 2 3 11 15
    // 8 19 23 127 235
    
    int aIdx = 0;
    int bIdx = 0;
    int diff = INT_MAX;
    
    while (aIdx < sizeA && bIdx < sizeB)
    {
        if (abs(arrA[aIdx] - arrB[bIdx]) < diff)
        {
            diff = abs(arrA[aIdx] - arrB[bIdx]);
        }
        
        if (arrA[aIdx] < arrB[bIdx])
        {
            aIdx++;
        }
        else
        {
            bIdx++;
        }
    }
    
    return diff;
}


//int main() {
//
//    // test 1
//    int arrA[]{1, 3, 15, 11, 2};
//    int arrB[]{23, 127, 235, 19, 8};
//
//    int sizeA = sizeof(arrA)/sizeof(int);
//    int sizeB = sizeof(arrA)/sizeof(int);
//
//    cout << getMinDifference(arrA, sizeA, arrB, sizeB);
//
//    std::cout << std::endl;

#endif /* arrays_10_h */
