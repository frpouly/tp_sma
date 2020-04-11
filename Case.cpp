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
        occupant = NULL;
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
 
void Case::afficher()
{
    if(occupant == NULL)
    {
        std::cout << ".";
    } else
    {
        std::cout << occupant->affichageA();
    }
}

int Case::distance(Case c1, Case c2)
{
    return std::max(std::max(c1.posX, c2.posX) - std::min(c1.posX, c2.posX),
                    std::max(c1.posY, c2.posY) - std::min(c1.posY, c2.posY));
}

Case::~Case()
{
    delete(occupant);
}

