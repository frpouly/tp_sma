#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include "Agent.hpp"
#include "Rand.hpp"
#include "Survivant.hpp"
#include "Case.hpp"
#include <map>
#include <iostream>

#define FORCE 40

class Survivant;

#define SIZE_MOORE_NEIGHBORHOOD 2

class Zombie : public Agent{
    int tempsSansManger;
    void move(std::vector<int> & xHumans, std::vector<int> & yHumans, int nbHumans, std::vector<std::vector<Case *>> mooreNeighboorhood);
    void moveTo(int x, int y, int distance, std::vector<std::vector<Case *>> mooreNeighboorhood);

    public:
        Zombie();
        Zombie(Zombie &z);
        Zombie(int f, int ddv);
        void attaquer(Agent * s);
        void live(std::vector<std::vector<Case *>> mooreNeighboorhood) override;
        void TraquerHumain();
        Zombie(int tSM);
        char affichageA() override;
        int getTempsSansManger();
        void setTempsSansManger(int tSM);
};

#endif