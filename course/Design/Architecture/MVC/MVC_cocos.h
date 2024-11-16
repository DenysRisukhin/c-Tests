//
//  MVC_cocos.h
//  Test2019
//
//  Created by Risukhin Denys on 1/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MVC_cocos_h
#define MVC_cocos_h

// simple MVC structure for a popup in a Cocos2d-x scene that updates data from a server

//Model
#include <string>

class PopupModel {
public:
    PopupModel();

    // Getter and setter for data
    const std::string& getData() const { return data; }
    void setData(const std::string& newData) { data = newData; }

    // Simulate data update from the server
    void updateDataFromServer()
    {
        // Simulate data update from the server
        // In a real-world scenario, you would make a network request to fetch updated data
        // For simplicity, we'll just append "_Updated" to the existing data
        data += "_Updated";
    }
    
private:
    std::string data;
};

//View--------------------------------------------------------------------------------------------------
class PopupView : public cocos2d::Node {
public:
    CREATE_FUNC(PopupView);

    // Set the data on the view
    void setDataOnView(const std::string& data);
};

bool PopupView::init() {
    if (!Node::init()) {
        return false;
    }

    // Create UI elements for the popup view (e.g., labels, buttons)
    // For simplicity, we'll just use a label to display data

    auto label = cocos2d::Label::createWithTTF("Popup Content", "fonts/arial.ttf", 24);
    label->setPosition(getContentSize() / 2);
    addChild(label);

    return true;
}

void PopupView::setDataOnView(const std::string& data) {
    // Update the UI elements with the provided data
    // For simplicity, we'll just update a label
    // In a real-world scenario, you would update various UI elements
    auto label = dynamic_cast<cocos2d::Label*>(getChildByName("Popup Content"));
    if (label) {
        label->setString(data);
    }
}

//Controller--------------------------------------------------------------------------------------------------

class PopupController {
public:
    PopupController(PopupModel* model, PopupView* view) : model(model), view(view) {}

    // Show the popup and update data from the server
    void showPopupAndUpdateData(){
        // Simulate updating data from the server
           model->updateDataFromServer();

           // Show the popup view and set the updated data
           view->setVisible(true);
           view->setDataOnView(model->getData());
    }
    
private:
    PopupModel* model;
    PopupView* view;
};


//Usage--------------------------------------------------------------------------------------------------

Scene* ExampleScene::createScene() {
    return ExampleScene::create();
}

bool ExampleScene::init() {
    if (!Scene::init()) {
        return false;
    }

    // Create the model, view, and controller for the popup
    auto popupModel = new PopupModel();
    auto popupView = PopupView::create();
    auto popupController = new PopupController(popupModel, popupView);

    // Add the popup view to the scene
    addChild(popupView);
    popupView->setVisible(false); // Initially, the popup is hidden

    // Simulate showing the popup and updating data from the server
    popupController->showPopupAndUpdateData();

    return true;
}

//Model (PopupModel): Represents the data (e.g., content of the popup) and includes a method to simulate updating data from the server.
//View (PopupView): Represents the user interface (UI elements of the popup) and includes a method to update the view with data.
//Controller (PopupController): Acts as an intermediary between the Model and the View, handling the logic of showing the popup and updating data.

//This is a basic example, and in a real-world scenario, you would have more complex UI elements and likely use a UI framework or library for creating popups. Additionally, the data update from the server would involve making actual network requests to fetch updated data.

#endif /* MVC_cocos_h */
