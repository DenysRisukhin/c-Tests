//
//  task_26.h
//  Test2019
//
//  Created by Risukhin Denys on 9/6/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_26_h
#define task_26_h

// Example 15

// The following code prints all Fibonacci numbers from Oto n. However, this time, it stores (i.e., caches) previ­ ously computed values in an integer array. If it has already been computed, it just returns the cache. What is its runtime?

void allFib(int n)
{
    int[] memo = new int[n + 1];
    
    for(int i = 0;i < n; i++)
    {
        System.out.println(i + ": "+ fib(i, memo));
    }
}

int fib(int n, int[] memo)
{
    if (n =< 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (memo[n] > 0)
        return memo[n];
    
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);

    return memo[n];
}

// Answer: O(n)

#endif /* task_26_h */
