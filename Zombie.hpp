#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include "Agent.hpp"
#include "Rand.hpp"

#define FORCE 40

class Survivant;

class Zombie : public Agent{
    int tempsSansManger;

    public:
    void manger(Survivant& s);
    void live();
    void TraquerHumain();
    Zombie(int tSM);
    char affichageA();
    int getTempsSansManger();
    void setTempsSansManger(int tSM);
};

#endif