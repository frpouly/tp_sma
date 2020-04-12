#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include <vector>
#include <iostream>

class Case;

class Agent{
	protected:
        /**
         * @var La force de l'agent
         */
        int force;
        int dureeDeVie;
        Case * currentCase;
        int sizeMooreNeighboorhood;
    public:

        /**
         * Cette methode est appelee a chaque tour par le jeu. Elle definit les deplacements et ce que fait l'Agent
         * 
         * @param mooreNeighboorhood Le voisinage de Moore de l'agent
         */
        virtual void live(std::vector<std::vector<Case *>> mooreNeighboorhood) = 0;
        Agent();
        Agent(const Agent &a);

        /**
         * Le constructeur d'un Agent.
         * 
         * @param f La force dont disposera l'agent
         * @param dDV La duree de vie de l'agent
         * @param sizeMooreNeighboorhood La taille du voisinage de Moore que l'agent verra
         */
        Agent(int f, int dDV, int sizeMooreNeighboorhood);

        /**
         * Permet de connaitre la force d'un agent.
         * 
         * @return la force de l'agent
         */
        int getForce();

        /**
         * Connaitre la duree de vie restante d'un agent
         * 
         * @return sa duree de vie restante
         */
        int getDureeDeVie();

        /**
         * Modifier la force de l'agent
         * 
         * @param nf La nouvelle valeur de la force de l'agent
         */
        void setForce(int nf);

        /**
         * Modifier la duree de vie de l'agent
         * 
         * @param ndDv la nouvelle duree de vie de l'agent
         */
        void setDureeDeVie(int ndDV);

        /**
         * Retourne la case actuelle de l'agent
         * 
         * @return NULL si il n'est pas sur une @class Case, un pointeur vers une @class Case sinon
         */
        Case * getCase();

        /**
         * Modifier la case actuelle de l'agent
         * 
         * @param nCase Un pointeur vers une @class Case
         */
        void setCase(Case * nCase);

        /**
         * Permet de faire mourir l'agent
         */
        void mourir();

        /**
         * Savoir si un agent est encore en vie
         * 
         * @return true si il est en vie, false si il est mort
         */
        bool isAlive();

        /**
         * Connaitre la taille du voisinage de Moore
         * 
         * @return la taille du voisinage de Moore
         */
        int getSizeMooreNeighboorhood();

        /**
         * Affichage de l'agent
         */
		virtual char affichageA() = 0;
};

#endif
