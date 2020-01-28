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
    if(occupant!=NULL){
        delete(occupant);
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

