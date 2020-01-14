#include "Survivant.h"

Survivant::Survivant(int tr, int kc, int f, int ddv) : Agent(f,ddv), tauxRepro(tr), killCount(kc)
{
}

void Survivant::Attaquer(Zombie& z)
{

}

void Survivant::live()
{
    /*
    Découverte des voisins de Moore
    Si partenaire survivant, test sur taux de repro et spawn d'un nouveau Survivant
    Se déplace (en cherchant à rester à coté d'un survivant) et sans être en voisinage de danger
    Si il ne peut pas, il doit Attaquer un zombie
    Si il gagne, il se déplace
    */
}

float Survivant::getTauxRepro()
{
    return tauxRepro;
}

int Survivant::getKillCount()
{
    return killCount;
}

void Survivant::setTauxRepro(float tR)
{
    tauxRepro = tr;
}

void Survivant::setKillCount(int kC)
{
    killCount = kc;
}