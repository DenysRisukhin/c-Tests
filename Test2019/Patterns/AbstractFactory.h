//
//  AbstractFactory.h
//  Test2019
//
//  Created by Denys Risukhin on 8/9/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef AbstractFactory_h
#define AbstractFactory_h

#include <iostream>
#include <vector>

// AbstractFactory Test
// 1. When do we need it to use?
// 2. What is the target? (families & group objectss)
// 3. Give and explaine 3 examples:
//    - multiplafrorm app which supports different UI for ios & android;
//    - text editor which supports multilangueges and special lexical blocks for each one language;
//    - Rome & Carfagen armies. Group of objects: archer, horseman, infantryman;
// 3. What is the main classes of abstract factory. Draw the scheme.
// 4. What is advantages and disadvantages?

// PS In first task we save all our objects in special class Army, in the second task in class ArmyFactory
// 5. Technical tasks:
//  5.1 Create Rome & Carfagen armies.
//      - Objects : archer, horseman, infantryman;
//      - armies creation can be from class Game;

//          Objects             : archer, horseman, infantryman;
//          General class Army  : consist all objects;
//          Abstract Product    : romeArcher, romeHorseman, romeInfantryman
//                                CarfagenArcher, CarfagenHorseman, CarfagenInfantryman
//          Abstract Factory    : ArmyFactory
//          ArmyFactory         : RomanArmyFactory, CarfagenArmyFactory;
//          Creations           : from any place. class Game;

//  5.2 Create functionality which accept to creates fighting units for different gaming race.
//      5.1 Units can create by 2 approaches:
//         - by barracks;
//         - by reinforcement(пополнение) (при помощи активации квестовых тригеров);
//      5.2 Due to gaming balace changes, fotman for human race must creates two units for one creation;
//      5.3 This changes must work only for barracks;
//          Objects         : footman, archer;
//          Abstract Product: humanFootman, HumanArcher, orcFootman, orcHumanArcher;
//          Abstract Factory: ArmyFactory
//          ArmyFactory     : HumanArmyFactory, OrcArmyFactory;
//          Creations       : barracks, reinforcement;

#pragma mark - test

//Game game;
//RomanArmyFactory r_factory;
//CarthaginArmyFactory c_factory;
//
//Army* ra = game.createArmy(r_factory);
//Army* ca = game.createArmy(c_factory);
//ra->info();
//ca->info();
//delete ra;
//delete ca;

#pragma mark - Game

//class Game {
//public:
//    Army* createArmy(ArmyFactory& factory) {
//        Army* p = new Army;
//        p->vi.push_back(factory.createInfantryMan());
//        p->va.push_back(factory.createArcher());
//        p->vh.push_back(factory.createHorseMan());
//        return p;
//    }
//};

#pragma mark - Army General class

//class Army {
//public:
//    void info() {
//        for(auto i = 0; i < vi.size(); ++i) {
//            vi[i]->info();
//        }
//
//        for(auto i = 0; i < va.size(); ++i) {
//            va[i]->info();
//        }
//
//        for(auto i = 0; i < vh.size(); ++i) {
//            vh[i]->info();
//        }
//    }
//
//    ~Army() {
//        for(auto i = 0; i < vi.size(); ++i) {
//            delete vi[i];
//        }
//
//        for(auto i = 0; i < va.size(); ++i) {
//            delete va[i];
//        }
//
//        for(auto i = 0; i < vh.size(); ++i) {
//            delete vh[i];
//        }
//    }
//
//    std::vector<InfantryMan*> vi;
//    std::vector<Archer*> va;
//    std::vector<HorseMan*> vh;
//};

#pragma mark - step 1

