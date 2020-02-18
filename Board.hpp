#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Case.hpp"
#include "Agent.hpp"
#include <math.h>
#include <vector>
#include <cstdlib>
#include <iostream>

class Board
{
	private:
		int taille;
		Case ** board;
	public:
		Board(int taille);
		Board();
		Board(const Board &b);
		static int calculDistance(int x1, int y1, int x2, int y2);
		int getTaille();
		std::vector<std::vector<Case *>> mooreNeighborhood(int x, int y);
		void afficher();
		bool addAgent(Agent * agent, int x, int y);
		Case * getCase(int x, int y);
		~Board();
};

#endif