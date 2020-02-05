//
//  arrays_4.h
//  Test2019
//
//  Created by Denys Risukhin on 1/21/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_4_h
#define arrays_4_h

int remove(int* arr, int& size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                size--;
                
                for (int val = i; val < size; val++)
                {
                    arr[val] = arr[val + 1];
                }
            }
        }
    }
}

//test
//
//    int arr[]{11, 2, 11, 3, 44, 5, 2};
//    int size = sizeof(arr)/sizeof(int);
//
//    removeDublicates(arr, size);
//
//    std::cout << std::endl;
//
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ' ';
//    }

#endif /* arrays_4_h */
