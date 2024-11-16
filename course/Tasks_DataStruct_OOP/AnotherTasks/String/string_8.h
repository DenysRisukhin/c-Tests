//
//  string_8.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_8_h
#define string_8_h

// TO DO LIST

// add optimization:
// example
// https://github.com/pnowaczyk/itoa/blob/master/itoa.c
// https://github.com/DevDocuments/bconv/blob/master/bconv.c

// TO DO
// platform support 32 64 bit

// add checks:
//   if 1-st digit 0 : 03636
//   if val doesn't init
//   if buff doesn't init

// @@@@@@@@@@@@@@@@@@@@@@

// Created by ITBoy

// Algorithm Steps:

// 1. check negative sign;
// 2. get digits one by one & convert to ascii and then store;
// 3. reverse digits in buffer;

// Tests:

// long val = 5557;
// char buff[32];
// i_itoa(val, buff);
// std::cout << "i_itoa result: " << buff << std::endl;

void i_itoa(long val, char* buf)
{
    // init
    unsigned curDigit = 0;
    
    char* traversStrPtr = nullptr;
    char* firstDigitPtr = nullptr;
    
    char temp;
    
    traversStrPtr = buf;
    
    // 1. check negative sign
    if (val < 0)
    {
        val = (unsigned long)(-val);
        *traversStrPtr++ = '-';
    }
    
    // save pointer to 1-st digit
    firstDigitPtr = traversStrPtr;
    
    // 2. get digits one by one & convert to ascii and then store
    do
    {
        curDigit = (unsigned)(val % 10);
        val /= 10;
        
        // convert to ascii and store
        if (curDigit <= 9)
        {
            *traversStrPtr++ = (char)(curDigit + '0');
        }
    } while(val > 0);
    
    *traversStrPtr-- = '\0';
    
    // 3. reverse digits in buffer
    //      - repeat until halfway;
    do {
        temp = *traversStrPtr;
        *traversStrPtr = *firstDigitPtr;
        *firstDigitPtr = temp;
        
        --traversStrPtr;
        
        // advance to next two digits
        ++firstDigitPtr;
    } while(firstDigitPtr < traversStrPtr);
    // repeat until halfway
}

#endif /* string_8_h */
