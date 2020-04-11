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
		Case ** board;
	public:
		Board(int taille);
		Board();
		Board(const Board &b);
		int getTaille();
		std::vector<std::vector<Case *>> mooreNeighborhood(int x, int y);
		static void displayMooreNeighborhood(std::vector<std::vector<Case *>> mooreNeighborhood, int size);
		void afficher();
		bool addAgent(Agent * agent, int x, int y);
		Case * getCase(int x, int y);
		~Board();
};

#endif