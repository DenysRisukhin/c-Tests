//
//  task_24.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_24_h
#define task_24_h

// Example 13
// The following code computes the Nth Fibonacci number.

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
// Generally speaking, when you see an algorithm with multiple recursive calls, you're looking at exponential runtime.

#endif /* task_24_h */
