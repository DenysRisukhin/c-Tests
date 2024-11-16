//
//  task_05.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_05_h
#define task_05_h

// The following code computes the [integer] square root of a number. If the number is not a perfect square (there is no integer square root),
// then it returns -1. It does this by successive guessing. If n is 100, it first guesses SO. Too high? Try something lower - halfway between 1 and SO. What is its runtime?

int sqrt(int n)
{
    return sqrt_helper(n, 1, n);
}

int sqrt_helper(int n, int min, int max)
{
    if (max < min)
    {
        return -1; // no square root
    }

    int guess = (min + max) / 2;
    if (guess * guess == n)
    {
        return guess; // found it!
    }
    else if (guess * guess < n)
    {
        // too low
        return sqrt_helper(n, guess + 1, max); // try higher
    }
    else
    {
        return sqrt_helper(n, min, guess - 1); // try lower
    }
}

#endif /* task_05_h */
