//
//  string_11.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_11_h
#define string_11_h

int getSize(char* data)
{
    int size = 0;
    
    while(*data++)
    {
        ++size;
    }
    return size;
}

bool isValidLeft(char data) {
    if (data == '{' || data == '[' || data == '(')
    {
        return true;
    }
    
    return false;
}

char getValidLeft(char data) {
    char left = 0;
    switch(data)
    {
        case '{':
            left = '{';
            break;
        case '[':
            left = '[';
            break;
        case '(':
            left = '(';
            break;
    }
    return left;
}

int findClosingRight(char* dataArr, int size) {
    bool found = false;
    int index = 1;
    int leftClosingCnt = 1;
    int rightClosingCnt = 0;
    
    while (index < size)
    {
        if (dataArr[0] == dataArr[index])
        {
            leftClosingCnt++;
        }
        else if (dataArr[0] == getValidLeft(dataArr[index]))
        {
            rightClosingCnt++;
        }
        
        if (leftClosingCnt == rightClosingCnt)
        {
            found = true;
            break;
        }
        index++;
    }
    
    if (!found)
    {
        index = 0;
    }
    
    return index;
}

bool checkBracketsRec(char* data, int size)
{
    if (size == 0)
        return true;
    
    if (isValidLeft(data[0]))
    {
        int index = findClosingRight(data, size);
        
        if (index == size - 1)
        {
            return checkBracketsRec(data + 1, size - 2);
        }
        else if (index == 1)
        {
            return checkBracketsRec(data + 2, size - 2);
        }
        else if (index)
        {
            return checkBracketsRec(data, index + 1) & checkBracketsRec(data + index + 1, size - (index + 1));
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
    return false;
}

bool checkIntegrity(char* scr)
{
    int size = getSize(scr);
    return checkBracketsRec(scr, size);
}

//test
//    
//    char* data = "((([])))";
//    cout << checkIntegrity(data) << endl; // true
//    
//    data = "{[}[]()((})[])]";
//    cout << checkIntegrity(data) << endl; // false
//    
//    data = "{}[]()(()[])";
//    cout << checkIntegrity(data) << endl; // true
//    
//    data = "((()())())";
//    cout << checkIntegrity(data) << endl; // true
//    
//    data = "(((()))(";
//    cout << checkIntegrity(data) << endl; // false
//    
//    data = "{[()]}{[()]}";
//    cout << checkIntegrity(data) << endl; // true

#endif /* string_11_h */
