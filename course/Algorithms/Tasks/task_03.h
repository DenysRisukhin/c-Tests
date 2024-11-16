//
//  task_03.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_03_h
#define task_03_h

// The following code computes a % b. What is its runtime?
int mod(int a, int b)
{
    if (b <= 0)
    {
        return -1;
    }
    
    int div = a % b;
    return a - div * b;
}

#endif /* task_03_h */
