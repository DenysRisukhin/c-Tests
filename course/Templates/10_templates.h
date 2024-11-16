//
//  10_templates.h
//  Test2019
//
//  Created by Risukhin Denys on 3/29/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef _10_templates_h
#define _10_templates_h

template<typename T, typename U, int N, typename... Args>
struct MultiArgTemplate
{
    void print()
    {
        std::cout << "Template with arguments: " << typeid(T).name() << ", " << typeid(U).name() << ", " << N;
        printVariadic<Args...>();
        std::cout << std::endl;
    }

private:
    // Helper function to print the variadic template arguments
        template<typename First, typename... Rest>

        void printVariadic()
        {
            std::cout << ", " << typeid(First).name();
            if constexpr (sizeof...(Rest) > 0)
            {
                printVariadic<Rest...>();
            }
        }
};

//int main()
//{
//
////    Instantiate the template with int, double, 5, and additional types (float, char, int)
//    MultiArgTemplate<int, double, 5, float, char, int> obj;
//    obj.print(); // Output: Template with arguments: i, d, 5, f, c, i
//
//    return 0;
//}

#endif /* _10_templates_h */
