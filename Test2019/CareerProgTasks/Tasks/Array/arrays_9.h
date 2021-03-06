//
//  arrays_9.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_9_h
#define arrays_9_h

// смотря что еще имеется ввиду
// возможно нужно просто найти мин положит число в массиве и вернуть его

int getClosestToZero(int* arr, int size) {
    if (arr == nullptr || size == 0)
    {
        return 0;
    }
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
        {
            if (arr[i-1] > 0)
            {
                return arr[i-1];
            }
            else if (arr[i+1] > 0)
            {
                return arr[i+1];
            }
        }
    }
    
    return 0;
}

//int main() {
//    
//    // test 1
//    int arr[]{-1, 2, -3, 0, 3, 5};
//    // test 2
//    //int arr[]{};
//    int size = sizeof(arr)/sizeof(int);
//    
//    cout << getClosestToZero(arr, size);

#endif /* arrays_9_h */
