#ifndef LIEUX_H_INCLUDED
#define LIEUX_H_INCLUDED

class Lieux : public Cartes//initialisation classe Lieux, herite de Cartes
{
public :
    Lieux();
    Lieux(std::string _nom);
    ~Lieux();

    void afficheCartes()const;

};



#endif // LIEUX_H_INCLUDED
