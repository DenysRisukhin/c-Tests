//
//  ObjectPool.h
//  Test2019
//
//  Created by Risukhin Denys on 2/11/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef ObjectPool_h
#define ObjectPool_h

// Улучшение производительности и эффективности использования памяти за счет повторного использования объектов
// из фиксированного пула, вместо их индивидуального выделения и освобождения.

class Particle
{
public:
    Particle() :
    framesLeft_(0)
    {
    }

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
         return;
     
     framesLeft_--;
     x_ += xVel_;
     y_ += yVel_;
 }

bool inUse() const { return framesLeft_ > 0; }

private:
    int framesLeft_;
    double x_, y_;
    double xVel_, yVel_;
};

#pragma mark - ParticlePool

class ParticlePool
{
public:
    void create(double x, double y, double xVel, double yVel, int lifetime)
    {
        for (int i = 0; i < POOL_SIZE; i++)
        {
            if (!particles_[i].inUse())
            {
                particles_[i].init(x, y, xVel, yVel, lifetime);
                return;
            }
        }
    }

    void animate()
    {
        for (int i = 0; i < POOL_SIZE; i++)
        {
            particles_[i].animate();
        }
    }

private:
    
    static const int POOL_SIZE = 100;
    Particle particles_[POOL_SIZE];
};

#endif /* ObjectPool_h */
