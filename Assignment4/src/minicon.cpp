// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include "minicon.h"

MiniCon::MiniCon()
    : Transformer(), _sizeClass(0), _isLinked(false)
{
}

MiniCon::MiniCon(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon, unsigned int sizeClass, bool isLinked)
    : Transformer(level, strength, fuel, weapon), _sizeClass(sizeClass), _isLinked(isLinked)
{
}

unsigned int MiniCon::getSizeClass() const
{
    return _sizeClass;
}

bool MiniCon::isLinked() const
{
    return _isLinked;
}

void MiniCon::powerLink()
{
    _isLinked = !_isLinked;
}

void MiniCon::transform()
{
    std::cout << "MiniCon: transforming into a weapon!" << std::endl;
}

void MiniCon::openFire()
{
    std::cout << "MiniCon: Zap!" << std::endl;
    _weapon.fire();
}

void MiniCon::ultraMove()
{
    std::cout << "MiniCon: Hitching a ride!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const MiniCon& m)
{
    os << "MiniCon(Level: " << m._level
       << ", Size: " << m._sizeClass << ")";
    return os;
}
