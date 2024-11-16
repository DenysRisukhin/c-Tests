//
//  DataLocality.h
//  Test2019
//
//  Created by Risukhin Denys on 2/11/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef DataLocality_h
#define DataLocality_h




//-Последовательные массивы

class GameEntity
{
public:
    GameEntity(AIComponent* ai, PhysicsComponent* physics, RenderComponent* render)
        : ai_(ai), physics_(physics), render_(render)
    {}
    
    AIComponent* ai() { return ai_; }
    PhysicsComponent* physics() { return physics_; }
    RenderComponent* render() { return render_; }

private:
    AIComponent* ai_;
    PhysicsComponent* physics_;
    RenderComponent* render_;
};


class AIComponent
{
public:
    void update() { /* Обработка и изменение состояния...
*/ }
private:

    
class PhysicsComponent
{
public:
    void update() { /* Обработка и изменение состояния... */ }

private:
 // твердое тело, скорость, масса, и т.д. ...
 };
    
    
class RenderComponent {
public:
    void render() { /* Обработка и изменение состояния... */ }

private:
// Сетка, текстуры, шейдеры, и т.д....
};
    
    
    
    while (!gameOver)
    {
     // Обрабатываем AI.
     for (int i = 0; i < numEntities; i++) 61. {
     entities[i]->ai()->update(); 63. }
    
     // Обновляем физику.
     for (int i = 0; i < numEntities; i++)
     {
     entities[i]->physics()->update(); 69. }
    
     // Рисуем на экране.
     for (int i = 0; i < numEntities; i++)
     {
     entities[i]->render()->render();
     }
    
    
     // Остальные задачи игрового цикла...
        
    }
    
    
    AIComponent* aiComponents = new AIComponent[MAX_ENTITIES];
    PhysicsComponent* physicsComponents = new PhysicsComponent[MAX_ENTITIES];
    RenderComponent* renderComponents = new RenderComponent[MAX_ENTITIES];
    
    
    
    while (!gameOver) {
    // Обработка AI.
    for (int i = 0; i < numEntities; i++)
    {
        aiComponents[i].update();
    }
        
        // Обработка физики.
    for (int i = 0; i < numEntities; i++)
    {
        physicsComponents[i].update();
    }
     
        // Отрисовка на экране.
    for (int i = 0; i < numEntities; i++)
    {
         renderComponents[i].render();
    }
   
         // Остальные задачи игрового цикла...
    }
    
    
    
    
    
    
    
    

#endif /* DataLocality_h */
