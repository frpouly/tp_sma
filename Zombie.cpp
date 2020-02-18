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
    int max = SIZE_MOORE_NEIGHBORHOOD * 2 + 1;
    int nbHumans = 0;
    std::vector<int> xHumans;
    std::vector<int> yHumans;
    for(int i = 0; i < max; i++)
    {
        for(int j = 0; j < max; j++)
        {
            if(mooreNeighboorhood[i][j]!=NULL)
            {
                if(mooreNeighboorhood[i][j]->isAgent())
                {
                    if(mooreNeighboorhood[i][j]->getOccupant()->affichageA() == 'O')
                    {
                        xHumans.push_back(i);
                        yHumans.push_back(j);
                        nbHumans++;
                    }
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