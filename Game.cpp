#include "Game.hpp"

Game::Game(const Game& g) : board(g.board), agents(g.agents)
{}

Game::Game(int taille, int nbZombies, int nbSurvivants)
{
    int x, y;
    board = Board(taille);
    Agent * agent;
    if(nbZombies + nbSurvivants > taille * taille)
    {
        throw std::invalid_argument("Il n'y a pas assez de case pour héberger tous ces Agents");
    }
    for(int i = 0; i < nbSurvivants; i++)
    {
        bool ok = false;
        while (!ok)
        {
            x = genrand_int32() % (taille);
            y = genrand_int32() % (taille);
            agent = new Survivant(2, 2, 80);
            ok = board.addAgent(agent, x, y);
        }
        agents.push_back(agent);
    }
    for(int i = 0; i < nbZombies; i++)
    {
        bool ok = false;
        while(!ok)
        {
            x = genrand_int32() % (taille);
            y = genrand_int32() % (taille);
            agent = new Zombie(2, 80);
            ok = board.addAgent(agent, x, y);
        }
        agents.push_back(agent);
    }
}

Board Game::getBoard()
{
    return board;
}

void Game::live(int nbTours)
{
    for(Agent *a : agents)
    {
        a->live(board.mooreNeighborhood(a->getCase()->getPosX(), a->getCase()->getPosY()));
    }
}

/* A fixer, fuite memoire pour l'instant */
Game::~Game()
{
}