//
//  task_18.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_18_h
#define task_18_h

// Which of the following are equivalent toO(N)? Why?

// 1. O(N + P),where P < N/2
// 2. O(2N)
// 3. O(N + log N)
// 4. O(N + M)

// Answer:

// 1. If P < N/2,then we know that N is the dominant term so we can drop the 0(P).
// 2. 0(2N) isO(N) since we drop constants.
// 3. O(N) dominates O(log N),so we can drop the O(log N).
// 4. There is no established relationship between N and M, so we have to keep both variables in there

// Therefore, all but the last one are equivalent to O(N).

#endif /* task_18_h */
