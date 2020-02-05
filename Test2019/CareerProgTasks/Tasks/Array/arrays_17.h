//
//  arrays_17.h
//  Test2019
//
//  Created by Denys Risukhin on 1/27/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_17_h
#define arrays_17_h

void remove(int* arr, int size, int val) {
    for (int i = 0; i < size; i++)
    {
        if (val == arr[i])
        {
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            break;
        }
    }
    
    int newArr[size - 1];
    
    for(int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
}

//test
//    const int size = 6;
//    int arr[size]{1, 2, 4, 7, 10, 12};
//    int removingValue = 7;
//
//    remove(arr, size, removingValue);
//
//    std::cout << std::endl;
//
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ' ';
//    }
//
//    std::cout << std::endl;

#endif /* arrays_17_h */
