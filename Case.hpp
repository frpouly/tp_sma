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
		/**
		 * Le constructeur de Case
		 * 
		 * @param x Sa position en x
		 * @param y Sa position en y
		 */
		Case(int x, int y);
		Case(const Case &c);

		/**
		 * Ajouter un agent a la case
		 * 
		 * @param agent l'agent a ajouter
		 */
		bool addAgent(Agent * agent);
		
		/**
		 * Savoir si un agent occupe la case
		 * 
		 * @return true si il y a un occupant, false sinon
		 */
		bool isAgent();
		
		/**
		 * Renvoie un pointeur vers l'occupant de la case
		 * 
		 * @return NULL si il n'y a pas d'occupant, un pointeur vers ce dernier sinon
		 */
		Agent * getOccupant();
		
		/**
		 * Enlever l'agent qui occupe la case
		 */
		void removeAgent();
		
		/**
		 * @return La position en x de la case
		 */
		int getPosX();
		
		/**
		 * @return la postion en y de la case
		 */
		int getPosY();
		
		/**
		 * Afficher la case en console
		 */
		void afficher();
		
		/**
		 * Connaitre la distance entre deux cases
		 * 
		 * @param c1 la premiere case
		 * @param c2 la seconde case
		 * @return la distance de deplacement entre les deux cases
		 */
		static int distance(Case c1, Case c2);
		~Case();
};

#endif