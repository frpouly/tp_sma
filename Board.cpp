#include "Board.hpp"

Board::Board(int taille) : taille(taille)
{
	board = (Case **) malloc (taille * sizeof(Case *));
	for(int i = 0; i < taille; i++)
	{
		board[i] = (Case *) malloc (taille * sizeof(Case));
	}
}

Board::Board(const Board &b) : taille(b.taille)
{
	board = (Case **) malloc (taille * sizeof(Case *));
	for(int i = 0; i < taille; i++)
	{
		board[i] = (Case *) malloc (taille * sizeof(Case));
	}
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
	for(int i = 0; i < taille; i++)
	{
		free(board[i]);
	}
	free(board);
}