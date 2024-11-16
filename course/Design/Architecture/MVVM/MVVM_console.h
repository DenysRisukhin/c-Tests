//
//  MVVM.h
//  Test2019
//
//  Created by Risukhin Denys on 1/10/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MVVM_h
#define MVVM_h

//MVVM (Model-View-ViewModel) is a design pattern that is widely used in modern UI applications to separate the business logic from the user interface. Even though MVVM is commonly associated with frameworks like WPF (Windows Presentation Foundation) in the .NET world, the pattern itself is not tied to any specific technology and can be implemented in C++ as well.

//Model: Represents the data and the business logic of the application.
//View: Represents the user interface.
//ViewModel: Acts as an intermediary between the Model and the View.

// Model (data structure)
class Person {
public:
    std::string name;
    int age;
};

// ViewModel
class PersonViewModel {
private:
    Person person;
public:
    PersonViewModel(const std::string& name, int age) : person{ name, age } {}
    
    std::string getName() const {
        return person.name;
    }
    
    int getAge() const {
        return person.age;
    }
    
    void setName(const std::string& name) {
        person.name = name;
    }
    
    void setAge(int age) {
        person.age = age;
    }
};

// View
class PersonView {
private:
    PersonViewModel* viewModel;
public:
    PersonView(PersonViewModel* vm) : viewModel(vm) {}
    
    void display() {
        std::cout << "Name: " << viewModel->getName() << ", Age: " << viewModel->getAge() << std::endl;
    }
};

int main() {
    // Create ViewModel
    PersonViewModel personVM("John", 30);
    
    // Create View
    PersonView personView(&personVM);
    
    // Display data
    personView.display();
    
    // Update data
    personVM.setName("Doe");
    personVM.setAge(35);
    
    // Display updated data
    personView.display();
    
    return 0;
}

//Person is the Model, representing a person's data.
//PersonViewModel acts as an intermediary between the Model and the View. It exposes methods to get and set data and contains the logic that manipulates the Model.
//PersonView is the View, which displays the data from the ViewModel.
//This is a simplified example to illustrate the concept. In a real-world application, you might use libraries or frameworks to bind the ViewModel to the View, handle user input, and manage state changes.

#endif /* MVVM_h */
