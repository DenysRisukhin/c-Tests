//
//  5_template.h
//  Test2019
//
//  Created by Risukhin Denys on 3/29/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef __template_h
#define __template_h

#include <iostream>

// Factorial template meta-programming
template <int N>
struct Factorial
{
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0>
{
    static const int value = 1;
};

int main()
{
    // Calculate the factorial of 5
    constexpr int result = Factorial<5>::value;
    std::cout << "Factorial of 5 is: " << result << std::endl; // Output: Factorial of 5 is: 120

    // Calculate the factorial of 10
    constexpr int result10 = Factorial<10>::value;
    std::cout << "Factorial of 10 is: " << result10 << std::endl; // Output: Factorial of 10 is: 3628800

    return 0;
}

#endif /* __template_h */
