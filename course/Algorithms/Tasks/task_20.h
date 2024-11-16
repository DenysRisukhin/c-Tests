//
//  task_20.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_20_h
#define task_20_h

// Example 9
// The following simple code sums the values of all the nodes in a balanced binary search tree. What is its runtime?

int sum(Node node)
{
    if (node == null)
    {
        return 0;
    }
    
    return sum(node.left) + node.value + sum(node.right);
}

// Answer: O(n)

#endif /* task_20_h */
