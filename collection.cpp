#include "header.h"
/*Initialisation des methodes
de la classe Collection*/
///Constructeur et destructeur

Collection::Collection()
{
    InitCarte();
}

Collection::~Collection()
{

}

///Accesseurs

std::vector<Cartes*> Collection::getCollect() const
{
    return m_collect;
}

std::stack<Cartes*>& Collection::getPile()
{
    return m_pile;
}

void Collection::setCollect(std::vector<Cartes*>_modif)
{
    m_collect = _modif;
}

void Collection::setPile(std::stack<Cartes*> _pileModif)
{
    m_pile = _pileModif;
}

///Methodes

void Collection::InitCarte()//on remplit le vecteur avec les differentes cartes
{
    ///Personnages
    m_collect.push_back(new Personnages("Batman"));
    m_collect.push_back(new Personnages("Robin"));
    m_collect.push_back(new Personnages("Catwoman"));
    m_collect.push_back(new Personnages("Alfred"));
    m_collect.push_back(new Personnages("Oracle"));
    m_collect.push_back(new Personnages("Commissaire Gordon"));

    ///Armes
    m_collect.push_back(new Armes("Revolver"));
    m_collect.push_back(new Armes("Corde"));
    m_collect.push_back(new Armes("Poison"));
    m_collect.push_back(new Armes("Hache"));
    m_collect.push_back(new Armes("Poignard"));
    m_collect.push_back(new Armes("Batarang"));

    ///Lieux
    m_collect.push_back(new Lieux("Cellule"));
    m_collect.push_back(new Lieux("Cuisine"));
    m_collect.push_back(new Lieux("Bibliotheque"));
    m_collect.push_back(new Lieux("Salle de bain"));
    m_collect.push_back(new Lieux("Infirmerie"));
    m_collect.push_back(new Lieux("Salle des gardes"));
    m_collect.push_back(new Lieux("Cour"));
    m_collect.push_back(new Lieux("Jardin botannique"));
    m_collect.push_back(new Lieux("Soins intensifs"));

}

Cartes* Collection::solutionArme()//choix de la solution Arme de l'enigme
{
    for(auto it=m_collect.begin(); it!=m_collect.end(); it++)
    {
        Cartes *tmp=*it;
        if(typeid(Armes)==typeid(*tmp))
        {
            m_collect.erase(it);
            return tmp;
        }
    }
    return NULL;
}

Cartes* Collection::solutionLieux()//choix de la solution Lieux de l'enigme
{
    for(auto it=m_collect.begin(); it!=m_collect.end(); it++)
    {
        Cartes *tmp=*it;
        if(typeid(Lieux)==typeid(*tmp))
        {
            m_collect.erase(it);
            return tmp;
        }
    }
    return NULL;
}

Cartes* Collection::solutionPerso()//choix de la solution Personnage de l'enigme
{
    for(auto it=m_collect.begin(); it!=m_collect.end(); it++)
    {
        Cartes *tmp=*it;
        if(typeid(Personnages)==typeid(*tmp))
        {
            m_collect.erase(it);
            return tmp;
        }
    }
    return NULL;
}
void Collection::melangeCarte() //Melanger un vecteur avec random_shuffle - OpenClassrooms
{

    random_shuffle(m_collect.begin(), m_collect.end());

}

void Collection::display()//affichage des cartes
{
    for(std::vector<Cartes*>::iterator it = m_collect.begin(); it != m_collect.end(); it++)
    {
        (*it)->afficheCartes();
    }
}

