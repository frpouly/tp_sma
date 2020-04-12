#include "Agent.hpp"
#include "Case.hpp"

Agent::Agent() :
    force(1), 
    dureeDeVie(5), 
    currentCase(NULL),
    sizeMooreNeighboorhood(1)
{}

Agent::Agent(const Agent &a) : 
    force(a.force),
    dureeDeVie(a.dureeDeVie),
    currentCase(a.currentCase),
    sizeMooreNeighboorhood(a.sizeMooreNeighboorhood)
{}

Agent::Agent(int f, int dDV, int sizeMooreNeighboorhood): 
    force(f), 
    dureeDeVie(dDV), 
    currentCase(NULL),
    sizeMooreNeighboorhood(sizeMooreNeighboorhood)
{}

bool Agent::isAlive()
{
    return currentCase != NULL;
}

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

void Agent::mourir(){
    currentCase->removeAgent();
    currentCase = NULL;
}

int Agent::getSizeMooreNeighboorhood()
{
    return sizeMooreNeighboorhood;
}

void Agent::setCase(Case * nCase){
    if(currentCase != NULL)
        currentCase->removeAgent();
    currentCase = nCase;
}
