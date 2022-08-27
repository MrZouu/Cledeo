#include "header.h"
/*Initialisation des methodes
de la classe Armes*/
Armes::Armes()
{

}

Armes::Armes(std::string _nom):Cartes(_nom)
{

}

Armes::~Armes()
{

}

void Armes::afficheCartes()const
{
    std::cout<<"Armes : "<<getNom()<<std::endl;
}

