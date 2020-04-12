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
        Agent(int f, int dDV, int sizeMooreNeighboorhood);
        int getForce();
        int getDureeDeVie();
        void setForce(int nf);
        void setDureeDeVie(int ndDV);
        Case * getCase();
        void setCase(Case * nCase);
        void mourir();
        int getSizeMooreNeighboorhood();
		virtual char affichageA() = 0;
};

#endif
