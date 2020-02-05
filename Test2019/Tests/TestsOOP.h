//
//  TestsOOP.h
//  Test2019
//
//  Created by Denys Risukhin on 1/6/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef TestsOOP_h
#define TestsOOP_h

#pragma mark - 1

class Vehicle {
public:
    float weight = 0.f;
    void driven() {}
};

class ForWater: public Vehicle {
public:
    void waves() {}
};

class ForLand: public Vehicle {
public:
    void holes() {}
};

class BothWaterAndLand: public ForWater, public ForLand {
public:
    void setWeight() {  ((ForLand*)this)->weight = 0.f; }
};

#pragma mark - 2

#endif /* TestsOOP_h */
