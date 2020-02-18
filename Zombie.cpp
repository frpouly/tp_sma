#include "Zombie.hpp"

Zombie::Zombie(int f, int ddv) : Agent(f, ddv)
{}

void Zombie::manger(Survivant& s){
    long res = genrand_real1();
}

void Zombie::live(std::vector<std::vector<Case *>> &mooreNeighboorhood)
{
    int x = getCase()->getPosX();
    int y = getCase()->getPosY();
    int max = SIZE_MOORE_NEIGHBORHOOD * 2 + 1;
    int nbHumans = 0;
    int distanceClosest = INT32_MAX;
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
                    Agent * humain = mooreNeighboorhood[i][j]->getOccupant();
                    if(humain->affichageA() == 'O')
                    {
                        int distance = Board::calculDistance(getPosX(), getPosY(), humain->getPosX(), humain->getPosY());
                        if(distance < distanceClosest)
                        {
                            distanceClosest = distance;
                            xHumans.clear();
                            yHumans.clear();
                            xHumans.push_back(i);
                            yHumans.push_back(j);
                            nbHumans = 0;
                        } else if(distance == distanceClosest)
                        {
                            xHumans.push_back(i);
                            yHumans.push_back(j);
                            nbHumans++;
                        }
                    }
                }
            }
        }
    }
    int iHumain = genrand_int31()%nbHumans;
    traquerHumain(xHumans[iHumain], yHumans[iHumain], mooreNeighboorhood);
}

void Zombie::traquerHumain(int xHuman, int yHuman, std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    int xDest = SIZE_MOORE_NEIGHBORHOOD;
    int yDest = SIZE_MOORE_NEIGHBORHOOD;
    if(xHuman > SIZE_MOORE_NEIGHBORHOOD)
        xDest++;
    else if(xHuman < SIZE_MOORE_NEIGHBORHOOD)
        xDest--;
    if(yHuman > SIZE_MOORE_NEIGHBORHOOD)
        yDest++;
    else if(yHuman < SIZE_MOORE_NEIGHBORHOOD)
        yDest--;
    mooreNeighboorhood[xDest][yDest]->addAgent(this);
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