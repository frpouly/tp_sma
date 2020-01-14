#include "Case.hpp"

Case::Case(Board &board, int x, int y) : 
    board(board),
    posX(x),
    posY(y)
{}

Case::Case(const Case &c) : 
    occupant(c.occupant), 
    board(c.board),
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

std::vector<std::vector<Case *>> Case::getVoisinageMoore()
{
    return board.mooreNeighborhood(posX, posY);
}

Case::~Case()
{
    delete(occupant);
}