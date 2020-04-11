#ifndef _SURVIVANT_HPP_
#define _SURVIVANT_HPP_

#include "Case.hpp"
#include "Rand.hpp"
#include "Zombie.hpp"
#include <iostream>

class Zombie;

class Survivant : public Agent{
    float tauxRepro;
    int killCount;
    public:
        Survivant();
        Survivant(int tr, int f, int ddv);
        void attaquer(Zombie * z);
        void live(std::vector<std::vector<Case *>> mooreNeighboorhood) override;
        float getTauxRepro();
        void reproduire(std::vector<std::vector<Case *>> mooreNeighboorhood);
        int getKillCount();
        void setTauxRepro(float tR);
        char affichageA() override;
        void setKillCount(int kC);
        int ** coeff_voisin(std::vector<std::vector<Case *>> mooreNeighboorhood, int tab[3][3]);
        
};

#endif