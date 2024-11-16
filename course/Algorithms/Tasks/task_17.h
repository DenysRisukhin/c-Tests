//
//  task_17.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_17_h
#define task_17_h

// The following code reverses an array. What is its runtime?

void reverse(int[] array)
{
    for (int i= 0; i <array.length/ 2; i++)
    {
        int other = array.length - i - 1;
        int temp = array[i];
        array[i] = array[other];
        array[other] = temp;
    }
}

// Answer: O(n)
// This algorithm runs inO( N) time. The fact that it only goes through half of the array (in terms of iterations) does not impact the big O time.

#endif /* task_17_h */
