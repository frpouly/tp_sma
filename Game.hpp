#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <vector>
#include "Board.hpp"
#include "Zombie.hpp"
#include "Survivant.hpp"
#include "Agent.hpp"
#include "Rand.hpp"

class Game 
{
    private:
        std::vector<Agent *> agents;
        Board board;
    public:
        Game(int taille, int nbZombie, int nbSurvivants);
        Game(const Game& g);
        void live(int nbTours);
        Board getBoard();
        ~Game();
};

#endif