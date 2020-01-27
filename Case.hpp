#ifndef _CASE_HPP_
#define _CASE_HPP_

#include "Agent.hpp"
#include <vector>
#include <iostream>

class Case
{
	private:
		Agent * occupant = nullptr;
		int posX, posY;
	public:
		Case(int x, int y);
		Case(const Case &c);
		bool addAgent(Agent * agent);
		bool isAgent();
		Agent * getOccupant();
		void removeAgent();
		int getPosX();
		int getPosY();

		~Case();
};

#endif