//
//  task_22.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_22_h
#define task_22_h

// Example 11

// The following code computes n! (n factorial). What is its time complexity?

int factorial(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// Answer: O(n)
// This is just a straight recursion from n to n-1 to n-2 down to 1.


#endif /* task_22_h */
