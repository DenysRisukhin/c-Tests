//
//  ECS_cocos.h
//  Test2019
//
//  Created by Risukhin Denys on 1/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef ECS_cocos_h
#define ECS_cocos_h

// let's create a simple example using the Entity-Component-System (ECS) pattern in the context of a Cocos2d-x game. In this example,
// we'll create a basic "enemy" entity with health and damage components.

//Components------------------------------------------------------------------------------

//First, let's define two components - HealthComponent and DamageComponent.
//These components will store information about the health and damage of an entity.

struct HealthComponent
{
    int health;

    HealthComponent(int initialHealth) : health(initialHealth) {}
};

struct DamageComponent
{
    int damage;

    DamageComponent(int damageValue) : damage(damageValue) {}
};

//Entity------------------------------------------------------------------------------

class EnemyEntity
{
public:
    HealthComponent healthComponent;
    DamageComponent damageComponent;

    EnemyEntity(int initialHealth, int damageValue)
        : healthComponent(initialHealth), damageComponent(damageValue) {}
};

//System------------------------------------------------------------------------------

//create a system that processes entities with HealthComponent and DamageComponent

class DamageSystem
{
public:
    static void applyDamage(EnemyEntity& enemy)
    {
        enemy.healthComponent.health -= enemy.damageComponent.damage;
        // You can add more logic here, like checking if the entity is dead.
    }
};

//Usage------------------------------------------------------------------------------

class GameScene : public cocos2d::Scene
{
public:
    virtual bool init()
    {
        if (!Scene::init())
        {
            return false;
        }

        // Create an enemy entity
        EnemyEntity enemy(100, 20);

        // Apply damage using the system
        DamageSystem::applyDamage(enemy);

        // Check the remaining health
        CCLOG("Enemy Health: %d", enemy.healthComponent.health);

        return true;
    }

    CREATE_FUNC(GameScene);
};

//This example demonstrates a basic implementation of the ECS pattern in the context of a Cocos2d-x game.
// Components (HealthComponent and DamageComponent) store data
// entities (EnemyEntity) represent game objects
// systems (DamageSystem) perform actions based on the components of entities.

//This separation of concerns makes it easier to manage and extend the game logic.

//+----------------+      +------------------------+       +-------------------+
//|     Entity     |      |       Component       |       |      System       |
//+----------------+      +------------------------+       +-------------------+
//| - ID           |      | - HealthComponent      |       | - DamageSystem    |
//| - ...          |      | - DamageComponent      |       | - ...             |
//| - ...          |      | - ...                  |       +-------------------+
//+----------------+      +------------------------+
//| + AddComponent()|      | + GetData()            |
//| + RemoveComponent|      | + SetData()            |
//| + ...          |      | + ...                  |
//+----------------+      +------------------------+


//Entity:
//  Represents a game object.
//  Contains an ID and may have additional data.
//  Has methods for adding/removing components.
//Component:
//  Represents the data or attributes of an entity.
//  Examples: HealthComponent, DamageComponent.
//  Has methods to get and set data.
//System:
//  Performs actions or logic based on the components of entities.
//Examples: DamageSystem.
//  Systems operate on entities with specific components.

//In this scheme:
//
//Entities are the objects in the game.
//Components store data related to specific aspects of an entity.
//Systems process entities based on their components.
//This separation allows for better organization and flexibility in game development. Entities can be composed of different combinations of components, and systems can operate on entities with specific component compositions. This promotes a modular and scalable architecture.

#endif /* ECS_cocos_h */
