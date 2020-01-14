#include "Agent.h"

Agent(int f, int dDV): force(f), dureeDeVie(dDV){}

int getForce(){
    return force;
}

int getDureeDeVie(){
    return dureeDeVie;
}

void setForce(int nf){
    f = nf;
}

void setDureeDeVie(int dDV){
    dureeDeVie = dDV;
}