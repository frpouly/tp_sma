#ifndef FABRIQUE_H
#define FABRIQUE_H

#include <map>
#include <string>
//La fabrique à proprement parler
class FactoryAgent
{
public:
    static std::map<std::string, Figure*> m_map;

public:
    //Fonction qui associe clé <=> prototype
    static void Register(const std::string& key, Agent* obj);

    //Celle qui va créer les objets
    Agent* Create(const std::string& key) const;
};
#endif