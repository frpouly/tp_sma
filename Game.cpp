#include "Game.hpp"

bool Game::alreadyCreated = false;
Game * Game::game = NULL;

Game::Game(int taille, int nbZombies, int nbSurvivants)
{
    if (alreadyCreated)
    throw std::logic_error("Vous ne pouvez pas créer une seconde instance de la classe Singleton.");

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
    
    alreadyCreated = true;
    game = this;
}

Board Game::getBoard()
{
    return board;
}

void Game::live(int nbTours)
{
    for(int i = 0; i < nbTours; i++)
    {
        for(Agent *a : agents)
        {
            auto mooreNeighborhood = board.mooreNeighborhood(a->getCase()->getPosX(), a->getCase()->getPosY(), a->getSizeMooreNeighboorhood());
            Board::displayMooreNeighborhood(mooreNeighborhood, a->getSizeMooreNeighboorhood());
            a->live(mooreNeighborhood);
        }
        std::cout<<std::endl<<std::endl<<"Nouveau Tour"<<std::endl;
        board.afficher();
    }
}

/* A fixer, fuite memoire pour l'instant */
Game::~Game()
{
    alreadyCreated = false;
}