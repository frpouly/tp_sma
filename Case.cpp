#include "Case.hpp"

Case::Case(int x, int y) : 
    posX(x),
    posY(y),
    occupant(NULL)
{}

Case::Case(const Case &c) : 
    occupant(c.occupant),
    posX(c.posX),
    posY(c.posY)
{}

bool Case::addAgent(Agent * agent)
{
    bool ret;
    if(this->occupant == NULL)
    {
        occupant = agent;
        std::cout<<"Added"<<std::endl;
        agent->setCase(this);
        ret = true;
    } else 
    {
        ret = false;
    }
    return ret;
}

void Case::removeAgent(){
    std::cout<< &occupant <<std::endl;
    if(occupant!=NULL){
        occupant = 0;
        delete(occupant);
        //std::cout<< occupant <<std::endl;
        std::cout<<"Bye Case"<<std::endl;
    }
}

bool Case::isAgent()
{
    return occupant != NULL;
}

Agent * Case::getOccupant()
{
    return occupant;
}

int Case::getPosX()
{
    return posX;
}

int Case::getPosY()
{
    return posY;
}

Case::~Case()
{
    delete(occupant);
}

