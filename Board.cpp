#include "Board.hpp"

Board::Board() : taille(0)
{}

Board::Board(int taille) : taille(taille)
{
	board = (Case **) malloc (taille * sizeof(Case *));
	for(int i = 0; i < taille; i++)
	{
		board[i] = (Case *) malloc (taille * sizeof(Case));
		for(int j = 0; j < taille; j++)
		{
			board[i][j] = Case(i, j);
		}
	}
}

Board::Board(const Board &b) : taille(b.taille)
{
	board = (Case **) malloc (taille * sizeof(Case *));
	for(int i = 0; i < taille; i++)
	{
		board[i] = (Case *) malloc (taille * sizeof(Case));
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
std::vector<std::vector<Case *>> Board::mooreNeighborhood(int x, int y, int size)
{
	std::vector<std::vector<Case *>> vector;
	int taille_moore = 2 * size + 1;
	int ib = x - size;
	int jb = y - size;

	for(int i = ib; i < ib + taille_moore; i++)
	{
		std::vector<Case *> v;
		for(int j = jb; j < jb + taille_moore; j++)
		{
			if(j >= 0 && i >= 0 && i < taille && j < taille)
			{
				v.push_back(&board[i][j]);
			} else 
			{
				v.push_back(NULL);
			}
		}
		vector.push_back(v);
	}
	return vector;
}

void Board::displayMooreNeighborhood(std::vector<std::vector<Case *>> mooreNeighborhood, int size)
{
	int max = size * 2 + 1;
	std::cout << "Moore Neighborhood : " << std::endl;
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max; j++)
		{
			if(mooreNeighborhood[i][j] == NULL)
			{
				std::cout << "N";
			} else
			{
				mooreNeighborhood[i][j]->afficher();
			}
		}
		std::cout << std::endl;
	}
}

int Board::getTaille() {
	return taille;
}

void Board::afficher() {
	int t = getTaille();
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			board[i][j].afficher();
			std::cout<<' ';
		}
		std::cout << std::endl;
	}
}

/* Essaye d'ajouter un agent à une case, renvoit false si la case est déjà occupée */
bool Board::addAgent(Agent * agent, int x, int y)
{
	bool ret = true;
	if(getCase(x, y)->isAgent())
		return false;
	else
		getCase(x, y)->addAgent(agent);
	return ret;
}

Board::~Board()
{
}