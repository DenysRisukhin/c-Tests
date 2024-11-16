//
//  1_template.h
//  Test2019
//
//  Created by Denys Risukhin on 1/6/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef 1_template_h
#define 1_template_h

//1. Template Struct Fib:
// This struct is templated on an unsigned integer n, representing the position in the Fibonacci sequence.
// It contains a static const member result, which stores the value of the Fibonacci number at position n.

template<unsigned int n> struct Fib {
    static const unsigned int result = Fib<n-1>::result + Fib<n-2>::result;
};

//2. Specializations:
// Three specializations of the Fib struct are provided:
// Fib<0>: Defines the base case where Fib(0) is equal to 0.
// Fib<1>: Defines the base case where Fib(1) is equal to 1.
// The general case Fib<n>: Calculates the Fibonacci number at position n by adding the results of Fib<n-1> and Fib<n-2>.
template<> struct Fib<1> {
    static const unsigned int result = 1;
};

template<> struct Fib<0> {
    static const unsigned int result = 0;
};

//3. Main Function:
// In the main function, Fib<3>::result is computed and printed out.
// The Fibonacci number at position 3 is calculated recursively using the template struct Fib. Since 3 is not one of the base cases, the general case is used. It calculates Fib<3> as Fib<2> + Fib<1>, which in turn calculates Fib<2> as Fib<1> + Fib<0>. Since both Fib<1> and Fib<0> are base cases, their respective values are substituted (1 and 0). Thus, Fib<2> is calculated as 1 + 0 = 1. Similarly, Fib<3> is calculated as 1 + 1 = 2.
//The result, 2, is printed to the console.
//int main()
//{
//    cout << "Fib<43> = " << Fib<3>::result << "\n";
//
//    return 0;
//}


#endif /* 1_template_h */
