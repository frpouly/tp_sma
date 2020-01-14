#ifndef _CASE_HPP_
#define _CASE_HPP_

#include "Agent.hpp"
#include "Board.hpp"

class Case
{
	private:
		Agent * occupant;
		Board board;
	public:
		Case(Board &board);
		Case(const Case &c);
		bool addAgent(Agent * agent);
		~Case();
};

#endif