//
//  Transaction.hpp
//  Test2019
//
//  Created by Denys Risukhin on 12/26/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Transaction_hpp
#define Transaction_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class CSomeClass{
public:
    int x;
    int y;
    
    void print() { std::cout << x << " " << y << std::endl; }
};

// Его оплетка: smart-pointer с поддержкой отмены.
class CSimpleTr{
public:
    CSomeClass* that;        // текущее значение
    CSomeClass* previos;    // предыдущее значение
public:
    // конструктор-деструктор-присваивание-копирование
    CSimpleTr():previos(NULL), that(new CSomeClass) {
        
    };
    
    CSimpleTr(const CSimpleTr& _st): previos(NULL) {
        
        //  that(new CSomeClass(*(_st.that)))
        
        that = new CSomeClass();
        that->x = _st.that->x;
        that->y = _st.that->y;
        
    };
    
    ~CSimpleTr(){delete that; delete previos;};
    
    CSimpleTr& operator=(const CSimpleTr& _st)
    {
        if (this != &_st)
        {
            delete that;
            //that = new CSomeClass(*(_st.that));
            that = new CSomeClass();
            that->x = _st.that->x;
            that->y = _st.that->y;
            
        }
        return *this;
    };
    // начало транзакции
    void BeginTrans()
    {
        delete previos;
        previos = that;
        //that = new CSomeClass(*previos);
        
        that = new CSomeClass();
        that->x = previos->x;
        that->y = previos->y;
        
        
    };
    // закрепление
    void Commit ()
    {
        delete previos;
        previos = NULL;
    };
    // отмена транзакции
    void Rollback()
    {
        if (previos != NULL)
        {
            delete that;
            that = previos;
            previos = NULL;
        }
    };
    // реализация указателя
    CSomeClass* operator->() {return that;}
};

// test

//CSimpleTr lvPair;
//lvPair->x = 5;
//lvPair->y = 8;
//lvPair->print();
//lvPair.BeginTrans();
//lvPair->x = 7;
//lvPair->y = 11;
//lvPair->print();
//lvPair.Rollback();
//lvPair->print();
//lvPair.BeginTrans();
//lvPair->x = 7;
//lvPair->y = 11;
//lvPair.Commit();

#endif /* Transaction_hpp */

