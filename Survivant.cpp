#include "Survivant.hpp"

Survivant::Survivant(int tr, int f, int ddv) : Agent(f, ddv, 1), tauxRepro(tr), killCount(0)
{
}

void Survivant::live(std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    int tab[3][3] = {0};
    //coeff_voisin(mooreNeighboorhood, tab);
    /*
    Découverte des voisins de Moore
    Si partenaire survivant, test sur taux de repro et spawn d'un nouveau Survivant
    Se déplace (en cherchant à rester à coté d'un survivant) et sans être en voisinage de danger
    Si il ne peut pas, il doit Attaquer un zombie
    Si il gagne, il se déplace
    */
    bool zombieProche = false;


    if(!zombieProche) {
        if ( getCase()->getPosX() == 0 && getCase()->getPosY() == 0)
        {
            mooreNeighboorhood[(genrand_int31()%2) + 1][(genrand_int31()%2) + 1]->addAgent(this);
        } 
        else if(getCase()->getPosX() != 0 && getCase()->getPosY() == 0 )
        {        
            mooreNeighboorhood[genrand_int31()%3][(genrand_int31()%2) + 1]->addAgent(this);
        } 
        else if(getCase()->getPosX() == 0 && getCase()->getPosY() != 0 )
        {        
            mooreNeighboorhood[(genrand_int31()%2) + 1][genrand_int31()%3]->addAgent(this);
        }
        else
        {        
            //mooreNeighboorhood[genrand_int31()%3][genrand_int31()%3]->addAgent(this);
        }
    }
    reproduire(mooreNeighboorhood);
}

float Survivant::getTauxRepro()
{
    return tauxRepro;
}

int Survivant::getKillCount()
{
    return killCount;
}

void Survivant::setTauxRepro(float tR)
{
    tauxRepro = tR;
}

void Survivant::reproduire(std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    int i=0,j=0;
    Case * naissance=NULL;
    bool partenaire=false;
    while ((naissance == NULL && partenaire == false)||j==4)
    {
        if (mooreNeighboorhood[i][j] != NULL)
        {
            if (mooreNeighboorhood[i][j]->getOccupant() == NULL)
            {//case vide trouvée
                naissance = mooreNeighboorhood[i][j];
            }
            else if (mooreNeighboorhood[i][j]->getOccupant()->affichageA() == 'O')
            { //Humain Trouvé
                partenaire=true;
            }
        }
        i++;
        if (i > 3)
        {
            i = 0;
            j++;
        }
    }
    if(naissance!=NULL && partenaire !=false && getTauxRepro()*genrand_real3()>=0.5){
        Survivant * enfant = new Survivant(1, getForce(),10); //Naissance avec un taux de repro de 1 (50% de chances de se reproduire si possible), une force égale à celle du parent et une durée de vie maximale de 10 tours
        naissance->addAgent(enfant);
    }
}


void Survivant::setKillCount(int kC)
{
    killCount = kC;
}

char Survivant::affichageA()
{
    return 'O';
}

void Survivant::attaquer(Zombie * z)
{
    if (force * (1 + killCount * 0.1) * genrand_real3() >= z->getForce() * genrand_real3())
    {
        z->mourir();
        killCount++;
    }
    else{
        Case * temp = getCase();
        temp->addAgent(new Zombie(1,10));
        mourir();
    }
}

void coeff_voisin(std::vector<std::vector<Case *>> mooreNeighboorhood, int ** tab)
{
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(mooreNeighboorhood[i][j] == NULL){
                tab[i][j] +=15;
            }
            else if(mooreNeighboorhood[i][j]->getOccupant()->affichageA() == 'X'){
                tab[i][j] += 3;
                tab[1][1] += 1;
                if(i==0 && j==0) //en haut à gauche
                {
                    tab[0][1] +=1;
                    tab[1][0] +=1;
                }
                if(i==0 && j==1) //en haut au milieu
                {
                    tab[0][0] +=1;
                    tab[1][0] +=1;
                    tab[0][2] +=1;
                    tab[1][2] +=1;
                }
                if(i==0 && j==2) // en haut à droite
                {
                    tab[0][1] +=1;
                    tab[1][2] +=1;
                }
                if(i==1 && j==2) // au milieu à droite
                {
                    tab[0][2] +=1;
                    tab[0][1] +=1;
                    tab[2][1] +=1;
                    tab[2][2] +=1;
                }
                if(i==2 && j==2) // en bas à droite
                {
                    tab[1][2] +=1;
                    tab[2][1] +=1;
                }
                if(i==2 && j==1) // en bas au milieu
                {
                    tab[2][0] +=1;
                    tab[1][0] +=1;
                    tab[1][2] +=1;
                    tab[2][2] +=1;
                }
                if(i==2 && j==0) // en bas à gauche
                {
                    tab[1][0] +=1;
                    tab[2][1] +=1;
                }
                if(i==1 && j==2) // au milieu à droite
                {
                    tab[0][0] +=1;
                    tab[0][1] +=1;
                    tab[2][1] +=1;
                    tab[2][0] +=1;
                }
            } else if(mooreNeighboorhood[i][j]->getOccupant()->affichageA() == 'O'){
                tab[i][j] += 15;
            }
        }
    }
}