//
//  task_25.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_25_h
#define task_25_h

// Example 14

// The following code prints all Fibonacci numbers from Oto n. What is its time complexity?

void allFib(int n)
{
    for (int i= 0; i < n; i++)
    {
        System.out.println(i + ": "+ fib(i));
    }
}

int fib(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

// Answer: O(2^N)

#endif /* task_25_h */
