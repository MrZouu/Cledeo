#ifndef CARTES_H_INCLUDED
#define CARTES_H_INCLUDED

class Cartes //initialisation de la classe Cartes
{
protected :
    std::string m_nom;

public :
    Cartes();
    Cartes(std::string _nom);
    virtual~Cartes();

    std::string getNom()const;
    virtual void afficheCartes()const;

};


#endif // CARTES_H_INCLUDED
