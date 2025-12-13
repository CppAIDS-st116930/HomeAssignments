// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include "autobot.h"

Autobot::Autobot()
    : Transformer(), _empathy(0), _guardianMode(false)
{
}

Autobot::Autobot(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon, unsigned int empathy, bool guardianMode)
    : Transformer(level, strength, fuel, weapon), _empathy(empathy), _guardianMode(guardianMode)
{
}

unsigned int Autobot::getEmpathy() const
{
    return _empathy;
}

bool Autobot::isGuardianMode() const
{
    return _guardianMode;
}

void Autobot::rollOut()
{
    std::cout << "Autobot rolling out!" << std::endl;
}

void Autobot::transform()
{
    std::cout << "Autobot: transforming into a truck!" << std::endl;
}

void Autobot::openFire()
{
    std::cout << "Autobot: Shooting lazers with empathy!" << std::endl;
    _weapon.fire();
}

void Autobot::ultraMove()
{
    std::cout << "Autobot: Using Jetpack!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Autobot& a)
{
    os << "Autobot(Level: " << a._level
       << ", Empathy: " << a._empathy << ")";
    return os;
}
