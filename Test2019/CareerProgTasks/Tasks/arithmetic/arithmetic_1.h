//
//  arithmetic_1.h
//  Test2019
//
//  Created by Denys Risukhin on 2/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_1_h
#define arithmetic_1_h

// 2 % 13 = 2
// 1 % 2 = 1
// 50 % 3 = 2

#pragma mark - 1 parity / not paryty

bool isParity(int val)
{
    if (val % 2 == 0)
    {
        // parity
        return true;
    }
    return false;
}

#pragma mark - 2 parity / not paryty

// проверить младший бит числа
// у четного он вседа 0
bool isParity(int val)
{
    if (val & 1 == 0)
    {
        // parity
        return true;
    }
    return false;
}

//test
//cout << isParity(4) << endl;

#endif /* arithmetic_1_h */
