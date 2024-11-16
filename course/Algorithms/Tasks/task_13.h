//
//  task_13.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_13_h
#define task_13_h

// What is the runtime of the below code?

void foo(int[] array) {
    
    int sum = 0;
    int product = 1;
    
    for (int i = 0; i < array.length; i++)
    {
        sum =+ array[i);
    }
    
    for (int i= 0; i < array.length; i++)
    {
        product *= array[i];
    }
    
    System.out.println(sum + ", " + product);
}



// Answer: O(n)
// The fact that we iterate through the array twice doesn't matter.

#endif /* task_13_h */
