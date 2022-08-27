#include "Couleur.h"
//Initialisation des methodes de la classe Couleur
Couleur::Couleur(std::string _nom, int _couleur)
{
    this->m_nom=_nom;
    this->m_couleur=_couleur;
}

Couleur::~Couleur()
{

}

std::string Couleur::getNom()
{
    return m_nom;
}

int Couleur::getCouleur()
{
    return m_couleur;
}
