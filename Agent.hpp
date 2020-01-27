#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include <vector>

class Case;

#define SIZE_MOORE_NEIGHBORHOOD 1

class Agent{
	protected:
        int force;
        int dureeDeVie;
    public:
        virtual void live(std::vector<std::vector<Case *>> mooreNeighboorhood) = 0;
        Agent(int f, int dDV);
        int getForce();
        int getDureeDeVie();
        void setForce(int nf);
        void setDureeDeVie(int ndDV);
		virtual char affichageA() = 0;
};

#endif
