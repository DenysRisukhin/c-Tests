//
//  Header.h
//  Test2019
//
//  Created by Risukhin Denys on 9/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Header_h
#define Header_h

// Example 12

// This code counts all permutations of a string.

void permutation(String str)
{
    permutation(str, "");
}

void permutation(String str, String prefix)
{
    if (str.length() == 0)
    {
        System.out.println(prefix);
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            String rem = str.substring(0, i) + str.substring(i + 1);
            permutation(rem, prefix + str.charAt(i));
        }
    }
}

// Answer: O(n^2 * n!)

#endif /* Header_h */
