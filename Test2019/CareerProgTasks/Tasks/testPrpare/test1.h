//
//  Header.h
//  Test2019
//
//  Created by Denys Risukhin on 12/10/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef test1_h
#define test1_h

//
//int getTestVal_1()
//{
//    int i = 0;
//    return i += ++i++ + ++i++ + i++;
//}

int getTestVal_2()
{
    int i = 0;
    return i += ++i + i++ + ++i;
}

int getTestVal_3()
{
    int i = 9;
    return i += i + i++ + ++i;
}

int getTestVal_4()
{
    int i = 5;
    return i += i++ + i++ + ++i;
}

int getTestVal_5()
{
    int i = 0;
    return i += i++ + i++ + i++;
}

int getTestVal_6()
{
    int i = 0;
    return i = ++i + ++i;
}

int getTestVal_7()
{
    int i = 0;
    return i = i + ++i;
}

//int main()
//{
//
//    //cout << getTestVal_1() << endl;
//    cout << getTestVal_2() << endl;
//    cout << getTestVal_3() << endl;
//    cout << getTestVal_4() << endl;
//    cout << getTestVal_5() << endl;
//    cout << getTestVal_6() << endl;
//    cout << getTestVal_7() << endl;
//
//    return 0; 
//}


#endif /* Header_h */
