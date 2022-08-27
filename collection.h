#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED
#include "header.h"
#include <vector>
#include <stack>

class Collection//initialisation classe Collection
{
private :
    std::vector<Cartes*> m_collect;
    std::stack<Cartes*>m_pile;

public :
    Collection();
    ~Collection();
    std::vector<Cartes*>getCollect()const;
    void setCollect(std::vector<Cartes*>_modif);
    std::stack<Cartes*>& getPile();
    void setPile(std::stack<Cartes*> _pileModif);
    Cartes* solutionArme();
    Cartes* solutionLieux();
    Cartes* solutionPerso();
    void InitCarte();
    void melangeCarte();
    void display();
};

#endif // COLLECTION_H_INCLUDED

