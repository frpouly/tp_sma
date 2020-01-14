#include "Case.hpp"

Case::Case(Board &board) : board(board)
{}

Case::Case(const Case &c) : occupant(c.occupant), board(c.board)
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

Case::~Case()
{
    delete(occupant);
}