#include "Board.hpp"

Board::Board(int taille) : taille(taille)
{
	for(int i = 0; i < taille; i++)
	{
		board.push_back(std::vector<Case>());
		for(int j = 0; j < taille; j++)
		{
			board[i].push_back(Case(i, j));
		}
	}
}

Board::Board(const Board &b) : taille(b.taille)
{
	for(int i = 0; i < taille; i++)
	{
		for(int j = 0; j < taille; j++)
		{
			board[i][j] = b.board[i][j];
		}
	}
}

Case * Board::getCase(int x, int y)
{
	if(x >= taille || y >= taille)
		throw new std::out_of_range("L'indice doit être inférieur à la taille");
	return &board[x][y];
}

/* Si par exemple, la case en haut à gauche de la case n'existe pas, on renvoit NULL	*/
std::vector<std::vector<Case *>> Board::mooreNeighborhood(int x, int y)
{
	std::vector<std::vector<Case *>> vector;
	int taille = 2 * SIZE_MOORE_NEIGHBORHOOD + 1;
	int ib = x - SIZE_MOORE_NEIGHBORHOOD;
	int jb = y - SIZE_MOORE_NEIGHBORHOOD;

	vector.reserve(10);

	/*for(int i = 0; i < taille; i++)
	{
			std::cout<<&board.at(ib).at(jb)<<std::endl;
			std::cout<<ib<<jb<<std::endl;
			std::cout<<vector[0][0]<<std::endl;

			std::cout<<ib<<jb<<std::endl;
			
		for(int j = 0; j < taille; j++)
		{
			
			try 
			{
				vector[i][j] = &board.at(ib).at(jb);	//BUG ICI DES LA PREMIERE ITERATION
			}
			catch (const std::exception exception) {
				vector[i][j] = NULL;
			}
			jb++;
		}
		ib++;
	}*/

	std::vector<std::vector<Case *>> mat;
	for (int i = 0; i < 10; i++)
	{
		// construct a vector of int
		std::vector<Case *> v;
		for (int j = 0; j < 10; j++)
			v.push_back(&board.at(ib).at(jb));
	
		// push back above one-dimensional vector
		mat.push_back(v);
	}

	return mat;
}

int Board::getTaille() {
	return taille;
}

void Board::afficher() {
	int t = getTaille();
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			if(!board[j][i].isAgent())
				std::cout << ".";
			else
				std::cout << board[j][i].getOccupant()->affichageA();
		}
		std::cout << std::endl;
	}
}

Board::~Board()
{
}