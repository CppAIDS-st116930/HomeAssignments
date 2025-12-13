// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "transformer.h"
#include <iostream>

class Decepticon : public Transformer
{
public:
    Decepticon();
    Decepticon(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon, unsigned int malice, bool stealthMode);

    unsigned int getMalice() const;
    bool isStealthMode() const;
    void scheme();

    // Overrides
    void transform() override;
    void openFire() override;
    void ultraMove() override;

    friend std::ostream& operator<<(std::ostream& os, const Decepticon& d);

private:
    unsigned int _malice;
    bool _stealthMode;
};

#endif
