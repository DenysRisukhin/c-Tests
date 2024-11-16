//
//  string_10.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_10_h
#define string_10_h

bool isSubstring(const std::string &source, const string& lexeme)
{
    for (int pos = 0; pos < source.size(); pos++)
    {
        int val = source.find(lexeme, pos);
        if (val != -1)
        {
            return true;
        }
    }
    return false;
}

bool isFoundLexeme(string source, string lexeme)
{
    
    bool isFound = false;
    
    if (source.size() == lexeme.size() && source.size() > 0)
    {
        const std::string& generalStr = source + source;
        isFound = isSubstring(generalStr, lexeme);
    }
    
    return isFound;
}

//    test
//
//    string sourceStr = "erbottlewat";
//    string lexemeStr = "waterbottle";
//    cout << isFoundLexeme(sourceStr, lexemeStr) << endl;

#endif /* string_10_h */
