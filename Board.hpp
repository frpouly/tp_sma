#ifndef _BOARD_HPP_
#define _BOARD_CPP_

#include "Case.hpp"
#include <cstdlib>

class Board
{
	private:
		int taille;
		Case **board;
	public:
		Board(int taille);
		Board(const Board &b);
		~Board();
};

#endif