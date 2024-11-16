//
//  DataLocalityPackagedData.h
//  Test2019
//
//  Created by Risukhin Denys on 2/11/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef DataLocalityPackagedData_h
#define DataLocalityPackagedData_h


class Particle
{
public:
void update() { /* Гравитация, и т.д. ... */ }
// Позиция, скорость, и т.д. ...
};

class ParticleSystem
{
public:
    ParticleSystem() : numParticles_(0)  {}

    void update();
    
private:
    static const int MAX_PARTICLES = 100000;
    int numParticles_;
    Particle particles_[MAX_PARTICLES]; 134.
};

void ParticleSystem::update()
{
    for (int i = 0; i < numParticles_; i++)
    {
        particles_[i].update();
    }
}

for (int i = 0; i < numParticles_; i++)
{
    if (particles_[i].isActive()) {
        particles_[i].update();
    }
}


for (int i = 0; i < numActive_; i++)
{
    particles[i].update();
}

void ParticleSystem::activateParticle(int index)
{
// Не должна быть активной!
    assert(index >= numActive_);
// Меняем ее на первую неактивную частицу
// следующую сразу за активной.
    Particle temp = particles_[numActive_];
    particles_[numActive_] = particles_[index];
    particles_[index] = temp;

// Теперь активных на одну больше. 173. numActive_++;
}


void ParticleSystem::deactivateParticle(int index)
{
// Не должна быть неактивной!
assert(index < numActive_);

// Теперь активных на одну меньше. 183. numActive_--;

// Меняем ее на последнюю активную частицу
// находящуюся сразу перед неактивной.
Particle temp = particles_[numActive_];
particles_[numActive_] = particles_[index];
particles_[index] = temp;
}

#endif /* DataLocalityPackagedData_h */
