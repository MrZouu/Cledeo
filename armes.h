#ifndef ARMES_H_INCLUDED
#define ARMES_H_INCLUDED

class Armes : public Cartes//initialisation classe Armes, herite de Cartes
{
public :
    Armes();
    Armes(std::string _nom);
    ~Armes();

    void afficheCartes()const;

};

#endif // ARMES_H_INCLUDED
