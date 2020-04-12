#include "Board.hpp"
#include "Game.hpp"
#include "Survivant.hpp"

int main(int argc, char ** argv)
{
	Game g = Game(10, 15, 15);
	g.getBoard().afficher();
	g.live(100);
	return 0;
}