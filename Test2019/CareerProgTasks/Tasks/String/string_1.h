//
//  string_1.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_1_h
#define string_1_h

string compress(string text)
{
    string resStr;
    int i = 0;
    int ctr = 0;
    
    while (text[i] != '\0')
    {
        if (text[i] != text[i+1]) {
            if (!ctr)
            {
                resStr += text[i];
            }
            else
            {
                string sCtr = to_string(ctr + 1);
                resStr += sCtr + text[i];
            }
            i++;
            ctr = 0;
        }
        else
        {
            i++;
            ctr++;
        }
    }
    return resStr;
}

//test
//    cout << compress("AABBBCCCCCADDDD") << endl;

#endif /* string_1_h */
