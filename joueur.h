#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "header.h"
#include "Couleur.h"
class Joueur//Initialisation de la classe Joueur
{
private :
    std::string m_pseudo;
    std::vector<Cartes*>m_jeuCarte;
    int m_posx, m_posy;
    int m_couleur;
    Compte* m_compte;

public :
    Joueur();
    ~Joueur();
    std::vector<Cartes*>getJeuCarte()const;
    std::string getPseudo()const;
    int getPosx();
    int getPosy();
    int getCouleur();
    void setCouleur(int);
    void setPosx(int x);
    void setPosy(int y);
    void ajouterCarte(Cartes* carte);
    void initPseudo();
    void affichJ();
    void piocherJ(int nb,std::stack<Cartes*>&pile);
    void initCouleur(std::vector<Couleur>&couleurs);
    Compte *getCompte();
};

#endif // JOUEUR_H_INCLUDED
