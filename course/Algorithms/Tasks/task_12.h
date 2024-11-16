//
//  task_12.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_12_h
#define task_12_h

//The following code computes the intersection (the number of elements in common) of two arrays. It assumes that neither array has duplicates. It computes the intersection by sorting one array (array b) and then iterating through array a checking (via binary search) if each value is in b. What is its runtime?

int intersection(int[] a, int[] b)
{
    mergesort(b);
    int intersect = 0;
    
    for (int x : a)
    {
        if (binarySearch(b, x) >= 0)
        {
            intersect++;
        }
    
    }

    return intersect;
}

#endif /* task_12_h */
