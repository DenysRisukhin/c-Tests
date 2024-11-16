//
//  string_7.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_7_h
#define string_7_h

#pragma mark - a

void reverse(char* str)
{
    if (str == nullptr)
    {
        return;
    }
    
    char* end = str;
    int ctr = 0;
    
    if (str)
    {
        while (*end)
        {
            ++end;
        }
        
        --end;
        
        char tmp;
        
        while (str < end)
        {
            tmp = *str;
            *str = *end;
            *end = tmp;
            
            *str++;
            *end--;
            
            ctr++;
        }
    }
    
    while (ctr > 0)
    {
        *str--;
        ctr--;
    }
    cout << str << endl;
}

#pragma mark - b

void reverse(char* str)
{
    if (str == nullptr)
    {
        return;
    }
    
    int size = strlen(str);
    
    for (int i = 0; i < size/2; i++)
    {
        std::swap(*(str + i), *(str + size - i - 1) );
    }
    
    cout << str << endl;
}

//test
//
//    char str[] = "ituboy";
//    reverse(str);

#endif /* string_7_h */
