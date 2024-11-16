//
//  Builder.h
//  Test2019
//
//  Created by Denys Risukhin on 8/10/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Builder_h
#define Builder_h

#include <iostream>
#include <vector>

//1. Complex Object Construction:
//Use the builder pattern when you need to construct complex objects with multiple components or parameters. This pattern separates the construction of a complex object from its representation, allowing you to create different variations of the same object.
//2. Step-by-Step Construction:
//When an object needs to be constructed in a step-by-step manner, and you want to control the construction process. The builder pattern provides a way to gradually construct an object, setting its various parameters or components at different stages.
//3. Immutable Objects:
//If you want to create immutable objects (objects whose state cannot be modified after construction), the builder pattern is a good choice. It allows you to set the parameters during construction and ensures that the object is in a valid and consistent state when it is created.
//4. Fluent Interface:
//When you want to provide a fluent and expressive interface for constructing objects. The builder pattern can be implemented in a way that allows method chaining, making the code more readable and concise when setting multiple parameters.

#pragma mark - step 1

class InfantryMan {
public:
    void info() { std::cout << "InfantryMan" << std::endl; }
};

class Archer {
public:
    void info() { std::cout << "Archer" << std::endl; }
};

class HorseMan {
public:
    void info() { std::cout << "HorseMan" << std::endl; }
};

class Catapult {
public:
    void info() { std::cout << "Archer" << std::endl; }
};

class Elephant {
public:
    void info() { std::cout << "Elephant" << std::endl; }
};

#pragma mark - step 2

class Army {
public:
    void info() {
        for(auto i = 0; i < vi.size(); ++i) {
            vi[i]->info();
        }
        
        for(auto i = 0; i < va.size(); ++i) {
            va[i]->info();
        }
        
        for(auto i = 0; i < vh.size(); ++i) {
            vh[i]->info();
        }
        
        for(auto i = 0; i < vc.size(); ++i) {
            vc[i]->info();
        }
        
        for(auto i = 0; i < ve.size(); ++i) {
            ve[i]->info();
        }
    }
    
    ~Army() {
        for(auto i = 0; i < vi.size(); ++i) {
            delete vi[i];
        }
        
        for(auto i = 0; i < va.size(); ++i) {
            delete va[i];
        }
        
        for(auto i = 0; i < vh.size(); ++i) {
            delete vh[i];
        }
        
        for(auto i = 0; i < vc.size(); ++i) {
            delete vc[i];
        }
        
        for(auto i = 0; i < ve.size(); ++i) {
            delete ve[i];
        }
    }
    
    std::vector<InfantryMan*> vi;
    std::vector<Archer*> va;
    std::vector<HorseMan*> vh;
    std::vector<Catapult*> vc;
    std::vector<Elephant*> ve;
};

#pragma mark - step 3

class ArmyBuilder {
public:
    ArmyBuilder(): p(nullptr) {}
    
   // ArmyBuilder() {}
    
    virtual void createArmy() {}
    virtual Army* getArmy() { return p; }
    
    virtual void buildInfantryMan() {}
    virtual void buildArcher() {}
    virtual void buildHorseMan() {}
    virtual void buildCatapult() {}
    virtual void buildElephant() {}
    
protected:
    Army* p = nullptr;
};

class RomanArmyBuilder: public ArmyBuilder {
public:
    void createArmy() { p = new Army; }
    
    void buildInfantryMan() { p->vi.push_back(new InfantryMan()); }
    void buildArcher()      { p->va.push_back(new Archer()); }
    void buildHorseMan()    { p->vh.push_back(new HorseMan()); }
    void buildCatapult()    { p->vc.push_back(new Catapult()); }
};

class CarthaginArmyBuilder: public ArmyBuilder {
public:
    void createArmy() { p = new Army; }
    
    void buildInfantryMan() { p->vi.push_back(new InfantryMan()); }
    void buildArcher()      { p->va.push_back(new Archer()); }
    void buildHorseMan()    { p->vh.push_back(new HorseMan()); }
    void buildElephant()    { p->ve.push_back(new Elephant()); }
};

#pragma mark - step 4

class Director {
public:
    Army* createArmy(ArmyBuilder& builder)
    {
        builder.createArmy();

        builder.buildInfantryMan();
        builder.buildArcher();
        builder.buildHorseMan();
        builder.buildCatapult();
        builder.buildElephant();
        
        return builder.getArmy();
    }
};

#pragma mark - tests

//Director dir;
//RomanArmyBuilder romanBuilder;
//CarthaginArmyBuilder carBuilder;
//Army* roman = dir.createArmy(romanBuilder);
//Army* car = dir.createArmy(carBuilder);
//
//std::cout << "roman army" << std::endl;
//roman->info();
//
//std::cout << "carthagin army" << std::endl;
//car->info();


#endif /* Builder_h */
