//
//  3_LSP.h
//  Test2019
//
//  Created by Risukhin Denys on 9/7/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef __LSP_h
#define __LSP_h

//Let's illustrate the relationship between polymorphism and the Liskov Substitution Principle (LSP) using pointers and dynamic memory allocation
//
//Correct Example (Adhering to LSP with Pointers)
//Here’s an example that adheres to both polymorphism and Liskov Substitution Principle (LSP). This will use pointers and dynamic memory allocation via new:

#include <iostream>
#include <memory>
#include <exception>

// Enum class for shape types
enum class ShapeType { Rectangle, Circle };

// Template base class representing a shape
template<typename T>
class Shape {
public:
    virtual T area() const = 0;  // Pure virtual function for area calculation
    virtual ShapeType getShapeType() const = 0;  // Pure virtual function for shape type
    virtual ~Shape() = default;  // Virtual destructor

    // Move constructor
    Shape(Shape&& other) noexcept = default;
    // Move assignment operator
    Shape& operator=(Shape&& other) noexcept = default;

protected:
    Shape() = default;  // Default constructor
};

// Derived class representing a rectangle
template<typename T>
class Rectangle : public Shape<T> {
public:
    explicit Rectangle(T width, T height) : m_width(width), m_height(height) {}

    T area() const override {
        return m_width * m_height;
    }

    ShapeType getShapeType() const override {
        return ShapeType::Rectangle;
    }

private:
    T m_width;
    T m_height;
};

// Derived class representing a circle
template<typename T>
class Circle : public Shape<T> {
public:
    explicit Circle(T radius) : m_radius(radius) {}

    T area() const override {
        return 3.14159 * m_radius * m_radius;
    }

    ShapeType getShapeType() const override {
        return ShapeType::Circle;
    }

private:
    T m_radius;
};

// Function to print the area of a shape
template<typename T>
void printArea(const std::shared_ptr<Shape<T>>& shape) {
    try {
        if (shape) {
            std::cout << "Area: " << shape->area() << std::endl;
        } else {
            throw std::runtime_error("Shape is null.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error calculating area: " << e.what() << std::endl;
    }
}

// Function to print the shape type
template<typename T>
void printShapeType(const std::shared_ptr<Shape<T>>& shape) {
    try {
        if (shape) {
            ShapeType type = shape->getShapeType();
            switch (type) {
                case ShapeType::Rectangle:
                    std::cout << "Shape Type: Rectangle" << std::endl;
                    break;
                case ShapeType::Circle:
                    std::cout << "Shape Type: Circle" << std::endl;
                    break;
            }
        } else {
            throw std::runtime_error("Shape is null.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error printing shape type: " << e.what() << std::endl;
    }
}

int main() {
    try {
        // Create instances of the template classes using std::shared_ptr
        std::shared_ptr<Shape<double>> shape1 = std::make_shared<Rectangle<double>>(5.0, 10.0);
        std::shared_ptr<Shape<double>> shape2 = std::make_shared<Circle<double>>(7.0);

        // Test with printArea function
        printArea(shape1);  // Output: Area: 50
        printArea(shape2);  // Output: Area: 153.938

        // Test with printShapeType function
        printShapeType(shape1);  // Output: Shape Type: Rectangle
        printShapeType(shape2);  // Output: Shape Type: Circle

        // Demonstrate move semantics with shared_ptr by directly moving the pointers
        auto shape3 = std::move(shape1);  // Move the ownership of shape1 to shape3
        auto shape4 = std::move(shape2);  // Move the ownership of shape2 to shape4

        printArea(shape3);  // Output: Area: 50 (after move)
        printArea(shape4);  // Output: Area: 153.938 (after move)

        // Check that the original shared pointers are now empty
        if (!shape1) {
            std::cout << "shape1 has been moved and is now null." << std::endl;
        }
        if (!shape2) {
            std::cout << "shape2 has been moved and is now null." << std::endl;
        }

        // Demonstrate move assignment with shared_ptr
        auto shape5 = std::make_shared<Rectangle<double>>(10.0, 20.0); // New instance
        shape5 = std::move(shape3);  // Move the ownership of shape3 to shape5

        printArea(shape5);  // Output: Area: 50 (after move assignment)
        if (!shape3) {
            std::cout << "shape3 has been moved and is now null." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception occurred in main: " << e.what() << std::endl;
    }

    return 0;
}

//Explanation:
//    Shared Pointers: std::shared_ptr is used for dynamic memory management.
//    Move Semantics: Demonstrated by moving ownership of shapes with std::move().
//    Error Handling: Handled using try-catch blocks for area and shape type printing.
//    Enums: enum class ShapeType is used for shape identification.
//    Tests: Different scenarios for calculating area, moving objects, and checking null pointers after moves.

#endif /* __LSP_h */
