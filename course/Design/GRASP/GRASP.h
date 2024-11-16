//
//  GRASP.h
//  Test2019
//
//  Created by Risukhin Denys on 1/28/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef GRASP_h
#define GRASP_h

// GRASP (General Responsibility Assignment Software Patterns/Шаблон программного обеспечения для общего распределения ответственности)
// is a set of nine principles that help in designing object-oriented software. These principles guide designers in assigning responsibilities to classes and objects in a way that promotes loose coupling and high cohesion. While GRASP is not specific to any programming language, you can certainly apply its principles when designing classes and objects in C++.

// Applying these principles in your C++ code will lead to a more modular, maintainable, and flexible design. Remember that these principles are guidelines, and their application might vary depending on the specifics of your software design.

// 9 GRASP principles:

//1 Information Expert:
//Assign a responsibility(відповідальність) to the class that has the information needed to fulfill that responsibility.
//In C++, this often means assigning a responsibility to the class that has access to the required data or methods.

class Student
{
private:
    std::string name;
    int age;
public:
    // ... constructor, getters, setters ...

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

class StudentProcessor {
public:
    void processStudentInfo(const Student& student) {
        // Use information from Student class
        std::cout << "Processing student: " << student.getName() << ", Age: " << student.getAge() << std::endl;
        // ... other processing logic
    }
};


//2 Creator:
//Assign the responsibility for creating an instance of class A to class B if one of the following is true:
//B "contains" A objects.
//B "uses" A objects.
//B has the initializing data for A.

class Car {
    // ... car properties and methods ...
};

class CarFactory {
public:
    Car createCar() {
        // Initialize and configure Car object
        Car car;
        // ... additional setup ...
        return car;
    }
};

//3 Controller:
//Assign the responsibility for handling system events to a controller class.
//In C++, this could be a class that manages the flow of control in a system.

class UserController {
public:
    void handleUserInput() {
        // Code to handle user input events
        // ...
    }
};


//4 Low Coupling(Низьке зчеплення):
//Assign responsibilities to minimize dependencies between classes.
//In C++, use interfaces, abstract classes, and dependency injection to achieve low coupling.

class Logger {
public:
    void log(const std::string& message) {
        // Log message
        std::cout << message << std::endl;
    }
};

class UserManager {
private:
    Logger& logger; // Dependency on Logger class
public:
    UserManager(Logger& logger) : logger(logger) {}

    void addUser(const std::string& username) {
        // ... add user logic ...
        logger.log("User added: " + username);
    }
};


//5 High Cohesion(Висока сплоченність):
//Assign responsibilities so that cohesion remains high.
//Cohesion refers to how closely the members of a class are related to its responsibility.

class FileParser {
public:
    void parseConfigurationFile(const std::string& filePath) {
        // ... parse file logic ...
    }

    void parseUserDataFile(const std::string& filePath) {
        // ... parse file logic ...
    }
};


//6 Polymorphism:
//Assign a responsibility so that it can be implemented using polymorphism.
//In C++, this often involves using virtual functions and interfaces.

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}

    double calculateArea() const override {
        return side * side;
    }
};


//7 Pure Fabrication:
//Introduce a class that does not represent a concept in the problem domain but is designed to achieve low coupling, high cohesion, and reuse.
//This is more about creating classes for design reasons rather than representing real-world entities.

class DataStorage {
public:
    void saveData(const std::string& data) {
        // ... save data logic ...
    }
};

class DataManager {
private:
    DataStorage storage;
public:
    void processData(const std::string& data) {
        // ... process data logic ...
        storage.saveData(data);
    }
};


//8 Indirection:
//Assign a responsibility to an intermediate object to mediate between other components or services to reduce the coupling between them.

class PaymentProcessor {
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCardPaymentProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        // ... credit card payment logic ...
    }
};

class PaymentGateway {
private:
    PaymentProcessor& processor;
public:
    PaymentGateway(PaymentProcessor& p) : processor(p) {}

    void makePayment(double amount) {
        // ... additional processing ...
        processor.processPayment(amount);
    }
};


//9 Protected Variations:
//Shield elements from variations(Елементи щита від варіацій) in other elements by encapsulating the volatile concepts (непостійні поняття).
//(Защитите элементы от вариаций других элементов, инкапсулируя изменчивые концепции.)

class DatabaseConnector
{
public:
    virtual void connect() = 0;
    virtual void disconnect() = 0;
};

class MySQLDatabaseConnector : public DatabaseConnector {
public:
    void connect() override {
        // ... MySQL specific connection logic ...
    }

    void disconnect() override {
        // ... MySQL specific disconnection logic ...
    }
};

class DatabaseManager
{
private:
    DatabaseConnector& connector;
public:
    DatabaseManager(DatabaseConnector& c) : connector(c) {}

    void performDatabaseOperation() {
        connector.connect();
        // ... perform database operation ...
        connector.disconnect();
    }
};


#endif /* GRASP_h */
