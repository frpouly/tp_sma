#include "Board.hpp"

Board::Board(int taille) : taille(taille)
{
	for(int i = 0; i < taille; i++)
	{
		for(int j; j < taille; j++)
		{
			board[i][j] = Case(*this, i, j);
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

std::vector<std::vector<Case *>> Board::mooreNeighborhood(int x, int y)
{
	std::vector<std::vector<Case *>> vector;
	int taille = 2 * SIZE_MOORE_NEIGHBORHOOD + 1;
	int ib = x - SIZE_MOORE_NEIGHBORHOOD;
	int jb = y - SIZE_MOORE_NEIGHBORHOOD;
	for(int i = 0; i < taille; i++)
	{
		for(int j = 0; j < taille; j++)
		{
			try 
			{
				vector[i][j] = &board.at(ib).at(jb);
			}
			catch (const std::exception exception) {
				vector[i][j] = NULL;
			}
			jb++;
		}
		ib++;
	}
	return vector;
}

Board::~Board()
{
}