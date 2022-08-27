#include "header.h"

//Initialisation des methodes du plateau
Plateau::Plateau()
{

}

Plateau::~Plateau()
{

}

char Plateau::getCase(int x, int y)
{
    return board[x][y];
}

void Plateau::init()
{
    ///INITIALISATION
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            board[i][j]=' ';
        }
    }
    ///DEBUT
    //Angles du tableau
    board[0][0]=0xDA;
    board[0][54]=0xBF;
    board[23][0]=0xC0;
    board[23][54]=0xD9;
    ///Carre principal
    for(int j=1; j<54; j++) //LIGNE DU HAUT
    {
        board[0][j]=0xC4;
    }
    for(int i=1; i<23; i++) //LIGNES COTE
    {
        board[i][0]=0xB3;
        board[i][54]=0xB3;
        if(i==6||i==8||i==15||i==17)
        {
            board[i][0]=0xC3;//Affichage T a gauche
        }
        if(i==6||i==8||i==12||i==16||i==18)
        {
            board[i][54]=0xB4;//Affichage T a droite
        }
    }
    for(int j=1; j<54; j++) //LIGNE DU BAS
    {
        board[23][j]=0xC4;
        if(j==17||j==20||j==36||j==39)
        {
            board[23][j]=0xC1;//Affichage T du cote bas
            board[0][j]=0xC2;//Affichage T du coté haut
        }
    }
    ///SALLES
    for(int i=1; i<23; i++) //Colonnes
    {
        for(int j=0; j<54; j++)
        {
            if((i<6||i>17)&&(j==17||j==20||j==36||j==39))
            {
                //Colonnes salles haut et bas
                board[i][j]=0xB3;

            }
            if((i>8&&i<15)&&(j==17||j==39))
            {
                //Colonnes salles haut et bas
                board[i][j]=0xB3;

            }
        }
    }
    board[18][39]=' ';//Enlever une | a salle bas droite
    board[15][39]=0xB3;//Ajouter une | a salle du milieu, droite bas
    //lignes
    for(int i=1; i<23; i++)
    {
        for(int j=1; j<54; j++)
        {
            if(i==6&&(j<17||j>20&&j<36||j>39)||i==8&&(j<17||j>39))
            {
                board[i][j]=0xC4; //Lignes du haut
            }
            if(((j<17&&i==15)||(j>39&&(i==16||i==12||i==18))||(i==17&&j<36))&&(j<17||j>20))
            {
                board[i][j]=0xC4;//Lignes salles coté bas
            }

        }
    }
    for(int i=1; i<23; i++)
    {
        //Angle des salles
        for(int j=0; j<54; j++)
        {
            if((i==6&&(j==17||j==36))||(i==15&&j==17))
            {
                board[i][j]=0xD9;//Angles T bas droit
            }
            if((i==8&&(j==39))||(i==17&&j==20)||(i==18&&j==39))
            {
                board[i][j]=0xDA;//Angles T haut gauche
            }
            if((i==6&&(j==20||j==39))||(i==16&&j==39))
            {
                board[i][j]=0xC0;//Angles T bas gauche
            }
            if((j==17&&(i==8||i==17))||(i==17&&j==36))
            {
                board[i][j]=0xBF;//Angles T haut droit
            }
        }
    }
    //Porte des salles ( espaces vides )
    for(int i=1; i<23; i++)
    {

        if(i==6||i==8||i==15||i==17)
        {
            //Salles de gauche
            board[i][14]='/';
            board[i][15]='/';
            if(i==6 || i==15)
            {
                board[i-1][14]=0xDC;
                board[i-1][15]=0xDC;
            }
            else
            {
                board[i+1][14]=0xDF;
                board[i+1][15]=0xDF;
            }

        }
        if(i==6||i==17)
        {
            //Salles du milieu
            board[i][27]='/';
            board[i][28]='/';
            board[i][29]='/';
            if(i==6)
            {
                board[i-1][27]=0xDC;
                board[i-1][28]=0xDC;
                board[i-1][29]=0xDC;
            }
            else
            {
                board[i+1][27]=0xDF;
                board[i+1][28]=0xDF;
                board[i+1][29]=0xDF;
            }

        }
        if(i==6||i==8||i==18)
        {
            //Salles de droite
            board[i][41]='/';
            board[i][42]='/';
            if(i==6)
            {
                board[i-1][41]=0xDC;
                board[i-1][42]=0xDC;
            }
            else
            {
                board[i+1][41]=0xDF;
                board[i+1][42]=0xDF;
            }

        }
    }
    board[9][24]=0xDA;
    board[9][32]=0xBF;
    board[14][24]=0xC0;
    board[14][32]=0xD9;
    for(int i=10; i<14; i++)
    {
        board[i][24]=0xB3;
        board[i][32]=0xB3;

    }
    for(int i=25; i<32; i++)
    {
        board[9][i]=0xC4;
        board[14][i]=0xC4;
    }
    board[14][28]='/';
    board[13][28]=0xDC;


    board[14][39]='/';//Enlever une | a salle du milieu, droite bas
    board[14][40]=0xDB;
    board[12][39]=0xC3; // T entre les salles du milieu, droit
    ///TEXTE SUR LE PLATEAU
    //Centre
    board[11][25]='C';
    board[11][26]='L';
    board[11][27]='U';
    board[11][28]='E';
    board[11][29]='D';
    board[11][30]='O';

    board[12][25]='A';
    board[12][26]='R';
    board[12][27]='K';
    board[12][28]='H';
    board[12][29]='A';
    board[12][30]='M';
    //Salles
    board[3][5]='C';
    board[3][6]='U';
    board[3][7]='I';
    board[3][8]='S';
    board[3][9]='I';
    board[3][10]='N';
    board[3][11]='E';

    board[11][7]='C';
    board[11][8]='O';
    board[11][9]='U';
    board[11][10]='R';

    board[20][4]='I';
    board[20][5]='N';
    board[20][6]='F';
    board[20][7]='I';
    board[20][8]='R';
    board[20][9]='M';
    board[20][10]='E';
    board[20][11]='R';
    board[20][12]='I';
    board[20][13]='E';

    board[3][25]='C';
    board[3][26]='E';
    board[3][27]='L';
    board[3][28]='L';
    board[3][29]='U';
    board[3][30]='L';
    board[3][31]='E';

    board[19][25]='J';
    board[19][26]='A';
    board[19][27]='R';
    board[19][28]='D';
    board[19][29]='I';
    board[19][30]='N';
    board[20][24]='B';
    board[20][25]='O';
    board[20][26]='T';
    board[20][27]='A';
    board[20][28]='N';
    board[20][29]='I';
    board[20][30]='Q';
    board[20][31]='U';
    board[20][32]='E';

    board[3][41]='B';
    board[3][42]='I';
    board[3][43]='B';
    board[3][44]='L';
    board[3][45]='I';
    board[3][46]='O';
    board[3][47]='T';
    board[3][48]='H';
    board[3][49]='E';
    board[3][50]='Q';
    board[3][51]='U';
    board[3][52]='E';

    board[9][44]='S';
    board[9][45]='A';
    board[9][46]='L';
    board[9][47]='L';
    board[9][48]='E';
    board[10][45]='D';
    board[10][46]='E';
    board[11][44]='B';
    board[11][45]='A';
    board[11][46]='I';
    board[11][47]='N';

    board[13][44]='S';
    board[13][45]='A';
    board[13][46]='L';
    board[13][47]='L';
    board[13][48]='E';
    board[14][45]='D';
    board[14][46]='E';
    board[14][47]='S';
    board[15][44]='G';
    board[15][45]='A';
    board[15][46]='R';
    board[15][47]='D';
    board[15][48]='E';
    board[15][49]='S';

    board[20][44]='S';
    board[20][45]='O';
    board[20][46]='I';
    board[20][47]='N';
    board[20][48]='S';
    board[21][42]='I';
    board[21][43]='N';
    board[21][44]='T';
    board[21][45]='E';
    board[21][46]='N';
    board[21][47]='S';
    board[21][48]='I';
    board[21][49]='F';
    board[21][50]='S';
    ///affichage des cases
    for(int i=1; i<WIDTH-2; i++)
    {
        board[7][i]='O';
    }
    for(int i=1; i<WIDTH-17; i++)
    {
        board[16][i]='O';
    }
    for(int i=WIDTH-17; i<WIDTH-2; i++)
    {
        board[17][i]='O';
    }
    for(int i=1; i<HEIGHT-1; i++)
    {
        board[i][18]='O';
        board[i][19]='O';
    }
    for(int i=1; i<HEIGHT-1; i++)
    {
        board[i][37]='O';
        board[i][38]='O';
    }
    for(int i=8; i<17; i++)
    {
        board[i][20]='O';
        board[i][21]='O';
        board[i][22]='O';
        board[i][23]='O';
    }
    for(int i=8; i<17; i++)
    {
        board[i][33]='O';
        board[i][34]='O';
        board[i][35]='O';
        board[i][36]='O';
    }
    for(int i=24; i<33; i++)
    {
        board[8][i]='O';
    }
    for(int i=24; i<33; i++)
    {
        board[15][i]='O';
    }
}


void Plateau::affichage(std::vector<Joueur>joueurs)
{
    ///AFFICHAGE DU PLATEAU
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            bool display=false;
            for(auto elem: joueurs)
            {
                if(elem.getPosx()==i && j==elem.getPosy())
                {
                    textcolor(elem.getCouleur());
                    std::cout<<"X";
                    textcolor(WHITE);
                    display=true;
                    break;
                }
            }
            if(display==false)
            {
                std::cout << board[i][j];
            }
        }
        std::cout<< std::endl;
    }
}

