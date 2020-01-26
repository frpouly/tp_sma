#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include "Survivant.h"

#define FORCE 40

class Survivant;

class Zombie : public Agent{
    int tempsSansManger;

    public:
    void Manger(Survivant& s);
    void live();
    void TraquerHumain();
    Zombie(int tSM);
    int getTempsSansManger();
    void setTempsSansManger(int tSM);
};

#endif