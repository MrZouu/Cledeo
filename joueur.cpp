#include "header.h"
#include <stack>
/*Initialisation des methodes
de la classe Joueur*/

Joueur::Joueur()
{
    m_posx=14;
    m_posy=28;
    m_compte=NULL;
}

Joueur::~Joueur()
{

}

int Joueur::getPosx()
{
    return m_posx;
}

int Joueur::getPosy()
{
    return m_posy;
}

void Joueur::setPosx(int x)
{
    m_posx=x;
}

void Joueur::setPosy(int y)
{
    m_posy=y;
}
void Joueur::setCouleur(int c)
{
    m_couleur=c;
}

int Joueur::getCouleur()
{
    return m_couleur;
}

std::string Joueur::getPseudo()const
{
    return m_pseudo;
}

std::vector<Cartes*>Joueur::getJeuCarte()const
{
    return m_jeuCarte;
}

void Joueur::initPseudo()//choix du pseudo
{
    std::cout<<"Saisir un pseudo : "<<std::endl;
    std::cin>>m_pseudo;
    m_compte=new Compte(m_pseudo);
}

void Joueur::affichJ()//affichage pseudo et cartes du joueur
{
    std::cout<<"Joueur: "<<m_pseudo<<std::endl;
    for(std::vector<Cartes*>::iterator it = m_jeuCarte.begin(); it != m_jeuCarte.end(); it++)
    {
        (*it)->afficheCartes();
    }
}

void Joueur::ajouterCarte(Cartes* carte)
{
    this->m_jeuCarte.push_back(carte);
}

void Joueur::initCouleur(std::vector<Couleur>&couleurs)//initialisation couleur du pion
{
    int choix=1;
    while(1)
    {
        std::cout<<"Quelle couleur voulez vous?"<<std::endl;
        int i=1;
        for(auto elem: couleurs)
        {
            if(choix==i)
            {
                textcolor(BLACK);
                textbackground(WHITE);
            }
            std::cout<<i<<"."<<elem.getNom()<<std::endl;
            if(choix==i)
            {
                textcolor(WHITE);
                textbackground(BLACK);
            }
            i++;

        }
        int touche=getch();
        if(touche==224)//si on appuie sur les fleches
        {
            switch(getch())
            {
            case UP:
                choix--;
                if(choix<1)
                {
                    choix=couleurs.size();
                }
                break;
            case DOWN:
                choix++;
                if(choix>couleurs.size())
                {
                    choix=1;
                }
            }
        }
        else if(touche==32)//si on appuie sur espace
        {
            break;
        }
        clrscr();
    }
    this->m_couleur=couleurs[choix-1].getCouleur();
    couleurs.erase(couleurs.begin()+(choix-1));
}

Compte* Joueur::getCompte()
{
    return m_compte;
}







