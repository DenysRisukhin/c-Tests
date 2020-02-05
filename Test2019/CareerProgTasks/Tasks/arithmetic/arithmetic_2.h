//
//  arithmetic_2.h
//  Test2019
//
//  Created by Denys Risukhin on 2/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_2_h
#define arithmetic_2_h

//Положит число можно представить в виде произведения простых чисел
//84 = 2^2 * 3^1 * 5^0 * 7^1 * 11^0
//
//Проверка на простоту
//Натуральное число - положит целое число. N - множество всех натуральных чисел
//
//Простое число - это натуральное число  > 1 имеющее 2-а натуральных делителя: 1 и само себя.
//Последовательность начинается с
//2 3 5 7 11 13 17 19 23
//
//Составное число - натуральное число имеющее больше 2-ух делителей

#pragma mark - 2_1

// Проверить есть ли простое число в диапазоне 0 да size - 1
bool checkPrime(int size) {
    if (size < 2) {
        return false;
    }
    
    for (int i = 0; i <= sqrt(size); i++) {
        if (i % 2 == 0) {
            return false;
        }
    }
    return true;
}

#pragma mark - 2_2

// найти все простые числа
int getNextPrime(bool* flags, int prime, int size) {
    int next = prime + 1;
    
    while (next < size && flags[next]) {
        next++;
    }
    return next;
}

// sieve - решето
void sieveOfEratosthenes(bool* flags, int size) {
    int prime = 2;
    
    while (prime <= sqrt(size)) {
        // crossOff - вычеркнуть оставшиеся числа кратные prime
        // начиная с prime * prime
        for (int i = prime * prime; i < size; i += prime) {
            flags[i] = true;
        }
        
        prime = getNextPrime(flags, prime, size);
    }
}

//Test
//const int size = 100;
//bool flags[size]{false};
//flags[0] = true;
//flags[1] = true;
//
//sieveOfEratosthenes(flags, size);
//
//for (auto i = 0; i < size; i++) {
//    std::cout << flags[i] << ' ';
//    }
//
//    std::cout << std::endl;

    
#pragma mark - 2_3

//НОД - наибольший общий делитель. Если есть ‘a’ и ‘b’, то есть ‘с’ на которое делится и ‘а’ и ‘b’
//
//3 НОД 5 = 1
//8 НОД 4 = 4
//
//алг Евклида для НОД
//abs - модуль, страховка от отрицательных чисел
//Входящие числа > 0
//если b > а то остаток меньшего от большего a%b будет меньше и числа развернутся (a и b) поменяются местами и дальше пойдут как обычно

int NOD(int a,int b) {
    if (b == 0) {
        return a;
    }
    return NOD(b, a % b);
}

// Test
// std::cout << NOD(abs(-3), abs(5)) << std::endl;

#pragma mark - 2_4

//НОК - наименьшее общее кратное. Минимальное число ‘с’ которое делится и на ‘а’ и на ‘b’
//
//3 НОК 5 = 15
//8 НОК 4 = 4

int NOK(int a, int b)
{
    // return a*b/NOD(a, b); // ok
    return a / NOD(a, b) * b; // ok
}

// Test
// std::cout << NOK(abs(3), abs(-5)) << std::endl;

#endif /* arithmetic_2_h */
