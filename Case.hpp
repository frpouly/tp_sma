#ifndef _CASE_HPP_
#define _CASE_HPP_

#include "Agent.hpp"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

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
		void afficher();
		static int distance(Case c1, Case c2);
		~Case();
};

#endif