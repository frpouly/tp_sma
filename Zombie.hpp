#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include "Agent.hpp"
#include "Rand.hpp"
#include "Survivant.hpp"
#include "Case.hpp"
#include <map>
#include <iostream>

#define FORCE 40

class Survivant;

#define SIZE_MOORE_NEIGHBORHOOD 2

class Zombie : public Agent{
    int tempsSansManger;
    void move(std::vector<int> & xHumans, std::vector<int> & yHumans, int nbHumans, std::vector<std::vector<Case *>> mooreNeighboorhood);
    void moveTo(int x, int y, int distance, std::vector<std::vector<Case *>> mooreNeighboorhood);

    public:
        Zombie();
        Zombie(Zombie &z);

        /**
         * Le constructeur d'un Survivant.
         * @param f La force dont disposera le zombie
         * @param dDV La duree de vie de le zombie
         */
        Zombie(int f, int ddv);

        /**
         * Fonction d'attaque d'un zombie vers survivant
         * 
         * @param s Le survivant à attaquer
         */
        void attaquer(Agent * s);

        /**
         * Fonction de vie d'un zombie
         * 
         * @param mooreNeighboorhood Le voisinnage de moore du personnage
         */
        void live(std::vector<std::vector<Case *>> mooreNeighboorhood) override;
        
        /**
         * Fonction de pathfinding du zombie lui faisant traquer un survivant à un voisinnage de 2 cases         * 
         */
        void TraquerHumain();

        /**
         * Affichage de l'agent
         * @return un caractère adapté au zombie
         */
        char affichageA() override;

        /**
         * Connaitre le temps sans manger de survivants d'un zombie
         * 
         * @return son temps sans manger d'humain
         */
        int getTempsSansManger();

        /**
         * Modifier le temps sans manger d'un zombie
         * 
         * @param tSM nouveau temps sans manger d'un zombie
         */
        void setTempsSansManger(int tSM);
};

#endif