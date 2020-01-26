#ifndef _BOARD_HPP_
#define _BOARD_CPP_

#include "Case.hpp"
#include <vector>
#include <cstdlib>

#define SIZE_MOORE_NEIGHBORHOOD 1

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
		~Board();
};

#endif