//
//  ECS_cocos_2.h
//  Test2019
//
//  Created by Risukhin Denys on 1/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef ECS_cocos_2_h
#define ECS_cocos_2_h

//Model------------------------------------------------------------------------------
struct PopupItemMVC
{
    std::string title;
};

class PopupModelMVC {
public:
    void addItem(const std::string& title)
    {
        items.push_back(title);
    }
    
    void removeItem(int index)
    {
        if (index >= 0 && index < static_cast<int>(items.size()))
        {
            items.erase(items.begin() + index);
        }
    }
    
    const std::vector<PopupItemMVC>& getItems() const { return items; }

private:
    std::vector<PopupItemMVC> items;
};

//View------------------------------------------------------------------------------

class PopupViewMVC : public cocos2d::Scene {
public:
    CREATE_FUNC(PopupViewMVC);

    virtual bool init()
    {
        if (!Scene::init())
        {
            return false;
        }

            // Create the model
            model = new PopupModelMVC();
            // don't forget delete

            // Create UI elements
            itemInput = ui::EditBox::create(Size(200, 30), ui::Scale9Sprite::create());
            itemInput->setPlaceHolder("Enter item title");
            addChild(itemInput);

            auto addButton = ui::Button::create("button_normal.png", "button_pressed.png");
            addButton->setTitleText("Add Item");
            addButton->addClickEventListener(CC_CALLBACK_1(PopupViewMVC::onAddItemButtonClicked, this));
            addChild(addButton);

            auto removeButton = ui::Button::create("button_normal.png", "button_pressed.png");
            removeButton->setTitleText("Remove Item");
            removeButton->addClickEventListener(CC_CALLBACK_1(PopupViewMVC::onRemoveItemButtonClicked, this));
            addChild(removeButton);

            itemList = ui::ListView::create();
            itemList->setDirection(ui::ScrollView::Direction::VERTICAL);
            itemList->setContentSize(Size(300, 200));
            addChild(itemList);

            // Update the view initially
            updateItemList(model->getItems());

            return true;
    }
    
    void updateItemList(const std::vector<PopupItemMVC>& items)
    {
        itemList->removeAllItems();

        for (const auto& item : items)
        {
            auto itemLabel = Label::createWithTTF(item.title, "fonts/arial.ttf", 18);
            itemList->pushBackCustomItem(itemLabel);
        }
    }
    
    void setController(PopupControllerMVC* _controller)
    {
        controller = _controller;
    }

private:
    void onAddItemButtonClicked(Ref* sender)
    {
        controller->handleAddItem(itemInput->getText());
    }

    void onRemoveItemButtonClicked(Ref* sender)
    {
        int selectedItemIndex = itemList->getCurSelectedIndex();
        if (selectedItemIndex != -1)
        {
            controller->handleRemoveItem(selectedItemIndex);
        }
    }

private:
    PopupModelMVC* model;
    PopupControllerMVC* controller;
    
    cocos2d::ui::EditBox* itemInput;
    cocos2d::ui::ListView* itemList;
};

//Controller------------------------------------------------------------------------------

class PopupControllerMVC {
public:
    PopupControllerMVC(PopupModelMVC* model, PopupViewMVC* view): model(model), view(view) {}

    void handleAddItem(const std::string& title){
        model->addItem(title);
        updateView();
    }
    
    void handleRemoveItem(int index){
        model->removeItem(index);
        updateView();
    }
    
    void updateView(){
        const auto& items = model->getItems();
        view->updateItemList(items);
    }

private:
    PopupModelMVC* model;
    PopupViewMVC* view;
};

//Usage------------------------------------------------------------------------------
Scene* ExampleSceneMVC::createScene()
{
    return ExampleSceneMVC::create();
}

bool ExampleSceneMVC::init()
{
    if (!Scene::init()) {
        return false;
    }

    // Create the model, view, and controller for the popup
    popupModel = new PopupModelMVC();
    popupView = PopupViewMVC::create();
    popupController = new PopupControllerMVC(popupModel, popupView);

    // Set the view's controller
    popupView->setController(popupController);

    // Add the popup view to the scene
    addChild(popupView);

    return true;
}

void ExampleSceneMVC::onEnter()
{
    Scene::onEnter();
}

void ExampleSceneMVC::onExit()
{
    // Release resources
    delete popupModel;
    delete popupController;
    Scene::onExit();
}

// The controller (PopupControllerMVC) that handles user interactions and updates the model and view accordingly.
// This more closely aligns with the traditional MVC pattern where the controller is responsible for managing the flow of data between the
// model and the view.

#endif /* ECS_cocos_2_h */
