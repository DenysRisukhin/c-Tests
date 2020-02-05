//
//  rand_1.h
//  Test2019
//
//  Created by Denys Risukhin on 2/3/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef rand_1_h
#define rand_1_h

//5 * rand5() + rand5(); гарантирует все значения равно вероятны т к один способ получения кажого числа из диапазона от 0 до 24

int rand7()
{
    while(1)
    {
        int num = 5 * rand5() + rand5();
        if (num < 21)
        {
            return num % 7;
        }
    }
}

#endif /* rand_1_h */
