//
//  11_templates.h
//  Test2019
//
//  Created by Risukhin Denys on 3/28/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef _1_templates_h
#define _1_templates_h

// Base case: Sum of zero arguments is 0
template<typename T>
constexpr T sum()
{
    return T(0);
}

// Recursive case: Sum the first argument with the sum of the rest
template<typename T, typename... Args>
constexpr T sum(T first, Args... rest)
{
    return first + sum<T>(rest...);
}

//int main()
//{
//    constexpr int result1 = sum<int>(1, 2, 3, 4, 5);
//    cout << result1 << endl;
//    static_assert(result1 == 15, "Test case 1 failed");
//
//    constexpr double result2 = sum<double>(1.1, 2.2, 3.3, 4.4, 5.5);
//    cout << result1 << endl;
//    static_assert(result2 == 16.5, "Test case 2 failed");
//
//    std::cout << "All test cases passed." << std::endl;
//
//    return 0;
//}


#endif /* _1_templates_h */
