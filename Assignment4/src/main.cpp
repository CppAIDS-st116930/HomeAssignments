// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include <iostream>
#include <vector>
#include "autobot.h"
#include "decepticon.h"
#include "minicon.h"

int main()
{
    Weapon cannon(50, 10);
    
    Autobot prime(10, 500, 300, cannon, 100, true);
    Decepticon megatron(10, 510, 290, cannon, 100, false);
    MiniCon sparkplug(1, 20, 10, cannon, 1, false);

    std::cout << prime << std::endl;
    std::cout << megatron << std::endl;

    std::vector<Transformer*> squad;
    squad.push_back(&prime);
    squad.push_back(&megatron);
    squad.push_back(&sparkplug);

    for (Transformer* t : squad) 
    {
        t->transform();
        t->openFire();
    }

    return 0;
}
