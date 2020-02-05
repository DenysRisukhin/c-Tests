//
//  DelegateCocos.h
//  Test2019
//
//  Created by Denys Risukhin on 1/2/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef DelegateCocos_h
#define DelegateCocos_h

using namespace std;

class MathOperationsDelegate {
public:
    virtual void calcultedSum(int res) = 0;
    virtual void calcultedDot(int res) = 0;
};

class MathOperations {
public:
    void setDelegate(MathOperationsDelegate* delegate) {
        m_delegate = delegate;
    }
    
    void sum(int a, int b) {
        auto res = a + b;
        m_delegate->calcultedSum(res);
    }
    
    void dot(int a, int b) {
        auto res = a * b;
        m_delegate->calcultedDot(res);
    }
    
private:
    MathOperationsDelegate* m_delegate;
    
    // если нужно несколько делегатов то
    //map<string, delegate*> delegates;
    // или
    //list<delegate*> delegates;
};

class HomeScreen: public MathOperationsDelegate {
public:
    void calcultedSum(int res) {
        cout << "sum = " << res << endl;
    }
    
    void calcultedDot(int res) {
        cout << "dot = " << res << endl;
    }
};

//int main(int argc, const char * argv[]) {
//    auto homeScreen = new HomeScreen();
//    
//    auto mathOperations = new MathOperations();
//    mathOperations->setDelegate(homeScreen);
//    
//    mathOperations->dot(3, 4);
//    mathOperations->sum(3, 4);
//    
//    delete homeScreen;
//    delete mathOperations;
//    
//    return 0;
//}


#endif /* DelegateCocos_h */
