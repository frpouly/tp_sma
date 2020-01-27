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
        ret = true;
    } else 
    {
        ret = false;
    }
    return ret;
}

bool Case::isAgent()
{
    return occupant != NULL;
}

Agent * Case::getOccupant()
{
    return occupant;
}

Case::~Case()
{
    delete(occupant);
}