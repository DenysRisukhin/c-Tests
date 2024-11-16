//
//  task_21.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_21_h
#define task_21_h

// Example 10

// The following method checks if a number is prime(простым) by checking for divisibility on numbers less than it. It only needs to go up to the square root of n because if n is divisible by a number greater than its square root then it's divisible by something smaller than it.

// For example, while 33 is divisible by 11 (which is greater than the square root of 33), the "counterpart"to 11 is 3 (3 * 11 = 33). 33 will have already been eliminated as a prime number by 3.

// What is the time complexity of this function?

boolean isPrime(int n)
{
    for (int x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
        {
            return false;
        }
    }

    return true;
}

// Answer: O(sqrt n);

// The for loop will start when x = 2 and end when x*x = n. Or,ino ther words,it stops when x = sqrt(n) (when x equals the square root of n).

// This for loop is really something like this:

boolean isPrime(int n)
{
    for (int x = 2; x <= sqrt(n); x++)
    {
        if (n % x == 0)
        {
            return false;
        }
    }

    return true;
}

#endif /* task_21_h */
