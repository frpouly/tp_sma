#ifndef _SURVIVANT_HPP_
#define _SURVIVANT_HPP_

#include "Survivant.h"

Survivant::Survivant(int tr, int kc, int f, int ddv) : Agent(f,ddv), tauxRepro(tr), killCount(kc)
{
}

void Survivant::Attaquer(Zombie& z)
{
    //Combat entre le survivant et le zombie
    //Tirage en boucle de la force du survivant, randomisée et boostée par le killCount, soustraite aux pv du zombie
    //Riposte du zombie jusqu'à mort de l'un des participants
    //Si zombie gagne, le survivant crée un zombie, lui "donne" sa case et meurt
    //Sinon, le zombie meurt et le survivant se déplace sur la case vide
    if (force * (1 + killCount * 0.1) * genrand_real32() >= z.getForce() * genrand_real32());//humain gagne
}

void Survivant::live(std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    /*
    Découverte des voisins de Moore
    Si partenaire survivant, test sur taux de repro et spawn d'un nouveau Survivant
    Se déplace (en cherchant à rester à coté d'un survivant) et sans être en voisinage de danger
    Si il ne peut pas, il doit Attaquer un zombie
    Si il gagne, il se déplace
    */
    for(int i=0; i < SIZE_MOORE_NEIGHBORHOOD)

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

#endif