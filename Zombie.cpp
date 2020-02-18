#include "Zombie.hpp"

Zombie::Zombie(int f, int ddv) : Agent(f, ddv)
{}

void Zombie::manger(Survivant& s){
    long res = genrand_real1();
}

void Zombie::live(std::vector<std::vector<Case *>> &mooreNeighboorhood)
{
    /*int x = getCase()->getPosX();
    int y = getCase()->getPosY();
    int maxX = x + SIZE_MOORE_NEIGHBORHOOD;
    int maxY = y + SIZE_MOORE_NEIGHBORHOOD;
    for(int i = x - SIZE_MOORE_NEIGHBORHOOD; i < maxX; i++)
    {
        for(int j = y - SIZE_MOORE_NEIGHBORHOOD; j < maxY; j++)
        {
            if(j>=0 && i>=0 && j!=y && i!=x)
            {
                if(mooreNeighboorhood[i][j]->getOccupant()->affichageA() == 'O')
                {
                }
            }
        }
    }*/
}

void Zombie::TraquerHumain()
{
    genrand_int31()%9;

}

Zombie::Zombie(int tSM) : Agent(FORCE, 0), tempsSansManger(tSM) {}

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