#include "Zombie.hpp"

void Zombie::manger(Survivant& s){
    long res = genrand_real1();
}

void Zombie::live()
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