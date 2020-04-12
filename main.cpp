#include "Board.hpp"
#include "Game.hpp"
#include "Survivant.hpp"

int main(int argc, char ** argv)
{
	Game g = Game(10, 15, 15);
	g.getBoard().afficher();
	g.live(100);
	/*
	int nbTours=0;
	Board b = Board(10);
	Case * c = b.getCase(4, 4);
	Survivant *s = new Survivant(2, 2, 2); 
	Zombie *z = new Zombie(2);
	c->addAgent(s);
	std::cout<<"test"<<std::endl;
	c = b.getCase(6,6);
	c->addAgent(z);
	b.afficher();

	while(nbTours<3)
	{
		std::cout<<"----------"<<std::endl;
		s->live(b.mooreNeighborhood(s->getCase()->getPosX(),s->getCase()->getPosY()));
		z->live(b.mooreNeighborhood(z->getCase()->getPosX(),z->getCase()->getPosY()));
		b.afficher();
		nbTours++;
	}
	*/
	return 0;
}