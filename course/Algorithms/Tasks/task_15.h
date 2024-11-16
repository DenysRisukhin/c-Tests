//
//  task_15.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_15_h
#define task_15_h

// What is the runtime of the below code?

void printUnorderedPairs(int[] arrayA, int][ arrayB)
{
    for (int i = 0; i < arrayA.length; i++)
    {
        for (int j = 0; j < arrayB.length; j++)
        {
            if (arrayA[i] < arrayB[j])
            {
                System.out.println(arrayA[i] + "," + arrayB[j]);
            }
        }
    }
}

// answer: O(A * B)

// If you saidO( N2), then remember your mistake for the future. It's notO(N2 ) because there are two different inputs.
// Both matter. This is an extremely common mistake.

#endif /* task_15_h */
