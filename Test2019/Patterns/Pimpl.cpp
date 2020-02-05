//
//  Pimpl.cpp
//  Test2019
//
//  Created by Denys Risukhin on 1/1/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#include "Pimpl.hpp"

#pragma mark - Private class

class TestPimpl::Private
{
public:
    explicit Private(TestPimpl* backLink = nullptr): m_backLink(backLink) {}
    
    void setNum(double num) { m_num = num; }
    
    bool isAccept(double num) const { return num != 0; }
    
    // backLink usage
    void callTestPimplPublicMethods() { m_backLink->someMethod(2); }
    
private:
    TestPimpl* const m_backLink = nullptr;
    
    double m_num;
};

#pragma mark - TestPimpl class

TestPimpl::TestPimpl()
    : m_dPtr(new Private(this))
{

}

TestPimpl::~TestPimpl()
{
    delete m_dPtr;
}

void TestPimpl::someMethod(double num)
{
    if (m_dPtr->isAccept(num))
    {
        m_dPtr->setNum(num);
    }
}
