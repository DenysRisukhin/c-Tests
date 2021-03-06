//
//  OpenClosed.h
//  Test2019
//
//  Created by Denys Risukhin on 1/1/21.
//  Copyright © 2021 DenysRisukhin. All rights reserved.
//

#ifndef OpenClosed_h
#define OpenClosed_h

//Open/closed principle ( best way - polymorphism)
//Software entities should be open for extension, but closed for modification

//This allows new functionality to be added without changing existing source code.

// ex 1

enum class SensorModel {
   Good,
   Better
};

struct DistanceSensor {
   DistanceSensor(SensorModel model) : mModel{model} {}
   int getDistance() {
       switch (mModel) {
           case SensorModel::Good :
               // Business logic for "Good" model
           case SensorModel::Better :
               // Business logic for "Better" model
       }
   }
};

// ex 1: fix

struct DistanceSensor {
   virtual ~DistanceSensor() = default;
   virtual int getDistance() = 0;
};

struct GoodDistanceSensor : public DistanceSensor {
   int getDistance() override {
       // Business logic for "Good" model
   }
};

struct BetterDistanceSensor : public DistanceSensor {
   int getDistance() override {
       // Business logic for "Better" model
   }
};

#endif /* OpenClosed_h */
