//
//  MVVM_Observer_cocos.h
//  Test2019
//
//  Created by Risukhin Denys on 1/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef MVVM_Observer_cocos_h
#define MVVM_Observer_cocos_h

//let's create a deep example related to the Model-View-ViewModel (MVVM) architecture with the Observer pattern in the context of Cocos2d-x.
//In this example, we'll create a simple game where the player's score is tracked using MVVM architecture.
//в MVVM зазвичай вʼюха підписується на оновлення ViewModel через Observer.

//In summary, the Observer pattern in this example facilitates communication between the ScoreViewModel and ScoreView. It allows the view to react to changes in the underlying data (score) without direct coupling between the two components, promoting a more modular and maintainable architecture.

//Model: ScoreModel-------------------------------------------------------

class ScoreModel
{
public:
    int getScore() const
    {
        return score;
    }
    
    void setScore(int score)
    {
        score = score;
    }

private:
    int score;
};

//view: ScoreView (Observer) -------------------------------------------------------

class ScoreView : public cocos2d::Node
{
public:
    static ScoreView* create(ScoreViewModel* viewModel)
    {
        ...
    }

    virtual bool init() override
    {
        if (!Node::init()) {
            return false;
        }

        // Create and set up the score label
        scoreLabel = cocos2d::Label::createWithTTF("Score: 0", "fonts/arial.ttf", 24);
        scoreLabel->setPosition(cocos2d::Director::getInstance()->getVisibleSize() / 2);
        addChild(scoreLabel);

        // Add observer to update the score label
        viewModel->addObserver([this](int newScore)
        {
            updateScoreLabel(newScore);
        });

        return true;
    }

private:
    void updateScoreLabel(int newScore)
    {
        scoreLabel->setString("Score: " + std::to_string(newScore));
    }

private:
    ScoreViewModel* viewModel;

    cocos2d::Label* scoreLabel;
};

//ViewModel: ScoreViewModel-------------------------------------------------------

class ScoreViewModel
{
public:
    ScoreViewModel(ScoreModel* model): model(model) {}

    int getScore() const { return model->getScore(); }
    
    void incrementScore()
    {
        int newScore = model->getScore() + 1;
        model->setScore(newScore);

        // Notify observers
        for (const auto& observer : observers) {
            observer(newScore);
        }
    }
    
    void addObserver(std::function<void(int)> observer)
    {
        observers.push_back(observer);
    }

private:
    ScoreModel* model;
    std::vector<std::function<void(int)>> observers;
};

//GameScene: Main Game Scene-------------------------------------------------------

class GameScene : public cocos2d::Scene {
public:
    virtual bool init() override
    {
        if (!Scene::init()) {
            return false;
        }

        // Create ScoreViewModel and ScoreView
        scoreViewModel = ScoreViewModel(&scoreModel);
        scoreView = ScoreView::create(&scoreViewModel);
        addChild(scoreView);

        // Touch event to increment the score
        auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event)
        {
            scoreViewModel.incrementScore();
            return true;
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

        return true;
    }
    

    CREATE_FUNC(GameScene);

private:
    ScoreModel scoreModel;
    ScoreViewModel scoreViewModel;
    ScoreView* scoreView;
};

// ScoreModel represents the data (score)
// ScoreViewModel handles the business logic and notifies observers of changes
// ScoreView is a Cocos2d-x Node responsible for displaying the score and updating when the score changes.

// The GameScene ties everything together and increments the score on touch events.

// observer stuff-----------------------------------------------------------------------

//the Observer pattern is implemented in the ScoreViewModel class. Let's break down how the Observer pattern works in this context:
//
//Observable Subject (ScoreViewModel):

//The ScoreViewModel class is the subject or observable. It contains the data (in this case, the score) and provides methods (getScore, incrementScore) to manipulate the data.
//It also maintains a collection of observers (std::vector<std::function<void(int)>> observers) as function objects (in this case, lambda functions) that will be notified whenever the state changes.

//Observer (ScoreView):
//The ScoreView class acts as the observer. It's interested in changes to the score and wants to update its display whenever the score changes.
//The ScoreView registers itself as an observer during its initialization (viewModel->addObserver(...)) by providing a lambda function that specifies what action to take when notified.

//Notification Mechanism:
//Whenever the ScoreViewModel updates the score (e.g., in the incrementScore method), it iterates through its list of observers and invokes each observer's function.
//In the ScoreView, the lambda function provided during registration ([this](int newScore) { updateScoreLabel(newScore); }) is called with the new score as an argument.

//Updating the View (ScoreView):
//The lambda function in ScoreView (updateScoreLabel) is responsible for updating the view with the new score.
//In this case, it updates the scoreLabel with the new score, ensuring that the displayed score is always in sync with the underlying data.
//Here's a more detailed breakdown:

//In the ScoreView initialization (ScoreView::init):
//The observer function (updateScoreLabel) is provided during registration with the ScoreViewModel.
//This function is responsible for updating the score label whenever it's called.
//In the ScoreViewModel:
//The incrementScore method is responsible for updating the score and notifying observers.
//After updating the score, it iterates through its list of observers and calls each observer function with the new score as an argument.


#endif /* MVVM_Observer_cocos_h */
