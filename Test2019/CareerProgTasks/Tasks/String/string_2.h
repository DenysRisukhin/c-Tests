//
//  string_2.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_2_h
#define string_2_h

//  когда мы выделяем память строки, мы всегда должны помнить, что для хранения управляющего символа требуется дополнительный байт (char[3] c = "abc" даст вам ошибку. Правильный способ сделать это char[4] c = "abc", «abc» эквивалентно «abc \ 0»). Что, как говорится, strlen дает вам «полезную» длину строки без 0 в конце. Таким образом, цикл for выполняет итерацию по всем символам строки, но он также обязательно копирует ‘\ 0’ в конце b, так как это сам символ и foundChar[0] будет ложным до конца.

void removeDublicates(char* strA, char* strB) {
    
    const int ASCII_CHARS = 127;
    bool foundChar[ASCII_CHARS]{false};
    
    int len = strlen(strA);
    int lenb = 0; //b's length(initially 0)
    
    for (int i = 0; i <= len; i++)
    {
        char c = strA[i];
        if (!foundChar[c]) //first char encounter
        {
            strB[lenb] = c;
            lenb++; //we increment it every time we add a character
            foundChar[c] = true; //we found the char
        }
    }
}

//test
//    const int N = 255;
//    char a[N] = "asfsgeda";
//    char b[N]; //output string
//
//    removeDublicates(a, b);
//
//    cout << b << endl;

#endif /* string_2_h */
