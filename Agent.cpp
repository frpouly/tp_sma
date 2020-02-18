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

void Agent::setCase(Case * nCase){
    nCase->addAgent(this);
    if(currentCase != NULL) 
    {
        currentCase->removeAgent();
    }
    currentCase=nCase;    
}   

int Agent::getPosX()
{
    return currentCase->getPosX();
}

int Agent::getPosY()
{
    return currentCase->getPosY();
}

void Agent::moveRandomly(std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    if ( getCase()->getPosX() == 0 && getCase()->getPosY() == 0)
    {
        mooreNeighboorhood[(genrand_int31()%2) + 1][(genrand_int31()%2) + 1]->addAgent(this);
    } 
    else if(getCase()->getPosX() != 0 && getCase()->getPosY() == 0 )
    {        
        mooreNeighboorhood[genrand_int31()%3][(genrand_int31()%2) + 1]->addAgent(this);
    } 
    else if(getCase()->getPosX() == 0 && getCase()->getPosY() != 0 )
    {        
        mooreNeighboorhood[(genrand_int31()%2) + 1][genrand_int31()%3]->addAgent(this);
    }
    else
    {        
        mooreNeighboorhood[genrand_int31()%3][genrand_int31()%3]->addAgent(this);
    }
}

