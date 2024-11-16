//
//  arrays_3.h
//  Test2019
//
//  Created by Denys Risukhin on 1/21/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_3_h
#define arrays_3_h

int getMinElement(int* arr, int size) {
    if (size == 0)
    {
        return -1;
    }
    
    int minElem = INT_MAX;
    
    for (int i = 0; i < size; i++) {
        if (minElem > arr[i])
        {
            minElem = arr[i];
        }
    }
    
    return minElem;
}


//test
//    
//    int arr[]{11, 2, 11, -6, 44, 5, 2};
//    int size = sizeof(arr)/sizeof(int);
//    
//    cout << getMinElement(arr, size);
//    
//    std::cout << std::endl;


#endif /* arrays_3_h */
