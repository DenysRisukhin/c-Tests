//
//  arrays_18.h
//  Test2019
//
//  Created by Denys Risukhin on 1/27/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_18_h
#define arrays_18_h

#pragma mark - case a

void insert(int* arr, int& height, int size, int val) {
    if (arr[height - 1] < val)
    {
        arr[height] = val;
        height++;
        return;
    }
    
    int left = 0;
    int right = height - 1;
    
    while (left < right)
    {
        int middle = (left + right) / 2;
        
        if (arr[middle] >= val)
        {
            right = middle;
        }
        else if (arr[middle] <= val)
        {
            left = middle + 1;
        }
    }
    
    for (int i = height - 1; i >= left; i--) {
        arr[i+1] = arr[i];
    }
    
    arr[left] = val;
    height++;
}

#pragma mark - case b

// create new array with newSize = size + 1;
//    1 копируем все значения в новый массив
//    2 если вставка в середину то исчем число после которого нужен сдвиг
//    3 сдвиг
//    4 вставка

#pragma mark - tests

// test a)
//    const int size = 8;
//    int arr[size]{1, 2, 4, 7, 10};
//    int height = 5;
//    insert(arr, height, size, 8);
//    std::cout << std::endl;



#endif /* arrays_18_h */
