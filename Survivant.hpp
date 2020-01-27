#ifndef _SURVIVANT_HPP_
#define _SURVIVANT_HPP_

#include "Case.hpp"
#include "Rand.hpp"
#include "Zombie.hpp"

class Survivant : public Agent{
    float tauxRepro;
    int killCount;
    public:
        Survivant();
        Survivant(int tr, int f, int ddv);
        void Attaquer(Zombie& z);
        void live(std::vector<std::vector<Case *>> mooreNeighboorhood) override;
        float getTauxRepro();
        int getKillCount();
        void setTauxRepro(float tR);
        char affichageA();
        void setKillCount(int kC);
};

#endif