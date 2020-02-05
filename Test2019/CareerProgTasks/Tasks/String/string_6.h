//
//  string_6.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_6_h
#define string_6_h

#pragma mark - a

string sort(string str)
{
    std::sort(str.begin(), str.end());
    return str;
}

bool isPermutation(string strA, string strB) {
    
    if (strA.size() != strB.size())
    {
        return false;
    }
    
    return sort(strA) == sort(strB);
}

#pragma mark - b

bool isPermutation(string strA, string strB) {
    
    if (strA.size() != strB.size())
    {
        return false;
    }
    
    int letters[128]{};
    
    for (char c: strA)
    {
        letters[c]++;
    }
    
    for (int i = 0; i < strB.length(); i++)
    {
        int c = (int)strB[i];
        letters[c]--;
        if (letters[c] < 0)
        {
            return false;
        }
    }
    return true;
}

//test
//    cout << isPermutation("abvd", "dabc") << endl;

#endif /* string_6_h */
