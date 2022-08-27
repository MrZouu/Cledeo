#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED
#include <string>

class Couleur
{
private:
    std::string m_nom;
    int m_couleur;
public:
    Couleur(std::string, int);
    ~Couleur();
    std::string getNom();
    int getCouleur();
};

#endif // COULEUR_H_INCLUDED
