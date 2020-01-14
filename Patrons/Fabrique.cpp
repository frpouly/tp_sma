
#include <iostream>
#include <iterator>

#include "fabrique.h"

using namespace std;

Agent* Survivant::Clone() const
{
    return new Survivant(*this);
}

/*void Survivant::SeDessiner()
{
    cout << "Je suis un Carre" << endl;
}*/

Figure* Zombie::Clone() const
{
    return new Zombie(*this);
}

/*void Cercle::SeDessiner()
{
    cout << "Je suis un Cercle" << endl;
}*/

std::map<string, Figure*> FactoryAgent::m_map = std::map<string, Agent*>();

void FactoryFigure::Register(const string& key, Agent* obj)
{
    //si la clé n'est pas déjà présente
    if (m_map.find(key) == m_map.end())
    {
        //on ajoute l'objet dans la map
        m_map[key] = obj;
    }

    //on pourrait détruire obj mais cette tâche ne revient pas à Register
}

Figure* FactoryAgent::Create(const std::string& key) const
{
    Figure* tmp = 0;
    std::map<string, Agent*>::const_iterator it = m_map.find(key);

    //si l'itérateur ne vaut pas map.end(), cela signifie que que la clé à été trouvée
    if (it != m_map.end())
    {
        tmp = ((*it).second)->Clone();
    }

    //on pourrait lancer une exeption si la clé n'a pas été trouvée

    return tmp;
}

int main(void)
{
    //notre fabrique
    FactoryAgent fac;

    //on enregistre des types
    FactoryFigure::Register("Carre", new Carre);
    FactoryFigure::Register("Cercle", new Cercle);

    //on crée des objets via la fabrique
    Figure* c = fac.Create("Cercle");
    Figure* ca = fac.Create("Carre");

    c->SeDessiner();
    ca->SeDessiner();

    delete c;
    delete ca;

    return 0;
}