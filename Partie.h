#ifndef PARTIE_H
#define PARTIE_H
#include "header.h"

enum direction
{
    UP=72, DOWN=80, LEFT=75, RIGHT=77
};
class Partie//Initialisation classe Partie
{
public:
    Partie();
    virtual ~Partie();
    void commencer();
    bool deplacerJoueur(int);
    bool isPorte();
    Lieux detectePiece();
    Personnages choixSuspect();
    Armes choixArme();
    Lieux choixLieux();
protected:

private:
    std::vector<Joueur>joueurs;
    int nbJoueurs;
    int tourJoueur;
    Cartes* solutionLieux;
    Cartes* solutionArme;
    Cartes* solutionPerso;
    Collection collect;
    Plateau plateau;
    std::vector<Couleur>couleurs;
};

#endif // PARTIE_H
