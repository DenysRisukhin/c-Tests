//
//  Observer2.h
//  Test2019
//
//  Created by Denys Risukhin on 1/2/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Observer2_h
#define Observer2_h

#include <iostream>
#include <vector>

using namespace std;

class Listener
{
public:
    virtual void onEvent(string msg) = 0;
};

class Publisher
{
public:
    
    void addListener(Listener* listener)
    {
        m_listeners.push_back(listener);
    }
    
    void publishEvent(string msg)
    {
        for (auto listener: m_listeners)
        {
            listener->onEvent(msg);
        }
    }
    
    void doSomething()
    {
        publishEvent("Hello");
    }
    
private:
    vector<Listener*> m_listeners;
    
};

class ListenerA: Listener
{
public:
    
    ListenerA(Publisher& p)
    {
        p.addListener(this);
    }
    
    void onEvent(string msg) override
    {
        cout << "ListenerA reporting in. The publisher said " << msg << endl;
    }
};

class ListenerB: Listener
{
public:
    
    ListenerB(Publisher& p)
    {
        p.addListener(this);
    }
    
    void onEvent(string msg) override
    {
        cout << "ListenerB reporting in. The publisher said " << msg << endl;
    }
};

// tests
//Publisher p;
//
//ListenerA* aPtr = new ListenerA(p);
//ListenerB* bPtr = new ListenerB(p);
//
//p.doSomething();
//
//delete aPtr;
//delete bPtr;

#endif /* Observer2_h */
