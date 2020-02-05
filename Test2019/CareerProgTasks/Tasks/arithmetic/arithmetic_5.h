//
//  arithmetic_5.h
//  Test2019
//
//  Created by Denys Risukhin on 2/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_5_h
#define arithmetic_5_h

bool isNumberPowerOfTree(int n)
{
    // case 1
    // double x = log10(n) / log10(3);
    // return (n > 0) && (ceil(x) == floor(x));
    
    // case 2
    double x = log(n) / log(3);
    return (n > 0) && (abs(x - (int)(x + 0.5)) < 1e-10);
}

//test
//    cout << isNumberPowerOfTree(9) << endl;

#endif /* arithmetic_5_h */
