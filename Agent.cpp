#include "Agent.hpp"
#include "Case.hpp"

Agent::Agent(int f, int dDV): 
    force(f), 
    dureeDeVie(dDV), 
    currentCase(NULL) 
{}

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
    //~Agent();    
}

void Agent::setCase(Case * nCase){
    nCase->addAgent(this);
    if(currentCase != NULL) 
    {
        currentCase->removeAgent();
    }
    currentCase=nCase;    
}
