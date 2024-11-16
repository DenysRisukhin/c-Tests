//
//  task_06.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_06_h
#define task_06_h

//The following code computes the [integer] square root of a number. If the number is not
//a perfect square (there is no integer square root), then it returns -1. It does this by trying increasingly large numbers until it finds the right value (or is too high). What is its runtime?

int sqrt(int n)
{
    for (int guess = 1; guess * guess <= n; guess++)
    {
        if (guess * guess == n)
        {
            return guess;
        }
    }

    return -1;
}

#endif /* task_06_h */
