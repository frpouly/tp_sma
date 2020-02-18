#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include "Agent.hpp"
#include "Rand.hpp"
#include "Case.hpp"
#include "Board.hpp"
#include <map>
#include <iostream>

#define FORCE 40

class Survivant;

class Zombie : public Agent{
    int tempsSansManger;

    public:
        Zombie();
        Zombie(int f, int ddv);
        void manger(Survivant& s);
        void live(std::vector<std::vector<Case *>> &mooreNeighboorhood) override;
        void traquerHumain(int xHuman, int yHuman, std::vector<std::vector<Case *>> mooreNeighboorhood);
        Zombie(int tSM);
        char affichageA() override;
        int getTempsSansManger();
        void setTempsSansManger(int tSM);
};

#endif