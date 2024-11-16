//
//  4_task_ISP.h
//  Test2019
//
//  Created by Risukhin Denys on 9/15/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef __task_ISP_h
#define __task_ISP_h

#include <iostream>
#include <string>
#include <utility> // for std::move

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
private:
    std::string reportTitle; // Example field

public:
    // Parameterized constructor
    explicit ReportHandler(std::string title) : reportTitle(std::move(title)) {}

    // Move constructor
    ReportHandler(ReportHandler&& other) noexcept
        : reportTitle(std::move(other.reportTitle)) {}

    // Move assignment operator
    ReportHandler& operator=(ReportHandler&& other) noexcept {
        if (this != &other) {
            reportTitle = std::move(other.reportTitle);
        }
        return *this;
    }

    // Copy constructor and copy assignment operator
    ReportHandler(const ReportHandler&) = default;
    ReportHandler& operator=(const ReportHandler&) = default;

    void print(const std::string& text) const override {
        std::cout << "Printing: " << text << " - Title: " << reportTitle << std::endl;
    }

    void save(const std::string& text) const override {
        std::cout << "Saving: " << text << " - Title: " << reportTitle << std::endl;
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
    ReportHandler reportHandler("Annual Report");

    // Pass pointers to the interfaces directly
    demonstrateUsage(&reportHandler, &reportHandler, "Report Data");

    // Demonstrate move semantics
    ReportHandler movedHandler(std::move(reportHandler));
    demonstrateUsage(&movedHandler, &movedHandler, "Moved Report Data");

    ReportHandler anotherHandler("Temporary Report");
    anotherHandler = std::move(movedHandler);
    demonstrateUsage(&anotherHandler, &anotherHandler, "Another Moved Report Data");

    return 0;
}

Key Points
1. Interface Definition:
    Printable and Savable define the contracts for printing and saving, respectively.
2. Concrete Implementation:
    ReportHandler implements both interfaces and manages its own state, including reportTitle.
3. Move Semantics:
    Move constructor and move assignment operator are implemented to handle resource transfers using C++14 features.
4. Demonstration Function:
    demonstrateUsage shows how to interact with ReportHandler through interface pointers.
5. Testing:
    The main function demonstrates the creation, movement, and reassignment of ReportHandler instances, ensuring move semantics work as expected.
#endif /* __task_ISP_h */
