#include "Zombie.hpp"

Zombie::Zombie(int f, int ddv) : Agent(f, ddv)
{}

void Zombie::manger(Survivant& s){
    long res = genrand_real1();
}

void Zombie::live(std::vector<std::vector<Case *>> mooreNeighboorhood)
{
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