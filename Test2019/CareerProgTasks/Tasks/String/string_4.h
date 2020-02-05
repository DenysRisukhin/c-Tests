//
//  string_4.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_4_h
#define string_4_h

char* replaceSpace(const char* s) {
    const char* temp = s;
    int spaceCtr = 0;
    
    while(*temp++) {
        if (*temp == ' ') {
            spaceCtr++;
        }
    }
    
    char* result = new char[strlen(s) + 1 + spaceCtr*3];
    char* beginPtrRest = result;
    
    while(*s) {
        if (*s == ' ') {
            *result++ = '%';
            *result++ = '2';
            *result++ = '0';
        } else {
            *result++ = *s;
        }
        *s++;
    }
    
    *result = '\0';
    
    return beginPtrRest;
}

//test
//    char str[] = "IT B o y";
//    cout << replaceSpace(str);
//    cout << endl;

#endif /* string_4_h */
