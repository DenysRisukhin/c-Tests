//
//  9_template.h
//  Test2019
//
//  Created by Risukhin Denys on 3/29/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef __template_h
#define __template_h

#include <iostream>
#include <type_traits>

using namespace std;

// Concept to check if a type is integral
template <typename T>
concept Integral = std::is_integral_v<T>;

// Concept to check if a type is floating point
template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

// Concept to check if a type is arithmetic (integral or floating point)
template <typename T>
concept Arithmetic = Integral<T> || FloatingPoint<T>;

// Function constrained with Integral concept
template <Integral T>
T add(T a, T b) {
    return a + b;
}

// Function constrained with FloatingPoint concept
template <FloatingPoint T>
T multiply(T a, T b) {
    return a * b;
}

// Function constrained with Arithmetic concept
template <Arithmetic T>
void printResult(T result) {
    std::cout << "Result: " << result << std::endl;
}

//int main()
//{
//    int sumResult = add(5, 3); // Calls add(int, int)
//    std::cout << "Sum result: " << sumResult << std::endl;
//
//    double productResult = multiply(2.5, 4.0); // Calls multiply(double, double)
//    std::cout << "Product result: " << productResult << std::endl;
//
//    printResult(10); // Calls printResult(int)
//    printResult(3.14); // Calls printResult(double)
//
//    // The following line will cause a compilation error
//    //printResult("Hello");
//
//    return 0;
//}

#endif /* __template_h */
