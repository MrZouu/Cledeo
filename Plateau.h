#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "header.h"


#define HEIGHT 24
#define WIDTH 56

class Plateau//Initialisation de la classe Plateau
{
private:
    char board[HEIGHT][WIDTH];
public:
    Plateau();
    ~Plateau();
    char getCase(int x, int y);
    void init();
    void affichage(std::vector<Joueur>joueurs);
};

#endif // PLATEAU_H_INCLUDED
