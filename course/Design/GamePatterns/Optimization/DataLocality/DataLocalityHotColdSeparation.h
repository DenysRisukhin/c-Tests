//
//  DataLocalityHotColdSeparation.h
//  Test2019
//
//  Created by Risukhin Denys on 2/11/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef DataLocalityHotColdSeparation_h
#define DataLocalityHotColdSeparation_h

class AIComponent
{
public:
    void update() { /* ... */ }

private:
    Animation* animation_;
    double energy_;
    Vector goalPos_;
};

class AIComponent
{
public:
    void update() { /* ... */ }

private:
 // Предыдущие поля...
    LootType drop_;
    int minDrops_;
    int maxDrops_;
    double chanceOfDrop_;
};

class AIComponent
{
public:
// Методы... 223. private:
    Animation* animation_;
    double energy_;
    Vector goalPos_;

    LootDrop* loot_;
};

class LootDrop
{
    friend class AIComponent;
    LootType drop_;
    int minDrops_;
    int maxDrops_;
    double chanceOfDrop_;
};

#endif /* DataLocalityHotColdSeparation_h */
