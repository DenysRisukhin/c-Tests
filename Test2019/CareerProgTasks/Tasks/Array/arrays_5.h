//
//  arrays_5.h
//  Test2019
//
//  Created by Denys Risukhin on 1/21/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_5_h
#define arrays_5_h

//xor - двоичный оператор (слева на право). Равен 1 если один из аргументов имеет значение 1

// 1^3^7
// step 1
//0001 // 1
//0011 // 3
//----
//0010 // 2

// step 2
//0010 // 2
//0111 // 7
//----
//0101 // 5

//1. a^0 = a
//2. a^a = 0
//3. a^b = b^a      коммутативна
//4. (a^b)^c = a^(b^c) ассоциативна
//5. (1^3)^7 = 1^(3^7)   ->  5 = 5

// 3 & 5 показывают что порядок в котором мы ксорим числа не имеет значения
// a^b^x^c^b^a^c = a^a ^ b^b ^ c^c ^x = 0^0^0^x = x
// тоесть результат любой последовательности операций xor полностью независит от порядка операндов(порядка эл-ов)


int isUniqueElem(int* arr, int size){
    int lostElem = 0;
    
    for (int i = 0; i < size; i++)
    {
        lostElem ^= arr[i];
    }
    
    return lostElem;
}

#pragma mark - c++11 approach

#include <numeric>

//int arr[]{3, 4, 3, 4, 5, 8, 9, 8, 9};
//int val = std::accumulate(begin(arr), end(arr), 0, [] (int x, int y) {return x^y;});

#endif /* arrays_5_h */
