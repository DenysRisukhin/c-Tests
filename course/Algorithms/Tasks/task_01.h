//
//  task_01.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_01_h
#define task_01_h

// The following code computes the product of a and b. What is its runtime?
int product(int a, int b)
{
    int sum = 0;
    
    for (int i= 0; i < b; i++)
    {
        sum += a;
    }

    return sum;
}

#endif /* task_01_h */
