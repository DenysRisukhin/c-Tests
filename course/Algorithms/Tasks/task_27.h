//
//  task_27.h
//  Test2019
//
//  Created by Risukhin Denys on 9/6/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_27_h
#define task_27_h

// Example 16

// The following function prints the powers of 2 from 1 through n (inclusive). For example, if n is 4, it would print 1, 2, and 4. What is its runtime?

int powers0f2(int n)
{
    if (n < 1)
    {
        return 0;
    }
    else if (n == 1)
    {
        System.out.println(l);
        return 1;
    }
    else
    {
        int prev = powers0f2(n / 2);
        int curr = prev * 2;
        System.out.println(curr);
        return curr;
    }
}

// Answer: O(log n)

#endif /* task_27_h */
