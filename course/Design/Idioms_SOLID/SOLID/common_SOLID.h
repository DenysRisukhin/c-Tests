//
//  SOLID.h
//  Test2019
//
//  Created by Risukhin Denys on 1/11/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef SOLID_h
#define SOLID_h

#include <iostream>
#include <string>

//1. Single Responsibility Principle (SRP): A class should have only one reason to change, meaning it should have only one responsibility or job.

//2. Open-Closed Principle (OCP): Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
//   This means that you should be able to add new functionality without changing the existing code.

//3. Liskov Substitution(Замена) Principle (LSP): Subtypes must be substitutable for(замінний для) their base types without affecting the correctness of the   program.
//  In other words, objects of a derived class should be able to replace objects of the base class without causing errors or unexpected behavior.
//  A derived class should be able to replace a base class without affecting the functionality of the program. If replacing a base class with a derived class breaks functionality or changes expected behavior, then it violates LSP.

//4. Interface Segregation(разделение) Principle (ISP): Clients should not be forced to depend on interfaces they do not use. Instead of one large interface,  it's better to have multiple smaller interfaces.

//5. Dependency Inversion Principle (DIP): High-level modules should not depend on low-level modules. Both should depend on abstractions (interfaces).
//   Abstractions should not depend on details; details should depend on abstractions.

// 1. SRP: Class has a single responsibility - to represent a person's data.
class Person
{
public:
    Person(const std::string& name, int age) : name(name), age(age) {}
    
    const std::string& getName() const { return name; }
    int getAge() const { return age; }

private:
    std::string name;
    int age;
};

// 2. OCP
class Shape
{
public:
    virtual double area() const = 0;  // Abstract method

    virtual ~Shape() {}  // Virtual destructor
};

//The Shape class is designed in a way that follows the Open/Closed Principle because:
//
//The Shape class defines an abstract interface (area() method), which means the existing Shape class does not need to be modified when you introduce new shapes.
//New shapes (like Rectangle, Circle, etc.) can be added by simply inheriting from Shape and implementing the area() method without modifying the base class itself.

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() const override
    {
        return width * height;
    }

private:
    double width;
    double height;
};

//How to Extend (Add New Shape):
//If you want to add a new shape, like a Circle, you can extend the system without changing the Shape class:

class Circle : public Shape
{
public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

// This follows the OCP because we are extending the system without modifying the existing Shape or Rectangle classes.

// 4. ISP: Instead of having one large interface, use smaller interfaces.
class Printer {
public:
    virtual void print(const std::string& text) const = 0;
    virtual ~Printer() {}
};

class ConsolePrinter : public Printer {
public:
    void print(const std::string& text) const override
    {
        std::cout << "Console: " << text << std::endl;
    }
};

class FilePrinter : public Printer {
public:
    void print(const std::string& text) const override
    {
        // Implement file printing logic
        std::cout << "File: " << text << std::endl;
    }
};

// 5. DIP: High-level module depends on abstractions. Example 1
class PersonPrinter
{
public:
    PersonPrinter(const Printer& printer) : printer(printer) {}

    void printPerson(const Person& person) const
    {
        std::string output = person.getName() + " is " + std::to_string(person.getAge()) + " years old.";
        printer.print(output);
    }
    
private:
    const Printer& printer;
};

int main()
{
    Rectangle rectangle(5.0, 3.0);
    std::cout << "Rectangle Area: " << rectangle.area() << std::endl;

    ConsolePrinter consolePrinter;
    FilePrinter filePrinter;

    Person person("John", 30);
    PersonPrinter personPrinter(consolePrinter);
    personPrinter.printPerson(person);

    return 0;
}

//Polymorphism: The function printArea takes a Shape* (a pointer to the base class) and can handle any object of a derived class like Rectangle or Circle. This is an example of dynamic polymorphism—at runtime, the correct area() method is called depending on the actual type of the object the pointer is pointing to.
//Liskov Substitution Principle (LSP): Both Rectangle and Circle can be substituted for Shape without changing the program’s behavior. The printArea function works perfectly with both types, adhering to the expectations of the Shape base class.




// 4. ISP example

#include <iostream>
#include <string>

// Define specific interfaces
class Printable {
public:
    virtual void print(const std::string& text) const = 0;
    virtual ~Printable() {}
};

class Savable {
public:
    virtual void save(const std::string& text) const = 0;
    virtual ~Savable() {}
};

// Concrete implementation that handles both printing and saving
class ReportHandler : public Printable, public Savable {
public:
    void print(const std::string& text) const override {
        std::cout << "Printing: " << text << std::endl;
    }

    void save(const std::string& text) const override {
        std::cout << "Saving: " << text << std::endl;
    }
};

// Function to demonstrate usage with interface pointers
void demonstrateUsage(const Printable* printable, const Savable* savable, const std::string& text) {
    if (printable) {
        printable->print(text);
    }
    if (savable) {
        savable->save(text);
    }
}

int main() {
    // Create an instance of the class implementing multiple interfaces
    ReportHandler reportHandler;

    // Pass pointers to the interfaces directly
    demonstrateUsage(&reportHandler, &reportHandler, "Report Data");

    return 0;
}


// 5. DIP: High-level module depends on abstractions. Example 2

// Abstraction representing a Logger
class ILogger
{
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

// Concrete implementation of a Logger
class ConsoleLogger : public ILogger
{
public:
    void log(const std::string& message) override {
        std::cout << "Console Log: " << message << std::endl;
    }
};

// Another concrete implementation of a Logger
class FileLogger : public ILogger
{
public:
    void log(const std::string& message) override {
        // Code for logging to a file
        std::cout << "File Log: " << message << std::endl;
    }
};

// High-level module that depends on an abstraction (ILogger)
class MessageProcessor
{
public:
    MessageProcessor(ILogger* logger) : logger(logger) {}

    void processMessage(const std::string& message) {
        // Process the message

        // Log the message using the provided logger
        logger->log(message);
    }

private:
    ILogger* logger; // Dependency on abstraction
};

//int main() {
//    // Creating instances of concrete implementations
//    ConsoleLogger consoleLogger;
//    FileLogger fileLogger;
//
//    // High-level module (MessageProcessor) is not dependent on low-level modules.
//    // Instead, it depends on abstractions (ILogger).
//    MessageProcessor messageProcessor1(&consoleLogger);
//    MessageProcessor messageProcessor2(&fileLogger);
//
//    // Using the MessageProcessor with different loggers
//    messageProcessor1.processMessage("Hello from Console Logger");
//    messageProcessor2.processMessage("Hello from File Logger");
//
//    return 0;
//}

//  SRP is demonstrated by the Person class, which has a single responsibility to represent a person's data.
//  OCP & LSP are demonstrated by the Shape hierarchy, where new shapes can be added without modifying existing code.
//  ISP is demonstrated by the Printer interfaces, where different printers can be implemented without affecting the PersonPrinter.
//  DIP is demonstrated by the PersonPrinter depending on the Printer interface, allowing for flexibility in printing implementations.

#endif /* SOLID_h */
