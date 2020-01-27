#include "Agent.hpp"

Agent::Agent(int f, int dDV): force(f), dureeDeVie(dDV){}

int Agent::getForce(){
    return force;
}

int Agent::getDureeDeVie(){
    return dureeDeVie;
}

void Agent::setForce(int nf){
    force = nf;
}

void Agent::setDureeDeVie(int dDV){
    dureeDeVie = dDV;
}

Case * Agent::getCase(){
    return currentCase;
}

void Agent::setCase(Case * nCase){
    currentCase=nCase;
}