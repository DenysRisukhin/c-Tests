//
//  MVC.h
//  Test2019
//
//  Created by Risukhin Denys on 1/10/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MVC_h
#define MVC_h

//The MVC (Model-View-Controller) pattern is a widely used architectural pattern in software development, particularly in the context of GUI applications. MVC separates an application into three interconnected components:

//Model: Represents the data and business logic of the application.
//View: Represents the user interface and displays the data from the model to the user.
//Controller: Acts as an intermediary between the Model and the View, handling user input and updating the Model and View accordingly.

#include <iostream>
#include <string>
#include <vector>

// Model
class TodoList {
private:
    std::vector<std::string> tasks;
public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
    }

    const std::vector<std::string>& getTasks() const {
        return tasks;
    }
};

// View
class TodoListView {
public:
    void displayTasks(const std::vector<std::string>& tasks) {
        std::cout << "Tasks:\n";
        for (const auto& task : tasks) {
            std::cout << "- " << task << "\n";
        }
    }
};

// Controller
class TodoListController {
private:
    TodoList model;
    TodoListView view;
public:
    void addTask(const std::string& task) {
        model.addTask(task);
        updateView();
    }

    void updateView() {
        view.displayTasks(model.getTasks());
    }
};

int main() {
    TodoListController controller;

    // Add tasks using the controller
    controller.addTask("Buy groceries");
    controller.addTask("Clean the house");

    return 0;
}


//In this example:
//
//TodoList is the Model, representing a list of tasks.
//TodoListView is the View, responsible for displaying the tasks to the user.
//TodoListController is the Controller, which contains the business logic and acts as an intermediary between the Model and the View.
//The main() function demonstrates how tasks can be added to the TodoList using the TodoListController, and the tasks are displayed to the user through the TodoListView.
//
//This is a simplified example to illustrate the MVC pattern in a console-based application. In a real-world application, you might use frameworks or libraries to handle user input, manage state changes, and update the view in response to model changes.


#endif /* MVC_h */
