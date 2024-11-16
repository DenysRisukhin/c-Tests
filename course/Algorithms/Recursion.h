//
//  Recursion.h
//  Test2019
//
//  Created by Risukhin Denys on 8/5/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Recursion_h
#define Recursion_h

int f(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    
    return f(n - 1) + f(n - 1);
}

#endif /* Recursion_h */
