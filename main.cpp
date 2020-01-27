#include "Board.hpp"
#include "Survivant.hpp"

int main(int argc, char ** argv)
{
	Board b = Board(10);
	Case * c = b.getCase(4, 4);
	c->addAgent(new Survivant(2, 2, 2));
	b.afficher();
	return 0;
}