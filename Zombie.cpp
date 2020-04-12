#include "Zombie.hpp"

Zombie::Zombie(int f, int ddv) : Agent(f, ddv, 2)
{}

void Zombie::manger(Survivant& s){
    long res = genrand_real1();
}

void Zombie::live(std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    int x = getCase()->getPosX();
    int y = getCase()->getPosY();
    int max = sizeMooreNeighboorhood * 2 + 1;
    int nbCanGo, nbHumans;
    nbCanGo = nbHumans = 0;
    std::vector<int> xHumans;
    std::vector<int> yHumans;
    std::vector<Case *> canGo;
    for(int i = 0; i < max; i++)
    {
        for(int j = 0; j < max; j++)
        {
            if(mooreNeighboorhood[i][j] != NULL)
            {
                if(mooreNeighboorhood[i][j]->isAgent())
                {
                    if(mooreNeighboorhood[i][j]->getOccupant()->affichageA() == 'O')
                    {
                        xHumans.push_back(i);
                        yHumans.push_back(j);
                        nbHumans++;
                    } 
                } else if(Case::distance(*mooreNeighboorhood[i][j], Case(x, y)) == 1)
                {
                    canGo.push_back(mooreNeighboorhood[i][j]);
                    nbCanGo++;
                }
            }
        }
    }
    if(nbHumans > 0)
    {
        move(xHumans, yHumans, nbHumans, mooreNeighboorhood);
    } else {
        canGo[genrand_int31()%nbCanGo]->addAgent(this);
    }
}

void Zombie::move(std::vector<int> & xHumans, std::vector<int> & yHumans, int nbHumans, std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    int closestX = xHumans[0];
    int closestY = yHumans[0];
    Case current = Case(sizeMooreNeighboorhood, sizeMooreNeighboorhood);
    int shorter = Case::distance(Case(xHumans[0], yHumans[0]), current);
    for(int i = 1; i < nbHumans; i++)
    {
        int newDistance = Case::distance(Case(xHumans[i], yHumans[i]), current);
        if(newDistance < shorter)
        {
            shorter = newDistance;
            closestX = xHumans[i];
            closestY = yHumans[i];
        }
    }
    moveTo(closestX, closestY, shorter, mooreNeighboorhood);
}

void Zombie::moveTo(int x, int y, int distance, std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    int xMooreNeighboorhood;
    int yMooreNeighboorhood;
    xMooreNeighboorhood = (x > getCase()->getPosX()) ? sizeMooreNeighboorhood + 1 : sizeMooreNeighboorhood - 1;
    yMooreNeighboorhood = (y > getCase()->getPosY()) ? sizeMooreNeighboorhood + 1 : sizeMooreNeighboorhood - 1;
    if(distance == 1)
    {
        attaquer(mooreNeighboorhood[x][y]->getOccupant());
    } else {
        if(!mooreNeighboorhood[xMooreNeighboorhood][yMooreNeighboorhood]->isAgent())
            mooreNeighboorhood[xMooreNeighboorhood][yMooreNeighboorhood]->addAgent(this);
    }
}

void Zombie::attaquer(Agent * s)
{
    if (force * genrand_real3() > s->getForce() * genrand_real3())
    {
        Case * temp = s->getCase();
        Zombie *z = new Zombie(1,10);
        temp->addAgent(z);
        s->mourir();
        Game::game->agents.push_back(z);
    } else {
        mourir();
    }
}

Zombie::Zombie(int tSM) : Agent(FORCE, 0, 2), tempsSansManger(tSM) {}

int Zombie::getTempsSansManger(){
    return tempsSansManger;
}

void Zombie::setTempsSansManger(int ntSM){
    tempsSansManger = ntSM;
}

char Zombie::affichageA()
{
    return 'X';
}