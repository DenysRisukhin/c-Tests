//
//  task_19.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_19_h
#define task_19_h

// Suppose we had an algorithm that took in an array of strings, sorted each string, and then sorted the full array. What would the runtime be?

// Not correct: O(n) * O(n log n) * O(n log n) = O(n^2 log n * nlog n) = O(n^2 log n)

// Answer:

// Let's define new terms-and use names that are logical.
// Let 's' be the length of the longest string.
// Let 'a' be the length of the array.

// Now we can work through this in parts:

    // 1. Sorting each string is                       0(s log s)

    // 2. We have to do this for every string          0(a * s log s)

    // 3. Now we have to sort all the strings          0(a * s log a)

    // final result: 0(a * s(log a + log s))

    



#endif /* task_19_h */
