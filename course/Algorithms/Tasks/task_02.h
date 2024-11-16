//
//  task_02.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_02_h
#define task_02_h

// The following code computes a b. What is its runtime?
int power(int a, int b)
{
    if (b < 0)
    {
        return 0; // error
    }
    else if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * power(a, b - 1);
    }
}
    

#endif /* task_02_h */
