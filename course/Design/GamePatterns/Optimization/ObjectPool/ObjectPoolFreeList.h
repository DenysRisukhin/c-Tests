//
//  ObjectPoolFreeList.h
//  Test2019
//
//  Created by Risukhin Denys on 2/11/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef ObjectPoolFreeList_h
#define ObjectPoolFreeList_h

// Complexity O(1)

class Particle
{
public:
    Particle() :
    framesLeft_(0)
    {
    }
    
    Particle* getNext() const { return state_.next; }
    void setNext(Particle* next) { state_.next = next; }

void init(double x, double y, double xVel, double yVel, int lifetime)
{
    x_=x;
    y_=y;
    xVel_ = xVel;
    yVel_ = yVel;
    framesLeft_ = lifetime;
}

 void animate()
 {
     if (!inUse())
         return false;
     
     framesLeft_--;
     x_ += xVel_;
     y_ += yVel_;
     
     return framesLeft_ == 0;
 }

bool inUse() const { return framesLeft_ > 0; }

private:
    int framesLeft_;
 
    union
    {// Состояние когда частица используется.
        struct
        {
            double x, y;
            double xVel, yVel;
        } live;
        
        // Состояние когда частица доступна.
        Particle* next;
    } state;
};

#pragma mark - ParticlePool

class ParticlePool
{
public:
    
    ParticlePool()
    {
        // Доступен первый.
        firstAvailable_ = &particles_[0];
        
        // Каждая частица указывает на следующую. 9.for (int i = 0; i < POOL_SIZE - 1; i++)
        {
            particles_[i].setNext(&particles_[i + 1]);
        }
        
         // Последняя завершает список.
        particles_[POOL_SIZE - 1].setNext(NULL);
        
    }
    
    void create(double x, double y, double xVel, double yVel, int lifetime)
    {
        // Проверяем что пул не заполнен полностью. 8.assert(firstAvailable_ != NULL);
      
        // Удаляем ее из списка доступных.
        Particle* newParticle = firstAvailable_;
        firstAvailable_ = newParticle->getNext();
        
        newParticle->init(x, y, xVel, yVel, lifetime); 15. }
    }

    void animate()
    {
        for (int i = 0; i < POOL_SIZE; i++)
        {
            if (particles_[i].animate())
            {
                // Добавляем эту частицу в начало списка.
                particles_[i].setNext(firstAvailable_); 11. firstAvailable_ = &particles_[i];
            }
        }
    }

private:

    static const int POOL_SIZE = 100;
    Particle particles_[POOL_SIZE];
};

// Archtecture solutions

// 1. Если объекты связаны с пулом:

// 2. Если объекты не связаны с пулом:

// 3. Если пул повторно инициализируется внутри:


#endif /* ObjectPoolFreeList_h */
