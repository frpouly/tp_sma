#ifndef FABRIQUE_H
#define FABRIQUE_H

#include <map>
#include <string>
//La fabrique � proprement parler
class FactoryAgent
{
public:
    static std::map<std::string, Figure*> m_map;

public:
    //Fonction qui associe cl� <=> prototype
    static void Register(const std::string& key, Agent* obj);

    //Celle qui va cr�er les objets
    Agent* Create(const std::string& key) const;
};
#endif