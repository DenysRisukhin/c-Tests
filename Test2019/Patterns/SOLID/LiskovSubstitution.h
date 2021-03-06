//
//  LiskovSubstitution.h
//  Test2019
//
//  Created by Denys Risukhin on 1/1/21.
//  Copyright © 2021 DenysRisukhin. All rights reserved.
//

#ifndef LiskovSubstitution_h
#define LiskovSubstitution_h

//Liskov substitution principle
//If S is a subtype of T, then objects of type T in a program may be replaced with objects of type S without altering any of the desirable properties of that program (e.g. correctness)

// ex 1:

struct InertialMeasurementUnit {
   virtual ~InertialMeasurementUnit() = default;
   virtual int getOrientation()       = 0;
};
struct Gyroscope : public InertialMeasurementUnit {
   /**
    * @return orientation in degrees [0, 360)
    */
   int getOrientation() override;
};
struct Accelerometer : public InertialMeasurementUnit {
   /**
    * @return orientation in degrees [-180, 180)
    */
   int getOrientation() override;
};

// fix var 1:

struct InertialMeasurementUnit {
   virtual ~InertialMeasurementUnit() = default;
   /**
    * Sets the frequency of measurements
    * @param frequency (in Hertz)
    * @return Whether frequency was valid
    */
   virtual bool setFrequency(double frequency) = 0;
};
struct Gyroscope : public InertialMeasurementUnit {
   // Valid range [0.5, 10]
   bool setFrequency(double frequency) override;
};
struct Accelerometer : public InertialMeasurementUnit {
   // Valid range [0.1, 100]
   bool setFrequency(double frequency) override;
};

// fix var 2:

struct InertialMeasurementUnit {
   virtual ~InertialMeasurementUnit() = default;
   /**
    * Sets the frequency of measurements
    * @param frequency (in Hertz)
    * @throw std::out_of_range exception if frequency is invalid
    */
   virtual void setFrequency(double frequency) = 0;

   /**
    * Provides the valid measurement range
    * @return <minimum frequency, maximum frequency>
    */
   virtual pair<double, double> getFrequencyRange() const = 0;
};

#endif /* LiskovSubstitution_h */
