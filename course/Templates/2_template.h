//
//  2_template.h
//  Test2019
//
//  Created by Risukhin Denys on 3/28/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef __template_h
#define __template_h

template<typename T>
class A
{
public:
    A() { cout << ++a; }
    
private:
    static int a;
};

template<typename T>
int A<T>::a = 0;

//int main()
//{
//    A<int> obj1;
//    A<int> obj2;
//    A<char> obj3;
//    A<double> obj4;
//
//    return 0;
//}

#endif /* __template_h */
