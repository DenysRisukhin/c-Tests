//
//  task_16.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_16_h
#define task_16_h

// What about this strange bit of code?

void printUnorderedPairs(int[] arrayA, int[] arrayB)
{
    for (int i= 0; i < arrayA.length; i++)
    {
        for (int j = 0; j < arrayB.length; j++)
        {
            for (int k= 0; k < 100000; k++)
            {
                System.out.println(arrayA[i] + "," + arrayB[j]);
            }
        }
    }
}

// Answer: O(A*B)
// 100,000 units of work is still constant, so the runtime is 0(ab).


#endif /* task_16_h */
