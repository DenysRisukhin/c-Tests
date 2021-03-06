//
//  Global_logic_task.h
//  Test2019
//
//  Created by Denys Risukhin on 12/8/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Global_logic_task_h
#define Global_logic_task_h

class Foo
{
public:
    Foo(int val = 0): mBar(val) {} // fix: c-tor (c_tor and c-tor) by default added
    
    int getBar()
    {
        return mBar;
    }
    
    void setBar(int bar)  // fix: return type edded
    {
        mBar = bar;
    }

private:
    int mBar;
};


// fix: approach 1
// weak side: we must release memory in main()
//Foo* make_foo(int val) // fix: correct argument added
//{
//    Foo* ptr = new Foo;
//    ptr->setBar(val);
//    return ptr;
//}

// fix: approach 2
// be carefully: we cant use &
// std::shared_ptr<Foo>& make_foo(int val)
// because ptr - local variable, so we will get memory leak
// we can't use links or pointers here as return value
std::shared_ptr<Foo> make_foo(int val) // fix: correct argument added
{
    std::shared_ptr<Foo> ptr = std::make_shared<Foo>();
    ptr->setBar(val);
    
    return ptr;
}

void bar(Foo* foo) // fix: correct argument - pointer
{
    foo->setBar(10);
}

//int main()
//{
////    // fix: approach 1
////    Foo* foo1 = make_foo(10); // fix memory leak
////    cout << foo1->getBar() << endl;
////    delete foo1;
//
//    // fix: approach 2
//    std::shared_ptr<Foo> foo1 = make_foo(10); // fix memory leak
//    cout << foo1->getBar() << endl;
//
//    Foo* foo2 = new Foo();
//    cout << foo2->getBar() << endl; // print: 0
//
//    bar(foo2);
//    cout << foo2->getBar() << endl; // print: 10
//
//    delete foo2; // fix: dynamic memory realesed
//
//    return 0; // fix: added return
//}

#endif /* Global_logic_task_h */
