//
//  MVP_cocos.h
//  Test2019
//
//  Created by Risukhin Denys on 1/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MVP_cocos_h
#define MVP_cocos_h

// simple MVP (Model-View-Presenter) example in C++ using Cocos2d-x for a popup that updates data from a server.

//Model---------------------------------------
class PopupModel {
public:
    PopupModel(): data("Initial Data") {}

    const std::string& getData() const { return data; }
    void setData(const std::string& newData); { data = newData; }
    void updateDataFromServer() {
        // Simulate updating data from the server
        data += "_Updated";
    }

private:
    std::string data;
};

//View---------------------------------------
class PopupView : public cocos2d::Node {
public:
    CREATE_FUNC(PopupView);

    void setDataOnView(const std::string& data) { label->setString(data); }

private:
    cocos2d::Label* label;
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

//Presenter---------------------------------------

class PopupPresenter {
public:
    PopupPresenter(PopupModel* model, PopupView* view) : model(model), view(view) {}

    void showPopupAndUpdateData() {
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

//Usage---------------------------------------

Scene* ExampleScene::createScene() {
    return ExampleScene::create();
}

bool ExampleScene::init() {
    if (!Scene::init()) {
        return false;
    }

    // Create the model, view, and presenter for the popup
    auto popupModel = new PopupModel();
    auto popupView = PopupView::create();
    auto popupPresenter = new PopupPresenter(popupModel, popupView);

    // Add the popup view to the scene
    addChild(popupView);
    popupView->setVisible(false); // Initially, the popup is hidden

    // Simulate showing the popup and updating data from the server
    popupPresenter->showPopupAndUpdateData();

    return true;
}

//Model (PopupModel): Represents the data and business logic (e.g., content of the popup) and includes a method to simulate updating data from the server.
//View (PopupView): Represents the user interface (UI elements of the popup) and includes a method to update the view with data.
//Presenter (PopupPresenter): Acts as an intermediary between the Model and the View, handling the logic of showing the popup and updating data.

//The key difference between MVP and MVC is that the Presenter in MVP is responsible for controlling the flow of data between the Model and the View. The View is more passive in MVP, and it delegates user input handling to the Presenter. This helps to keep the business logic separate from the UI logic.

#endif /* MVP_cocos_h */
