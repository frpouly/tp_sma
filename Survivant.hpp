#include "Zombie.h"
#include "Case.h"

class Zombie;

class Survivant : public Agent{
    float tauxRepro;
    int killCount;
    public:
    void Attaquer(Zombie& z);
    void live(std::vector<std::vector<Case *>> mooreNeighboorhood)
    Survivant(int tr, int kc, int f, int ddv);
    float getTauxRepro();
    int getKillCount();
    void setTauxRepro(float tR);
    char affichageA();
    void setKillCount(int kC);
};
