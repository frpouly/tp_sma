#ifndef _SURVIVANT_HPP_
#define _SURVIVANT_HPP_

#include "Case.hpp"
#include "Rand.hpp"
#include "Zombie.hpp"
#include "Game.hpp"
#include <iostream>

class Zombie;

class Survivant : public Agent{
    float tauxRepro;
    int killCount;
    public:
        Survivant();
        Survivant(const Survivant &s);

        /**
         * Le constructeur d'un Survivant.
         * @param tr le taux de reproduction d'un Survivant
         * @param f La force dont disposera le Survivant
         * @param dDV La duree de vie de le Survivant
         */
        Survivant(int tr, int f, int ddv);

        /**
         * Fonction d'attaque d'un survivant vers un zombie
         * 
         * @param z Le zombie à attaquer
         */
        void attaquer(Zombie * z);

        /**
         * Fonction de vie d'un survivant
         * 
         * @param mooreNeighboorhood Le voisinnage de moore du personnage
         */
        void live(std::vector<std::vector<Case *>> mooreNeighboorhood) override;
        
        /**
         * Connaitre le taux de reproduction d'un survivant
         * 
         * @return sa duree de vie restante
         */
        float getTauxRepro();

        /**
         * Fonction de reproduction d'un agent
         * 
         * @param mooreNeighboorhood voisinnage de moore du survivant
         */
        void reproduire(std::vector<std::vector<Case *>> mooreNeighboorhood);
        
        /**
         * Connaitre le nombre de tués d'un survivants
         * 
         * @return son nombre de zombies tués
         */
        int getKillCount();

        /**
         * Modifier le taux de reproduction de l'agent
         * 
         * @param tr le nouveau taux de reproduction de l'agent
         */
        void setTauxRepro(float tR);

        /**
         * Affichage de l'agent
         * @return un caractère adapté au survivant
         */
        char affichageA() override;

        /**
         * Modifier le nombre de tués d'un survivant
         * 
         * @param kc le nouveau nombre de tués d'un survivant
         */
        void setKillCount(int kC);

        /**
         * Fonction de pathfinding du survivant lui faisant choisir la case la moins risquée pour se déplacer
         * 
         * @param mooreNeighboorhood voisinnage de moore
         * @return des vecteurs d'entiers correspondants aux taux de risques
         */
        std::vector<std::vector<int>> coeff_voisin(std::vector<std::vector<Case *>> mooreNeighboorhood);
};

#endif