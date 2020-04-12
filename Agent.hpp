#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include <vector>
#include <iostream>

class Case;

class Agent{
	protected:
        int force;
        int dureeDeVie;
        Case * currentCase;
        int sizeMooreNeighboorhood;
    public:
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
        Case * getCase();
        void setCase(Case * nCase);
        void mourir();
        bool isAlive();
        int getSizeMooreNeighboorhood();
		virtual char affichageA() = 0;
};

#endif
