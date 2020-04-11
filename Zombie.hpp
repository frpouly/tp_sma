#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include "Agent.hpp"
#include "Rand.hpp"
#include "Case.hpp"
#include <map>
#include <iostream>

#define FORCE 40

class Survivant;

class Zombie : public Agent{
    int tempsSansManger;
    void move(std::vector<int> & xHumans, std::vector<int> & yHumans);

    public:
        Zombie();
        Zombie(int f, int ddv);
        void manger(Survivant& s);
        void live(std::vector<std::vector<Case *>> mooreNeighboorhood) override;
        void TraquerHumain();
        Zombie(int tSM);
        char affichageA() override;
        int getTempsSansManger();
        void setTempsSansManger(int tSM);
};

#endif