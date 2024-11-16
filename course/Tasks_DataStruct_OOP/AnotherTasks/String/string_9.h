//
//  string_9.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_9_h
#define string_9_h

//with 2, 8, 10, 16 support - https://github.com/popcorn1429/myAtoi/blob/master/simple_atoi.h

// A char * является указателем на a char. Указатель - это просто адрес в какое-то место в памяти. (указатель только адрес, он ничего не знает о том, на что он
// указывает).
// В C/С++ (и Java) строки состоят из символов, которые могут индивидуально рассматриваться как целые числа (обычно один байт), благодаря ASCII.

// В C/С++ указатель на элемент некоторого типа такой же, как указатель на массив элементов этого типа.
// Строки в чистом C - это просто массивы char s, с '\0' (NUL) в конце, чтобы вы знали, когда попадете в конец строки, не обойдя всю ее длину

// Requirements:
// +1.1 What does return function if her arqument equal NULL?
// +1.2 or argument is not a digit
// +2.  Which behaviour do we get if input data is "123hello"?
// +3.  Which value or exception does return the function if
//      meaning of her argument bigger then avalaible int range?
// -4.  In which number system does function work? Is it enought
//      only decimal system?
// +5.  Do we need to support either negative numbers or value '-1'
//      as result for error indication?
// +6.  Do we need to ignor witespace at the begining of a string?
//      If yes, what signs can we imagine as whitespace(space, tab)?
// -7.  Do we need support both 32 bit and 64 bit platforms?

// tests
// printf("INT_MAX is %d\nINT_MIN is %d\n", INT_MAX, INT_MIN);
// printf("myResule is %d\n", i_atoi("2147483648"));
// printf("myResule is %d\n", i_atoi("-2147483649"));
// printf("myResule is %d\n", i_atoi(" \t 3649"));
// printf("myResule is %d\n", i_atoi("12fg"));

int i_atoi(const char* str)
{
    // 1.1 null check
    if (str == nullptr)
    {
        std::cout << "error: nullptr" << std::endl;
        return -1;
    }
    
    int digit = 0; // index of first digit
    int sign = 1; // sign as positiv
    int result = 0;
    
    // 5. sign handling
    if (str[digit] == '-')
    {
        sign = -1;
        digit++;
    }
    
    // 6. eliminate whitespace and tab
    while (str[digit] == ' ' || str[digit] == '\t' || str[digit] == '\r')
    {
        digit++;
    }
    
    // 1.2 checking a sign as a number
    if( (str[digit] < '0' || str[digit] > '9') )
    {
        std::cout << "error: not digit" << std::endl;
        return -1;
    }
    
    // Checks signs one by one while they are numbers.
    // 1. Checking sign as digit: if digit value is: 0 <= value < 10,
    //    then value has int type.
    while (str[digit] >= '0' && str[digit] <= '9')
    {
        // 3. int range check
        //  INT_MAX is 2147483647
        //  INT_MIN is -2147483648
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && str[digit]-'0' > INT_MAX % 10))
        {
            if(sign > 0)
            {
                return INT_MAX;
            }
            else
            {
                return INT_MIN;
            }
        }
        
        // Save new digit as result and do multipling between current
        // result meaning and 10, then add digit after conversion
        
        // @value       10               this is "shift" value over;
        // @expression  str[digit] - '0' this is the integer value of
        //                               the sign;
        result = result * 10 + str[digit++] - '0';
    }
    
    // 2. checking a sign as not a number
    if( (str[digit] < '0' || str[digit] > '9') )
    {
        std::cout << "error: signs after digit" << std::endl;
        return -1;
    }
    
    return sign * result;
}

#endif /* string_9_h */
