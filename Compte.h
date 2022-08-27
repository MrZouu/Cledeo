#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED
#include "header.h"

class Compte
{
private:
    std::string m_pseudo;
    int m_partiesJ;
    int m_partiesG;
public:
    Compte(std::string);
    ~Compte();
    void Save();
    void ajouterJ();
    void ajouterG();
};



#endif // COMPTE_H_INCLUDED
