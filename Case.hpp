#ifndef _CASE_HPP_
#define _CASE_HPP_

#include "Agent.hpp"
#include <vector>

class Case
{
	private:
		Agent * occupant;
		int posX, posY;
	public:
		Case(int x, int y);
		Case(const Case &c);
		bool addAgent(Agent * agent);
		bool isAgent();
		Agent * getOccupant();
		~Case();
};

#endif