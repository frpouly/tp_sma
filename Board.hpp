#ifndef _BOARD_HPP_
#define _BOARD_CPP_

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
		Board(const Board &b);
		int getTaille();
		std::vector<std::vector<Case *>> mooreNeighborhood(int x, int y);
		void afficher();
		Case * getCase(int x, int y);
		~Board();
};

#endif