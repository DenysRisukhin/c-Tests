//
//  task_10.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_10_h
#define task_10_h

// The following code sums the digits in a number. What is its big O time?

int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

#endif /* task_10_h */
