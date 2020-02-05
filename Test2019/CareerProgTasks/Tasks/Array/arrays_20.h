//
//  arrays_20.h
//  Test2019
//
//  Created by Denys Risukhin on 1/27/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_20_h
#define arrays_20_h

void pushBack(int*& arr, int& size, int insertionValue)
{
    int* newArr = new int[size + 1];
    
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    
    newArr[size] = insertionValue;
    
    size++;
    
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
//    int insertionValue = 5;
//    
//    pushBack(arr, size, insertionValue);
//    
//    std::cout << std::endl;
//    
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ' ';
//    }
//    
//    std::cout << std::endl;

#endif /* arrays_20_h */
