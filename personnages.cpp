#include "header.h"
/*initialisation des methodes
de la classe Personnages*/
Personnages::Personnages()
{

}

Personnages::Personnages(std::string _nom):Cartes(_nom)
{

}

Personnages::~Personnages()
{

}

void Personnages::afficheCartes()const
{
    std::cout<<"Personnage : "<<getNom()<<std::endl;
}


