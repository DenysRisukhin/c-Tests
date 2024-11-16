//
//  string_5.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_5_h
#define string_5_h

void compactString(char* str)
{
    char* cpy = str;
    
    while (*cpy != '\0')
    {
        if (*str != ' ')
        {
            *cpy++ = *str;
        }
        
        *str++;
    }
    
    *cpy = '\0';
}

//test
//
//    char str[] = "IT B o y";
//    compactString(str);
//    cout << str << endl;

#endif /* string_5_h */
