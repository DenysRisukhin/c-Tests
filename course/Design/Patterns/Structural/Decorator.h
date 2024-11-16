//
//  Decorator.h
//  Test2019
//
//  Created by Risukhin Denys on 1/15/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Decorator_h
#define Decorator_h

// Pattern allows behavior to be added to an individual object, either statically or dynamically, without affecting the behavior of other objects from the same class.
// It is achieved by creating a set of decorator classes that are used to wrap concrete components.

// Component interface
class Coffee {
public:
    virtual double cost() const = 0;
    virtual std::string description() const = 0;
};

// ConcreteComponent class
class SimpleCoffee : public Coffee {
public:
    double cost() const override {
        return 1.0;  // base cost of simple coffee
    }

    std::string description() const override {
        return "Simple Coffee";
    }
};

// Decorator abstract class
class CoffeeDecorator : public Coffee {
private:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}

    double cost() const override {
        return coffee->cost();
    }

    std::string description() const override {
        return coffee->description();
    }
};

// ConcreteDecorator classes
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double cost() const override {
        // additional cost for milk
        return CoffeeDecorator::cost() + 0.5;
    }

    std::string description() const override {
        // additional description for milk
        return CoffeeDecorator::description() + " with Milk";
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double cost() const override {
        // additional cost for sugar
        return CoffeeDecorator::cost() + 0.2;
    }

    std::string description() const override {
        // additional description for sugar
        return CoffeeDecorator::description() + " with Sugar";
    }
};

//int main() {
//    // Creating a simple coffee
//    Coffee* simpleCoffee = new SimpleCoffee();
//    std::cout << "Cost: $" << simpleCoffee->cost() << ", Description: " << simpleCoffee->description() << std::endl;
//
//    // Decorating the simple coffee with milk and sugar
//    Coffee* milkAndSugarCoffee = new MilkDecorator(new SugarDecorator(simpleCoffee));
//    std::cout << "Cost: $" << milkAndSugarCoffee->cost() << ", Description: " << milkAndSugarCoffee->description() << std::endl;
//
//    delete simpleCoffee;
//    delete milkAndSugarCoffee;
//
//    return 0;
//}

//In this example:
//  Coffee is the component interface defining the common interface for concrete components and decorators.
//  SimpleCoffee is a concrete component class that implements the Coffee interface.
//  CoffeeDecorator is an abstract decorator class that also implements the Coffee interface. It contains a reference to a Coffee object, which it can decorate.
//  MilkDecorator and SugarDecorator are concrete decorator classes that add specific behavior to the coffee.
//  This Decorator pattern allows you to dynamically add responsibilities to objects without altering their code. In the example, you can easily combine different decorators to create various combinations of coffee with different costs and descriptions.


#endif /* Decorator_h */
