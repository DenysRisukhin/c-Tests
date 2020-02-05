//
//  string_3.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef string_3_h
#define string_3_h

#pragma mark - a

#pragma mark - b

bool isUnique(string str) {
    bool charSet[256] {false};
    
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        
        if (charSet[val])
        {
            return true;
        }
        
        charSet[val] = true;
    }
    
    return false;
}

//test
//    char str[] = "itboty";
//    cout << isUnique(str);

#endif /* string_3_h */
