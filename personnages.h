#ifndef PERSONNAGES_H_INCLUDED
#define PERSONNAGES_H_INCLUDED

class Personnages : public Cartes//initialisation classe Personnages, herite de Cartes
{
public :
    Personnages();
    Personnages(std::string _nom);
    ~Personnages();

    void afficheCartes()const;

};

#endif // PERSONNAGES_H_INCLUDED


