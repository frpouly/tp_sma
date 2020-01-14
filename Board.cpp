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

Board::~Board()
{
}