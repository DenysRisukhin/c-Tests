//
//  ECS.h
//  Test2019
//
//  Created by Risukhin Denys on 1/10/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef ECS_h
#define ECS_h

//Entity-Component-System (ECS) is an architectural pattern commonly used in game development and other simulation-based applications to manage entities and their behavior. ECS decouples the data (components) from the behavior (systems) and organizes entities using identifiers (entity IDs).
//
//In an ECS architecture, the core concepts are:
//
//Entity: An entity is an identifier or a unique ID. It represents an object in the game or application.
//Component: A component is a plain data structure that holds data related to a specific aspect of an entity. For example, a Position component might store the x, y, and z coordinates of an entity.
//System: A system contains the logic or behavior that operates on entities with specific components. Systems process entities by querying for components and updating them accordingly.

#include <iostream>
#include <unordered_map>
#include <vector>

// Component: Position
struct Position {
    float x, y;

    Position(float _x, float _y) : x(_x), y(_y) {}
};

// Component: Velocity
struct Velocity {
    float dx, dy;

    Velocity(float _dx, float _dy) : dx(_dx), dy(_dy) {}
};

// Entity
using Entity = unsigned int;

// ECS
class ECS {
private:
    std::unordered_map<Entity, Position> positions;
    std::unordered_map<Entity, Velocity> velocities;

public:
    // Add components to an entity
    void addPositionComponent(Entity entity, float x, float y) {
        positions[entity] = Position(x, y);
    }

    void addVelocityComponent(Entity entity, float dx, float dy) {
        velocities[entity] = Velocity(dx, dy);
    }

    // Systems
    void updatePositionSystem() {
        for (auto& [entity, position] : positions)
        {
            if (velocities.find(entity) != velocities.end())
            {
                position.x += velocities[entity].dx;
                position.y += velocities[entity].dy;
            }
        }
    }
};

int main()
{
    ECS ecs;

    // Create entities and add components
    Entity entity1 = 1;
    ecs.addPositionComponent(entity1, 0.0f, 0.0f);
    ecs.addVelocityComponent(entity1, 1.0f, 1.0f);

    Entity entity2 = 2;
    ecs.addPositionComponent(entity2, 5.0f, 5.0f);

    // Update systems
    ecs.updatePositionSystem();

    // Display positions
    std::cout << "Entity 1 Position: (" << ecs.getPosition(entity1).x << ", " << ecs.getPosition(entity1).y << ")\n";
    std::cout << "Entity 2 Position: (" << ecs.getPosition(entity2).x << ", " << ecs.getPosition(entity2).y << ")\n";

    return 0;
}

//In this example:
//
//Position and Velocity are component structures.
//Entity is a unique identifier for entities.
//ECS is the main ECS manager class. It maintains maps for components and provides methods to add components and update systems.
//The updatePositionSystem method updates the positions of entities based on their velocities.
//This is a basic example to demonstrate the ECS pattern. In a real-world application, you would typically have more components, systems, and optimizations to handle a large number of entities efficiently.

#endif /* ECS_h */
