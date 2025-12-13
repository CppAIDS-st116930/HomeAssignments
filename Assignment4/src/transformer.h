// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "weapon.h"
#include "pilot.h"
#include <iostream>

class Transformer
{
public:
    Transformer();
    Transformer(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon);
    virtual ~Transformer();

    void setPilot(Pilot* pilot);
    Pilot* getPilot() const;

    unsigned int getLevel() const;
    unsigned int getStrength() const;
    unsigned int getFuel() const;

    // Virtual Methods
    virtual bool move();
    virtual bool jump();
    virtual bool fire(); // Made virtual to be safe
    virtual void openFire(); // New Virtual
    virtual void ultraMove(); // New Virtual
    virtual void transform() = 0; // Pure Virtual

    // Operator Overloading
    friend std::ostream& operator<<(std::ostream& os, const Transformer& t);

protected:
    unsigned int _level;
    unsigned int _strength;
    unsigned int _fuel;
    Weapon _weapon;
    Pilot* _pilot;
};

#endif
