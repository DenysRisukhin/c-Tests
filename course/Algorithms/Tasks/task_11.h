//
//  task_11.h
//  Test2019
//
//  Created by Risukhin Denys on 8/25/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef task_11_h
#define task_11_h

//The following code prints all strings of length k where the characters are in sorted order. It does this by generating all strings of length k and then checking if each is sorted. What is its runtime?

int numChars = 26;

void printSortedStrings(int remaining)
{
    printSortedStrings(remaining, "");
}

void printSortedStrings(int remaining, String prefix)
{
    if (remaining == 0)
    {
        if (isinOrder(prefix))
        {
            System.out.println(prefix);
        }
       
    }
    else
    {
        for (int i= 0; i < numchars; i++)
        {
            char c = ithletter(i);
            printSortedStrings(remaining - 1, prefix + c);
        }
    }
}

boolean isinOrder(String s)
{
    for (int i= 1; i < s.length(); i++)
    {
        int prev ithLetter(s.charAt(i - 1));
        int curr = ithLetter(s.charAt(i));
        
        if (prev > curr)
        {
            return false;
        }
    }
    return true;
}

char ithLetter(int i)
{
    return (char) (((int) 'a') + i);
}

#endif /* task_11_h */
