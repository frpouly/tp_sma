#include "Board.hpp"

Board::Board(int taille) : taille(taille)
{
	board = (Case **) malloc (taille * sizeof(Case *));
	for(int i = 0; i < taille; i++)
	{
		board[i] = (Case *) malloc (taille * sizeof(Case));
	}
}

Board::~Board()
{
	for(int i = 0; i < taille; i++)
	{
		free(board[i]);
	}
	free(board);
}