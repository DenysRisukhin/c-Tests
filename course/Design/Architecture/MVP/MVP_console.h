//
//  MVP.h
//  Test2019
//
//  Created by Risukhin Denys on 1/10/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MVP_h
#define MVP_h

//The MVP (Model-View-Presenter) pattern is architectural pattern commonly used in software development, particularly in GUI applications. MVP is similar to MVC but places a stronger emphasis(акцент) on separation of concerns and testability.
//
//In the MVP pattern:
//
//Model: Represents the data and business logic of the application.
//View: Represents the user interface and is passive. It displays data from the model to the user and sends user input events to the presenter.
//Presenter: Acts as an intermediary between the Model and the View. It contains the presentation logic and handles user input events from the View, updates the Model, and updates the View accordingly.

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

    std::string getUserInput() {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }
};

// Presenter
class TodoListPresenter {
private:
    TodoList model;
    TodoListView view;
public:
    void start() {
        // Display tasks initially
        view.displayTasks(model.getTasks());

        // Get user input and add tasks
        std::cout << "Enter a task (or 'exit' to quit):\n";
        while (true) {
            std::string input = view.getUserInput();
            if (input == "exit")
                break;
            model.addTask(input);
            view.displayTasks(model.getTasks());
        }
    }
};

int main() {
    TodoListPresenter presenter;
    presenter.start();

    return 0;
}

//In this example:
//
//TodoList is the Model, representing a list of tasks.
//TodoListView is the View, responsible for displaying the tasks to the user and getting user input.
//TodoListPresenter is the Presenter, which contains the presentation logic. It interacts with the Model to update the tasks and interacts with the View to display the tasks and get user input.
//The main() function creates a TodoListPresenter and starts the application. The presenter interacts with the Model and View to manage tasks and display them to the user.
//
//This is a simplified example to illustrate the MVP pattern in a console-based application. In a real-world application, you might use frameworks or libraries to handle user input, manage state changes, and update the view in response to model changes.

#endif /* MVP_h */
