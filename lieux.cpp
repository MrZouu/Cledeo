#include "header.h"
/*Initialisation des methodes
de la classe Lieux*/
Lieux::Lieux()
{

}

Lieux::Lieux(std::string _nom):Cartes(_nom)
{

}

Lieux::~Lieux()
{

}

void Lieux::afficheCartes()const
{
    std::cout<<"Lieux : "<<getNom()<<std::endl;
}
