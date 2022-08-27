#include "header.h"
/* initialisation des methodes de
la classe Cartes*/

Cartes::Cartes():m_nom("")
{

}

Cartes::Cartes(std::string _nom): m_nom(_nom)
{

}

Cartes::~Cartes()
{

}

std::string Cartes::getNom()const
{
    return m_nom;
}

void Cartes::afficheCartes()const
{
    std::cout<<"Nom : "<<getNom()<<std::endl;
}
