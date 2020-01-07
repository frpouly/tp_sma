#ifndef _BOARD_HPP_
#define _BOARD_CPP_

#include "Case.hpp"

class Board
{
	private:
		int taille;
		Case **board;
	public:
		Board(int taille);
		~Board();
};

#endif