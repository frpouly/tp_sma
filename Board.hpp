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
		/**
		 * Le constructeur de @class Board
		 * 
		 * @param taille La taille du plateau
		 */
		Board(int taille);
		Board();
		Board(const Board &b);
		
		/**
		 * @return La taille du plateau
		 */ 
		int getTaille();

		/**
		 * Calculer le voisinage de Moore
		 * 
		 * @return Le voisinage de Moore
		 */
		std::vector<std::vector<Case *>> mooreNeighborhood(int x, int y, int size);
		
		/**
		 * Afficher le voisinage de Moore
		 * 
		 * @param mooreNeighborhood Le voisinage de Moore
		 * @param size La taille du voisinage
		 */
		static void displayMooreNeighborhood(std::vector<std::vector<Case *>> mooreNeighborhood, int size);
		
		/**
		 * Afficher le plateau sur la console
		 */
		void afficher();

		/**
		 * Ajouter un @class Agent au plateau
		 * 
		 * @param agent l'agent a ajouter
		 * @param x sa position en x
		 * @param y sa position en y
		 */
		bool addAgent(Agent * agent, int x, int y);

		/**
		 * Renvoyer une case en connaissant son indice
		 * 
		 * @param x les coordonnees en x de la case
		 * @param y les coordonnees en y de la case
		 */
		Case * getCase(int x, int y);
		~Board();
};

#endif