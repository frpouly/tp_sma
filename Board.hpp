#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Case.hpp"
#include "Agent.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>

class Board
{
	private:
		int taille;
		std::vector<std::vector<Case>> board;
	public:
		Board(int taille);
		Board();
		Board(const Board &b);
		const int getTaille();
		std::vector<std::vector<Case *>> mooreNeighborhood(int x, int y);
		void afficher();
		bool addAgent(Agent * agent, int x, int y);
		Case * getCase(int x, int y);
		~Board();
};

#endif