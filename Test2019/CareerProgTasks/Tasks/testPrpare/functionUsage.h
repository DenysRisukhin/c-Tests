//
//  functionUsage.h
//  Test2019
//
//  Created by Denys Risukhin on 12/10/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef functionUsage_h
#define functionUsage_h

//// a) with functor
//struct AAA
//{
//    float operator() (int x, int y) const { return float(x)/y; }
//};
//
//void testAAA()
//{
//    function<float(int, int)> f = AAA();
//    cout << f(5,3);
//}
//
//// b) with pointers to mathods
//struct BBB
//{
//    int foo(int i) { return i * i; }
//};
//
//void testBBB()
//{
//    function<int(BBB*, int)> f = &BBB::foo;
//    BBB b;
//    f(&b, 5);
//}
//
//int main()
//{
//    // c) with lymbda
//    //    for lymbda auto better then function
//    function<int(int, int)> f = [](int x, int y) { return x+ y; };
//    
//    return 0;
//}

#endif /* functionUsage_h */
