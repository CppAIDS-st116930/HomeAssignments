// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "transformer.h"
#include <iostream>

class Autobot : public Transformer
{
public:
    Autobot();
    Autobot(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon, unsigned int empathy, bool guardianMode);

    unsigned int getEmpathy() const;
    bool isGuardianMode() const;
    void rollOut();

    // Overrides
    void transform() override;
    void openFire() override;
    void ultraMove() override;

    friend std::ostream& operator<<(std::ostream& os, const Autobot& a);

private:
    unsigned int _empathy;
    bool _guardianMode;
};

#endif
