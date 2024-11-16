//
//  Observer.h
//  Test2019
//
//  Created by Denys Risukhin on 8/13/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include <list>

#pragma mark - Observer With MVC (cocos2dx loadingbar view)

#pragma mark - step 1
// Each one model must inharites from class Observable
class Observable
{
public:
    Observable(): m_notify(true) {}
    
    virtual ~Observable() {
        
        for (auto it = m_observers.begin() ; it != m_observers.end() ; ++it) {
            auto cpyIter = it;
            it = m_observers->erase(cpyIter);
        }
        
        m_observers.clear();
    }
    
    // add observer to model
    void addObserver(Observer* observer) {
        m_observers.push_back(observer);
    }
    
    void removeObserver(Observer* observer){
        m_observers.remove(observer);
    }
    
protected:
    // уведомление что модель изменилась
    void notifyUpdate() {
        if (!m_notify) {
            return;
        }
    
        for (auto it = m_observers.begin() ; it != m_observers.end() ; ++it) {
            (*it)->Update();
        }
    }
    
    void disableNotify() {
        m_notify = false;
    }
    
    void enableNotify() {
        m_notify = true;
    }
    
private:
    std::list<Observer*> m_observers; // список из тех кого нужно оповещать об изменении модели
    bool m_notify; // флаг
};

#pragma mark - step 2

class Observer {
public:
    virtual void Update() = 0;
};

#pragma mark - step 3

class LoadingBarModel: public Observable
{
public:
    LoadingBarModel();
    LoadingBarModel(std::string loadingText, float progress);
    LoadingBarModel(float min, float max);
    
    void setProgress(float progress);
    void setLoadingText(std::string loadingText);
    void setMin(float min);
    void setMax(float max);
    
    float getMin() { return m_min; }
    float getMax() { return m_max; }
    float getProgress() { return m_progress; }
    std::string getLoadingText() { return m_loadingText; }
    
    std::string toString();
    
private:
    float m_min;
    float m_max;
    float m_progress;
    std::string m_loadingText;
};

#pragma mark - step 4

// вроде как наследование метода Update и есть подписка
class LoadingBarNode: public Node, public Observer
{
public:
    LoadingBarNode() {}
    
    LoadingBarNode(LoadingBarModel* model);
    
    bool init() override;
    
    void Update() override;
    void update(float delta);
    
    void formDestroy();
private:
    float m_progressValue = 0.f;
    float m_min = 0.f;
    float m_max = 100.f;
    
    LoadingBarModel* m_model = nullptr;
    LoadingBar* m_loadingBar = nullptr;
    cocos2d::Label* m_label1 = nullptr;
    cocos2d::Label* m_label2 = nullptr;
};

#pragma mark - Observer for cocos2dx

#pragma mark - step 1

class Count: public cocos2d::Label
{
public:
    ~Count();
    
    virtual bool init();
    
    CREATE_FUNC(Count);
    
private:
    int m_count = 0;
    void countUp(float dt);
};

Count::~Count()
{
    this->getEventDispatcher()->removeCustomEventListeners("TimeCount");
}

bool Count::init()
{
    if (!Label::init())
    {
        return false;
    }
    
    m_count = 0;
    this->setString("0");
    //this->setFontScale(2.0f);
    this->setBMFontSize(34.f);
    
    this->getEventDispatcher()->addCustomEventListener("TimeCount", [=](EventCustom* event)
                                                       {
                                                           this->countUp(0);
                                                       });
    // If you use Scheduler instead of EventDispatcher, you will notice something different.
    // The labels are not counting up at the same time in this way. Each label is counting up per second,
    // however not at the same time. Using Observer Pattern, a lot of subjects can be called at the same time.
    
    //this->schedule(schedule_selector(Count::countUp), 1.0f);
    
    return true;
}

void Count::countUp(float dt)
{
    m_count++;
    this->setString(StringUtils::format("%d", m_count));
}

#pragma mark - step 2 HelloWorld

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void countUp(float dt);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#pragma mark - step 3

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    auto countLabel = Count::create();
    this->addChild(countLabel);
    countLabel->setPosition(touch->getLocation());
    return true;
}

#pragma mark - step 4

bool HelloWorld::init()
{
    // ....
    this->schedule(schedule_selector(HelloWorld::countUp), 1.0f);
    return true;
}

#pragma mark - step 5

void HelloWorld::countUp(float dt)
{
    this->getEventDispatcher()->dispatchCustomEvent("TimeCount");
}


#endif /* Observer_h */
