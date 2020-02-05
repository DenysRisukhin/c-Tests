//
//  arrays_19.h
//  Test2019
//
//  Created by Denys Risukhin on 1/27/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_19_h
#define arrays_19_h

void popBack(int*& arr, int& size)
{
    --size;
    
    int* newArr = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    
    delete[] arr;
    
    arr = newArr;
}

//test
//
//    int size = 5;
//    int* arr = new int[size];
//
//    for (int i = 0; i < size; i++) {
//        arr[i] = i;
//    }
//
//    popBack(arr, size);
//
//    std::cout << std::endl;
//
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ' ';
//    }
//
//    std::cout << std::endl;


#endif /* arrays_19_h */