//class InfantryMan {
//public:
//    virtual void info() = 0;
//    virtual ~InfantryMan() {}
//};
//
//class Archer {
//public:
//    virtual void info() = 0;
//    virtual ~Archer() {}
//};
//
//class HorseMan {
//public:
//    virtual void info() = 0;
//    virtual ~HorseMan() {}
//};
//
#pragma mark - Roman
//
//class RomanInfantryMan: public InfantryMan {
//    public:
//    void info() { std::cout << "RomanInfantryMan" <<std::endl; }
//};
//
//class RomanArcher: public Archer {
//    public:
//    void info() { std::cout << "RomanArcher" <<std::endl; }
//};
//
//class RomanHorseMan: public HorseMan {
//    public:
//    void info() { std::cout << "RomanHorseMan" <<std::endl; }
//};
//
#pragma mark - Carthagin
//
//class CarthaginInfantryMan: public InfantryMan {
//    public:
//    void info() { std::cout << "CarthaginInfantryMan" <<std::endl; }
//};
//
//class CarthaginArcher: public Archer {
//    public:
//    void info() { std::cout << "CarthaginArcher" <<std::endl; }
//};
//
//class CarthaginHorseMan: public HorseMan {
//    public:
//    void info() { std::cout << "CarthaginHorseMan" <<std::endl; }
//};

#pragma mark - FACTORY BLOCK

#pragma mark - Army Abstract Factory

//class ArmyFactory {
//public:
//    virtual InfantryMan* createInfantryMan() = 0;
//    virtual Archer* createArcher() = 0;
//    virtual HorseMan* createHorseMan() = 0;
//    
//    ~ArmyFactory() {}
//};

#pragma mark - Roman Army Abstract Factory

//class RomanArmyFactory: public ArmyFactory {
//public:
//    InfantryMan* createInfantryMan() {
//        return new RomanInfantryMan;
//    }
//    
//    Archer* createArcher(){
//        return new RomanArcher;
//    }
//    
//    HorseMan* createHorseMan(){
//        return new RomanHorseMan;
//    }
//};

#pragma mark - Carthagin Army Abstract Factory

//class CarthaginArmyFactory: public ArmyFactory {
//public:
//    InfantryMan* createInfantryMan() {
//        return new CarthaginInfantryMan;
//    }
//    
//    Archer* createArcher(){
//        return new CarthaginArcher;
//    }
//    
//    HorseMan* createHorseMan(){
//        return new CarthaginHorseMan;
//    }
//};


/////////////////////////
// example 2

class Footman {
public:
    Footman(){}
    virtual ~Footman() {}
};

// разведчик
class Scout {
public:
    Scout(){}
    virtual ~Scout() {}
};

#pragma mark - step 2

class HumanFootman: public Footman {
public:
};

class HumanScout: public Scout {
public:
};

class OrcFootman: public Footman {
public:
};

class OrcScout: public Scout {
public:
};

#pragma mark - step 3

class ArmyFactory {
public:
    virtual void addFootman() = 0;
    virtual void addScout() = 0;
    
protected:
    std::vector<Footman*> m_footmanContainer;
    std::vector<Scout*> m_scoutContainer;
};

class HumanArmyFactory: public ArmyFactory {
public:
    void addFootman() {
        m_footmanContainer.push_back(new HumanFootman);
    }
    
    void addScout() {
        m_scoutContainer.push_back(new HumanScout);
    }
};

class OrcArmyFactory: public ArmyFactory {
public:
    void addFootman() {
        m_footmanContainer.push_back(new OrcFootman);
    }
    
    void addScout() {
        m_scoutContainer.push_back(new OrcScout);
    }
    
};

#pragma mark - Human Army Factory Extended

class HumanArmyFactoryExtended: public HumanArmyFactory {
public:
    void addFootman() {
        HumanArmyFactory::addFootman();
        m_footmanContainer.push_back(new OrcFootman);
    }
    
    void addScout() {
        m_scoutContainer.push_back(new OrcScout);
    }
};

#pragma mark - creation step 4

class Baracks
{
    virtual void init(ArmyFactory) = 0;
    
    void createFootman();
    void createScout();
};

class Reinforcement
{
    virtual void init(ArmyFactory) = 0;
    
    void createFootman();
    void createScout();
};

#endif /* AbstractFactory_h */
