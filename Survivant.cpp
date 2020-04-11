#include "Survivant.hpp"

Survivant::Survivant(int tr, int f, int ddv) : Agent(f,ddv), tauxRepro(tr), killCount(0)
{
}

void Survivant::Attaquer(Zombie& z)
{
    //Combat entre le survivant et le zombie
    //Tirage en boucle de la force du survivant, randomisée et boostée par le killCount, soustraite aux pv du zombie
    //Riposte du zombie jusqu'à mort de l'un des participants
    //Si zombie gagne, le survivant crée un zombie, lui "donne" sa case et meurt
    //Sinon, le zombie meurt et le survivant se déplace sur la case vide
    //if (force * (1 + killCount * 0.1) * genrand_real3() >= z.getForce() * genrand_real3());//humain gagne
}

void Survivant::live(std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    //coeff_voisin(mooreNeighboorhood, tab);
    /*
    Découverte des voisins de Moore
    Si partenaire survivant, test sur taux de repro et spawn d'un nouveau Survivant
    Se déplace (en cherchant à rester à coté d'un survivant) et sans être en voisinage de danger
    Si il ne peut pas, il doit Attaquer un zombie
    Si il gagne, il se déplace
    */
    std::vector<std::vector<int>> tab = Survivant::coeff_voisin(mooreNeighboorhood);
    int min = 1000;
     for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cout << tab[i][j];
            if (tab[i][j] < min) {
                min = tab[i][j];
            }
		}
		std::cout << std::endl;
	}
    if(min < 15){
        std::vector<Case *> possibilites;
        int taille_vect = 0;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if (tab[i][j] == min) {
                    possibilites.push_back(mooreNeighboorhood[i][j]);
                    taille_vect++;
                }
            }
            std::cout << std::endl;
        }
        possibilites[genrand_int31()%taille_vect]->addAgent(this);
    }


/*
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
            mooreNeighboorhood[genrand_int31()%3][genrand_int31()%3]->addAgent(this);
        }
    }
    */
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

void Survivant::setKillCount(int kC)
{
    killCount = kC;
}

char Survivant::affichageA()
{
    return 'O';
}

std::vector<std::vector<int>> Survivant::coeff_voisin(std::vector<std::vector<Case *>> mooreNeighboorhood)
{
    std::vector<std::vector<int>> tab;

    for(int k = 0; k < 3; k++)
	{
		std::vector<int> v;
		for(int l = 0; l < 3; l++)
		{
			v.push_back(0);
		}
		tab.push_back(v);
	}

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(mooreNeighboorhood[i][j] == NULL){
                tab[i][j] +=15;
            }
            else {
                if(mooreNeighboorhood[i][j]->getOccupant() == NULL){
                tab[i][j] += 0;
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
                if(i==1 && j==0) // au milieu à droite
                {
                    tab[0][0] +=1;
                    tab[0][1] +=1;
                    tab[2][0] +=1;
                    tab[2][1] +=1;
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
            } else if(mooreNeighboorhood[i][j]->getOccupant()->affichageA() == 'O'){
                tab[i][j] += 15;
            }
            }
        }
    }
    
    return tab;
}

