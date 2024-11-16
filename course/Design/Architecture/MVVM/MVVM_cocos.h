//
//  MVVM_cocos.h
//  Test2019
//
//  Created by Risukhin Denys on 1/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MVVM_cocos_h
#define MVVM_cocos_h

#include <string>

// Implementing MVVM (Model-View-ViewModel) in Cocos2d-x involves creating a structure where the
// View displays the UI
// ViewModel manages the presentation logic
// Model handles the application's data and business logic.

// Below is a simple example of MVVM in C++ using Cocos2d-x for a popup that updates data from a server.


//Model---------------------------------------------------------------------------------------------------

class PopupModel {
public:
    PopupModel(): data("Initial Data") {}

    const std::string& getData() const{
        return data;
    }

    void setData(const std::string& newData){
        data = newData;
    }

    void updateDataFromServer() {
        // Simulate updating data from the server
        data += "_Updated";
    }

private:
    std::string data;
};

//ViewModel---------------------------------------------------------------------------------------------------

class PopupViewModel {
public:
    PopupViewModel(PopupModel* model): model(model) {}

    const std::string& getData() const{
        return model->getData();
    }

    void updateDataFromServer(){
        model->updateDataFromServer();
    }
    
private:
    PopupModel* model;
};

//View---------------------------------------------------------------------------------------------------

class PopupView : public cocos2d::Node {
public:
    CREATE_FUNC(PopupView);

    void setDataOnView(const std::string& data) { label->setString(data); }
    
    void setViewModel(PopupViewModel* viewModel) { viewModel = viewModel; }

private:
    cocos2d::Label* label;
    PopupViewModel* viewModel;
};

bool PopupView::init() {
    if (!Node::init()) {
        return false;
    }

    // Create UI elements for the popup view (e.g., labels, buttons)

    label = cocos2d::Label::createWithTTF("Popup Content", "fonts/arial.ttf", 24);
    label->setPosition(getContentSize() / 2);
    addChild(label);

    return true;
}

//Usage---------------------------------------------------------------------------------------------------

Scene* ExampleScene::createScene() {
    return ExampleScene::create();
}

bool ExampleScene::init() {
    if (!Scene::init()) {
        return false;
    }

    // Create the model, view model, and view for the popup
    auto popupModel = new PopupModel();
    auto popupViewModel = new PopupViewModel(popupModel);
    auto popupView = PopupView::create();

    // Set the view model for the view
    popupView->setViewModel(popupViewModel);

    // Add the popup view to the scene
    addChild(popupView);

    // Simulate updating data from the server
    popupViewModel->updateDataFromServer();

    // Update the view with the data from the view model
    popupView->setDataOnView(popupViewModel->getData());

    return true;
}

//In this MVVM example:
//
//Model (PopupModel): Represents the data and business logic (e.g., content of the popup) and includes a method to simulate updating data from the server.
//ViewModel (PopupViewModel): Acts as an intermediary between the Model and the View, handling the presentation logic and data manipulation.
//View (PopupView): Represents the user interface (UI elements of the popup) and includes methods to update the view with data and set the ViewModel.
//
//In MVVM, the ViewModel is responsible for preparing data for the View and responding to user interactions. The View, in turn, is responsible for displaying the data and forwarding user inputs to the ViewModel. This separation of concerns allows for better testability and maintainability.

#endif /* MVVM_cocos_h */
