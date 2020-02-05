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
    Army* createArmy(ArmyBuilder& builder) {
        builder.createArmy();
        builder.buildInfantryMan();
        builder.buildArcher();
        builder.buildHorseMan();
        builder.buildCatapult();
        builder.buildElephant();
        
        return builder.getArmy();
    }
};


#endif /* Builder_h */
