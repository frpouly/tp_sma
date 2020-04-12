#ifndef _SURVIVANT_HPP_
#define _SURVIVANT_HPP_

#include "Case.hpp"
#include "Rand.hpp"
#include "Zombie.hpp"
#include "Game.hpp"
#include <iostream>

class Zombie;

class Survivant : public Agent{
    float tauxRepro;
    int killCount;
    public:
        Survivant();
        Survivant(const Survivant &s);
        Survivant(int tr, int f, int ddv);
        void Attaquer(Zombie& z);
        void attaquer(Zombie * z);
        void live(std::vector<std::vector<Case *>> mooreNeighboorhood) override;
        float getTauxRepro();
        void reproduire(std::vector<std::vector<Case *>> mooreNeighboorhood);
        int getKillCount();
        void setTauxRepro(float tR);
        char affichageA() override;
        void setKillCount(int kC);
        std::vector<std::vector<int>> coeff_voisin(std::vector<std::vector<Case *>> mooreNeighboorhood);
};

#endif