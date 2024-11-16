//
//  task_14.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_14_h
#define task_14_h

// What is the runtime of the below code?

void printPairs(int[] array)
{
    for (int i = 0; i < array.length; i++)
    {
        for (int j = 0; j < array.length; j++)
        {
            System.out.println(array[i] + "," + array[j]);
        }
    }
}

// There are O(N^2) pairs; therefore, the runtime is O(N^2)

#endif /* task_14_h */
