#include "Zombie.h"

class Zombie;

class Survivant : public Agent{
    float tauxRepro;
    int killCount;
    public:
    void Attaquer(Zombie& z);
    void live();
    Survivant(int tR, int kC);
    float getTauxRepro();
    int getKillCount();
    void setTauxRepro(float tR);
    void setKillCount(int kC);
};
