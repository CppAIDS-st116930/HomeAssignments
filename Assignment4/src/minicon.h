// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#ifndef MINICON_H
#define MINICON_H

#include "transformer.h"
#include <iostream>

class MiniCon : public Transformer
{
public:
    MiniCon();
    MiniCon(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon, unsigned int sizeClass, bool isLinked);

    unsigned int getSizeClass() const;
    bool isLinked() const;
    void powerLink();

    // Overrides
    void transform() override;
    void openFire() override;
    void ultraMove() override;

    friend std::ostream& operator<<(std::ostream& os, const MiniCon& m);

private:
    unsigned int _sizeClass;
    bool _isLinked;
};

#endif
