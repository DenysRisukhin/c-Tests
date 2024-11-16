//
//  task_04.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_04_h
#define task_04_h

// The following code performs integer division. What is its runtime (assume a and b are both positive)?

int div(int a, int b)
{
    int count = 0;
    int sum = b;

    while (sum <= a)
    {
        sum += b;
        count++;
    }

    return count;
}

#endif /* task_04_h */
