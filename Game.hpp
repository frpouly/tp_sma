#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <vector>
#include <iostream>
#include "Board.hpp"
#include "Zombie.hpp"
#include "Survivant.hpp"
#include "Agent.hpp"
#include "Rand.hpp"

class Game 
{
    private:
        Board board;
        static bool alreadyCreated;
    public:
        /**
         * La variable statique de Game, permet de connaitre l'instance unique dans d'autres classes
         */
        static Game * game;

        /**
         * Tous les agents presents dans la simulation
         */
        std::vector<Agent *> agents;

        /**
         * Le constructeur de Game
         * 
         * @param taille La taille du plateau
         * @param nbZombie le nombre de zombies au depart de la partie
         * @param nbSurvivants Le nombre d'humains au depart
         */
        Game(int taille, int nbZombie, int nbSurvivants);

        Game(const Game& g);

        /**
         * Permet de jouer un certain nombre de tours
         *
         * @param nbTours Le nombre de tours que l'on se decide a jouer
         */
        void live(int nbTours);

        /**
         * Revoie le tableau du jeu
         * 
         * @return le @class Board
         */
        Board getBoard();
        ~Game();
};

#endif