#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include <vector>
#include <iostream>
#include "Rand.hpp"

class Case;

#define SIZE_MOORE_NEIGHBORHOOD 1

class Agent{
	protected:
        int force;
        int dureeDeVie;
        Case * currentCase;
    public:
        virtual void live(std::vector<std::vector<Case *>> mooreNeighboorhood) = 0;
        Agent(int f, int dDV);
        int getForce();
        int getDureeDeVie();
        void setForce(int nf);
        void moveRandomly(std::vector<std::vector<Case *>> mooreNeighboorhood);
        void setDureeDeVie(int ndDV);
        Case * getCase();
        int getPosX();
        int getPosY();
        void setCase(Case * nCase);
		virtual char affichageA() = 0;
};

#endif
