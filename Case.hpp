#ifndef _CASE_HPP_
#define _CASE_HPP_

#include "Agent.hpp"
#include "Board.hpp"

class Case
{
	private:
		Agent * occupant;
		Board board;
		int posX, posY;
	public:
		Case(Board &board, int x, int y);
		Case(const Case &c);
		bool addAgent(Agent * agent);
		const Agent * getAgent();
		std::vector<std::vector<Case *>> getVoisinageMoore();
		~Case();
};

#endif