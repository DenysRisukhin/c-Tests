//
//  InterfaceSegregation.h
//  Test2019
//
//  Created by Denys Risukhin on 1/1/21.
//  Copyright © 2021 DenysRisukhin. All rights reserved.
//

#ifndef InterfaceSegregation_h
#define InterfaceSegregation_h

//Interface segregation principle
//No client should be forced to depend on methods it does not use

// ex 1:
struct Runtime {
   virtual ~Runtime() = default;
   virtual void sendViaI2C(vector<byte> bytesToSend) = 0;
   virtual vector<byte> readViaI2C(int numberOfBytesToRead) = 0;

   virtual void sendViaUART(vector<byte> bytesToSend) = 0;
   virtual vector<byte> readViaUART(int numberOfBytesToRead) = 0;

   virtual void setPinDirection(int p, PinDirection d) = 0;
   virtual void setPin(int pin) = 0;
   virtual void clearPin(int pin) = 0;
};

// ex 2:
struct SerialManager {
  virtual ~Manager() = default;
  virtual void registerReceiver(function<void(string)> receiver) = 0;
  virtual void send(string message) = 0;
  virtual void readLine() = 0;
};

struct MySerialManager : public SerialManager {
  void registerReceiver(function<void(string)> receiver) override;
  void send(string message) override;
  void readLine() override;
};

// ex 2 fix
struct SerialClient {
  virtual ~SerialClient() = default;
  virtual void registerReceiver(function<void(string)> receiver) = 0;
  virtual void send(string message) = 0;
}

struct SerialReader {
  virtual ~SerialReader() = default;
  virtual void readLine() = 0;
};

struct MySerialManager : public SerialClient, public SerialReader {
  void registerReceiver(function<void(string)> receiver) override;
  void send(string message) override;
  void readLine() override;
};

#endif /* InterfaceSegregation_h */
