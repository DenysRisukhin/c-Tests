//
//  MVP_cocos2.h
//  Test2019
//
//  Created by Risukhin Denys on 1/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MVP_cocos2_h
#define MVP_cocos2_h

//Model-----------------------------------------------------

struct PopupItemMVP
{
    std::string title;
};

class PopupModelMVP
{
public:
    void addItem(const std::string& title)
    {
        items.push_back({ title });
    }

    void removeItem(int index)
    {
        if (index >= 0 && index < static_cast<int>(items.size()))
        {
            items.erase(items.begin() + index);
        }
    }
    
    const std::vector<PopupItemMVP>& getItems() const { return items; }

private:
    std::vector<PopupItemMVP> items;
};

//View-----------------------------------------------------

class PopupViewMVP : public cocos2d::Scene {
public:
    CREATE_FUNC(PopupViewMVP);

    virtual bool init(){
        if (!Scene::init()) {
            return false;
        }

        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        // Create the model
        model = new PopupModelMVP();

        // Create UI elements
        itemInput = ui::EditBox::create(Size(200, 30), ui::Scale9Sprite::create());
        itemInput->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 50));
        itemInput->setPlaceHolder("Enter item title");
        addChild(itemInput);

        auto addButton = ui::Button::create("button_normal.png", "button_pressed.png");
        addButton->setPosition(Vec2(origin.x + visibleSize.width / 2 - 120, origin.y + 30));
        addButton->setTitleText("Add Item");
        addButton->addClickEventListener(CC_CALLBACK_1(PopupViewMVP::onAddItemButtonClicked, this));
        addChild(addButton);

        auto removeButton = ui::Button::create("button_normal.png", "button_pressed.png");
        removeButton->setPosition(Vec2(origin.x + visibleSize.width / 2 + 120, origin.y + 30));
        removeButton->setTitleText("Remove Item");
        removeButton->addClickEventListener(CC_CALLBACK_1(PopupViewMVP::onRemoveItemButtonClicked, this));
        addChild(removeButton);

        itemList = ui::ListView::create();
        itemList->setDirection(ui::ScrollView::Direction::VERTICAL);
        itemList->setContentSize(Size(300, 200));
        itemList->setPosition(Vec2(origin.x + visibleSize.width / 2 - 150, origin.y + visibleSize.height - 200));
        addChild(itemList);

        // Update the view initially
        updateItemList(model->getItems());

        return true;
    }
    
    void updateItemList(const std::vector<PopupItemMVP>& items)
    {
        itemList->removeAllItems();

        for (const auto& item : items)
        {
            auto itemLabel = Label::createWithTTF(item.title, "fonts/arial.ttf", 18);
            itemList->pushBackCustomItem(itemLabel);
        }
    }
    
    void setPresenter(PopupPresenterMVP* _presenter)
    {
        presenter = _presenter;
    }

private:
    void onAddItemButtonClicked(Ref* sender)
    {
        presenter->addItem(itemInput->getText());
    }
    
    void onRemoveItemButtonClicked(Ref* sender)
    {
        int selectedItemIndex = itemList->getCurSelectedIndex();
        if (selectedItemIndex != -1)
        {
            presenter->removeItem(selectedItemIndex);
        }
    }

private:
    cocos2d::ui::EditBox* itemInput;
    cocos2d::ui::ListView* itemList;

    PopupModelMVP* model;
    PopupPresenterMVP* presenter;
};

//Presenter-----------------------------------------------------

class PopupPresenterMVP
{
public:
    PopupPresenterMVP(PopupModelMVP* model, PopupViewMVP* view): model(model), view(view) {}

    void addItem(const std::string& title)
    {
        model->addItem(title);
           updateView();
    }
    
    void removeItem(int index)
    {
        model->removeItem(index);
            updateView();
    }
    
    void updateView()
    {
        const auto& items = model->getItems();
            view->updateItemList(items);
    }

private:
    PopupModelMVP* model;
    PopupViewMVP* view;
};

//Usage-----------------------------------------------------

Scene* ExampleSceneMVP::createScene()
{
    return ExampleSceneMVP::create();
}

bool ExampleSceneMVP::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Create the model, view, and presenter for the popup
    auto popupModel = new PopupModelMVP();
    auto popupView = PopupViewMVP::create();
    auto popupPresenter = new PopupPresenterMVP(popupModel, popupView);

    // Set the view's presenter
    popupView->setPresenter(popupPresenter);

    // Add the popup view to the scene
    addChild(popupView);

    return true;
}

//MVC:
//The PopupViewMVC directly interacts with the PopupModelMVC in response to user actions.
//The PopupViewMVC is responsible for updating both the PopupModelMVC and itself.

//MVP:
//The PopupViewMVP delegates user interactions to the PopupPresenterMVP.
//The PopupPresenterMVP is responsible for updating both the PopupModelMVP and the PopupViewMVP.
//In the MVP example, the PopupViewMVP remains more passive and delegates the handling of user interactions to the PopupPresenterMVP. This separation allows for better testability and maintenance, as the PopupViewMVP does not directly manipulate the model.
//
//This should give you a clearer understanding of the differences between MVC and MVP, particularly in the context of user interaction and code organization.

#endif /* MVP_cocos2_h */
