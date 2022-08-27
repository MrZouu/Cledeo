#include "Partie.h"

Partie::Partie()//Initialisation des valeurs de base
{
    this->nbJoueurs=0;
    this->tourJoueur=0;
    this->couleurs.push_back(Couleur("Bleu", BLUE));
    this->couleurs.push_back(Couleur("Vert", GREEN));
    this->couleurs.push_back(Couleur("Rouge", RED));
    this->couleurs.push_back(Couleur("Jaune", YELLOW));
    this->couleurs.push_back(Couleur("Magenta", MAGENTA));
    this->couleurs.push_back(Couleur("Marron", BROWN));
}

Partie::~Partie()
{

}

void Partie::commencer()
{
    plateau.init();
    while(1)
    {
        textcolor(YELLOW);
        std::cout<<"BIENVENUE DANS LE CLEDEO ARKHAM!"<<std::endl;
        std::cout<<"VOTRE MISSION EST DE TROUVER QUI A ASSASSINE LE JOKER, COMMENT ET DANS QUELLE PIECE DE L'ASILE."<<std::endl;
        std::cout<<"SI VOUS ETES PRETS A COMMENCER CE PERIPLE, APPUYEZ SUR UNE TOUCHE DU CLAVIER..."<<std::endl;
        std::cout<<"ET SURTOUT, BONNE CHANCE..."<<std::endl;
        getch();
        clrscr();
        ///Menu de démarrage
        char choix=1;
        while(1)
        {
            textcolor(RED);
            std::cout<<"Que voulez vous faire?"<<std::endl;
            if(choix==1)
            {
                textcolor(BLACK);
                textbackground(RED);
            }
            std::cout<<"1.Commencer Partie"<<std::endl;
            if(choix==1)
            {
                textcolor(RED);
                textbackground(BLACK);
            }
            if(choix==2)
            {
                textcolor(BLACK);
                textbackground(RED);
            }
            std::cout<<"2.Afficher les regles"<<std::endl;
            if(choix==2)
            {
                textcolor(RED);
                textbackground(BLACK);
            }
            if(choix==3)
            {
                textcolor(BLACK);
                textbackground(RED);
            }
            std::cout<<"3.Quitter"<<std::endl;
            if(choix==3)
            {
                textcolor(RED);
                textbackground(BLACK);
            }
            int touche=getch();
            if(touche==224)
            {
                switch(getch())
                {
                case UP:
                    choix--;
                    if(choix<1)
                    {
                        choix=3;
                    }
                    break;
                case DOWN:
                    choix++;
                    if(choix>3)
                    {
                        choix=1;
                    }
                }
            }
            else if(touche==32)
            {
                break;
            }
            clrscr();
        }
        switch(choix)
        {
        case 1:
        {
            ///Initialisation nombre de joueurs
            while(this->nbJoueurs<2 || this->nbJoueurs>6)
            {
                clrscr();
                std::cout<<"Quel est le nombre de joueurs?"<<std::endl;
                std::cin >>this->nbJoueurs;
                std::cout<<std::endl;
            }
            for(int i=0; i<this->nbJoueurs; i++)
            {
                clrscr();
                Joueur tmp;
                std::cout<<"Joueur "<<i+1<<std::endl;//affichage infos du joueur
                tmp.initPseudo();
                clrscr();
                tmp.initCouleur(this->couleurs);
                this->joueurs.push_back(tmp);
                std::cout<<std::endl;
            }
            this->collect.melangeCarte();//melange des cartes
            ///choix de l'enigme
            this->solutionArme=collect.solutionArme();
            this->solutionLieux=collect.solutionLieux();
            this->solutionPerso=collect.solutionPerso();
            int i=0;
            int x=18/this->nbJoueurs;
            int j=0;
            for(auto elem: this->collect.getCollect())
            {
                if(j>=this->nbJoueurs)//si deja distrib
                {
                    if(i==0)
                    {
                        std::cout<<"CARTES NON DISTRIBUEES, RETENEZ LES BIEN!"<<std::endl;
                    }
                    elem->afficheCartes();
                }
                else
                {
                    this->joueurs[j].ajouterCarte(elem);//distrib cartes
                }
                i++;
                if(i>=x)
                {
                    j++;//joueur suiv
                    i=0;
                }
            }
            std::cout<<"APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<std::endl;
            getch();
            clrscr();
            De de;
            while(1)
            {
                Joueur* J=&(this->joueurs[this->tourJoueur]);//joueur actuel
                std::cout<<J->getPseudo()<<" appuyez sur une touche pour lancer le de"<<std::endl;
                getch();
                clrscr();
                int mouvement=de.jeterDe();
                while(mouvement!=0)
                {
                    J->affichJ();//affichage des infos du joueur actuel
                    std::cout<<"Nombre de deplacements restants: "<<mouvement<<std::endl;
                    plateau.affichage(this->joueurs);
                    if(getch()==224)
                    {
                        if(deplacerJoueur(getch())==true)//si on peut se deplacer
                        {
                            mouvement--;//on enleve un deplacement au joueur
                            if(isPorte()==true)
                            {
                                mouvement=0;//si on entre dans une salle, on ne peut plus se deplacer
                                clrscr();
                                std::cout<<J->getPseudo()<< " entre dans le ";
                                Lieux L=this->detectePiece();//on detecte la piece dans laquelle le joueur rentre
                                L.afficheCartes();
                                bool finale=L.getNom()=="Escaliers";
                                std::cout<<"Appuyez sur une touche pour faire une ";
                                if(finale)
                                {
                                    std::cout<<"accusation finale!"<<std::endl;
                                }
                                else
                                {
                                    std::cout<<"hypothese!"<<std::endl;
                                }
                                getch();
                                clrscr();
                                Personnages S=choixSuspect();//on demande qui on accuse
                                clrscr();
                                if(finale)
                                {
                                    L=choixLieux();//on demande le lieux du crime
                                    clrscr();
                                }
                                Armes A=choixArme();//on demande l'arme du crime
                                clrscr();
                                std::cout<<"L'hypothese est ";//affichage de l'hypothese
                                S.afficheCartes();
                                A.afficheCartes();
                                L.afficheCartes();
                                if(getch()==224)//si fleche
                                {
                                    getch();
                                }
                                if(finale==true)
                                {
                                    if(S.getNom()==solutionPerso->getNom() && A.getNom()==solutionArme->getNom() && L.getNom()==solutionLieux->getNom())//si la solution est bonne
                                    {
                                        std::cout<<"BRAVO "<<J->getPseudo()<<" votre accusation est vraie, vous avez gagne la partie"<<std::endl;
                                        J->getCompte()->ajouterG();//increment nb partie j et g au gagnant
                                        for(auto elem: this->joueurs)
                                        {
                                            if(elem.getPseudo()!=J->getPseudo())
                                            {
                                                elem.getCompte()->ajouterJ();//increment nb partie j aux autres
                                            }
                                        }
                                        getch();
                                        clrscr();
                                        return;
                                    }
                                    else
                                    {
                                        std::cout<<"Dommage, l'hypothese finale est fausse"<<std::endl;
                                        getch();
                                        clrscr();
                                        continue;
                                    }
                                }
                                bool indice=false;
                                for(int i=this->tourJoueur+1; i!=this->tourJoueur; i++)//on ne prend pas en compte les cartes Personnage du joueur qui fait l'hypothese
                                {

                                    if(i>=this->nbJoueurs)
                                    {
                                        i=0;
                                        if(i==this->tourJoueur)//on saute le joueur actuel
                                        {
                                            break;
                                        }
                                    }
                                    Joueur *G=&(this->joueurs[i]);
                                    std::vector<Cartes*>cartes=G->getJeuCarte();
                                    for(std::vector<Cartes*>::iterator it = cartes.begin(); it != cartes.end(); it++)//parcours des cartes des joueurs
                                    {
                                        if((*it)->getNom()==S.getNom())//si on trouve la carte suspect
                                        {
                                            std::cout<<G->getPseudo()<<" vous montre la carte ";
                                            S.afficheCartes();//on l'affcihe
                                            getch();
                                            indice=true;
                                            break;
                                        }
                                    }
                                }
                                for(int i=this->tourJoueur+1; i!=this->tourJoueur; i++)//meme raisonnement pour les cartes Lieux
                                {
                                    if(indice==true)
                                    {
                                        break;
                                    }
                                    if(i>=this->nbJoueurs)
                                    {
                                        i=0;
                                        if(i==this->tourJoueur)
                                        {
                                            break;
                                        }
                                    }
                                    Joueur *G=&(this->joueurs[i]);
                                    std::vector<Cartes*>cartes=G->getJeuCarte();
                                    for(std::vector<Cartes*>::iterator it = cartes.begin(); it != cartes.end(); it++)
                                    {
                                        if((*it)->getNom()==L.getNom())
                                        {
                                            std::cout<<G->getPseudo()<<" vous montre la carte ";
                                            L.afficheCartes();
                                            getch();
                                            indice=true;
                                            break;
                                        }
                                    }
                                }
                                for(int i=this->tourJoueur+1; i!=this->tourJoueur; i++)//meme raisonnement pour les cartes Armes
                                {
                                    if(indice==true)
                                    {
                                        break;
                                    }
                                    if(i>=this->nbJoueurs)
                                    {
                                        i=0;
                                        if(i==this->tourJoueur)
                                        {
                                            break;
                                        }
                                    }
                                    Joueur *G=&(this->joueurs[i]);
                                    std::vector<Cartes*>cartes=G->getJeuCarte();
                                    for(std::vector<Cartes*>::iterator it = cartes.begin(); it != cartes.end(); it++)
                                    {
                                        if((*it)->getNom()==A.getNom())
                                        {
                                            std::cout<<G->getPseudo()<<" vous montre la carte ";
                                            A.afficheCartes();
                                            getch();
                                            indice=true;
                                            break;
                                        }
                                    }
                                }
                                if(indice==false)
                                {
                                    std::cout<<"Pas de carte trouvee..."<<std::endl;
                                    getch();
                                }
                            }
                        }
                    }
                    clrscr();
                }
                this->tourJoueur++;//on passe au joueur suivant
                if(this->tourJoueur>=this->nbJoueurs)//si on depasse le nombre de joueur
                {
                    this->tourJoueur=0;//on retourne au premier joueur
                }
            }
            break;
        }
        case 2:
            clrscr();
            std::cout<<"Affichage des regles"<<std::endl;
            std::cout<<std::endl;
            std::cout<<"Bienvenu ! "<<std::endl;
            std::cout<<std::endl;
            std::cout<<"Le CLEDEO est un jeu de deduction. "<<std::endl;
            std::cout<<"Le jeu se deroule dans l'asile d'Arkham. "<<std::endl;
            std::cout<<"Le but du jeu est de savoir qui a tue Joker dans quelle piece de l'asile et avec quelle arme a ete commis le meurtre."<<std::endl;
            std::cout<<"Le jeu se base autour de trois types de cartes : Des cartes personnages, armes et lieux. "<<std::endl;
            std::cout<<"Avant que la partie ne commence, une carte de chaque type est tiree au sort et est placee dans une enveloppe et chaque joueur se voit attribue"<<std::endl;
            std::cout<<"aleatoirement le meme nombre de carte: personnages, lieux et armes. "<<std::endl;
            std::cout<<"A chaque tour d'un joueur, le joueur commence par lancer son de. Si le nombre affiche sur le de le permet, le joueur a la possibilite d'entrer"<<std::endl;
            std::cout<<"dans une piece et y emettre une hypothese. Si ce n’est pas le cas, le joueur reste dans le couloir et ne peut pas faire d’hypothese. "<<std::endl;
            std::cout<<"Si le joueur pense avoir trouve le meurtrier, son arme et la piece dans laquelle a ete commis le crime, il doit se rendre dans les escaliers"<<std::endl;
            std::cout<<"pour y emettre son hypothese FINALE !"<<std::endl;
            std::cout<<"Si son hypothese est vraie, le joueur remporte la partie et la partie prend fin. Si son hypothese est fausse le jeu continue."<<std::endl;
            getch();
            clrscr();
            break;
        case 3:
            exit(1);
            break;
        }
    }
}

bool Partie::deplacerJoueur(int d)
{
    Joueur* J=&(this->joueurs[this->tourJoueur]);
    switch(d)
    {
    case UP:
        if(plateau.getCase(J->getPosx()-1, J->getPosy())=='O' || plateau.getCase(J->getPosx()-1, J->getPosy())=='/')//si on peut se deplacer vers le haut
        {
            J->setPosx(J->getPosx() - 1) ;//on modifie la position x du jeton
            return true;
        }
        return false;
    case  DOWN:
        if(plateau.getCase(J->getPosx()+1, J->getPosy())=='O' || plateau.getCase(J->getPosx()+1, J->getPosy())=='/')//si on peut se deplacer vers le bas
        {
            J->setPosx(J->getPosx() + 1);//on modifie la position x du jeton
            return true;
        }
        return false;
    case RIGHT:
        if(plateau.getCase(J->getPosx(), J->getPosy()+1)=='O' || plateau.getCase(J->getPosx(), J->getPosy()+1)=='/')//si on peut aller a droite
        {
            J->setPosy(J->getPosy() + 1) ;//on modifie la position y
            return true;
        }
        return false;
    case LEFT:
        if(plateau.getCase(J->getPosx(), J->getPosy()-1)=='O' || plateau.getCase(J->getPosx(), J->getPosy()-1)=='/')//si on peut aller a gauche
        {
            J->setPosy(J->getPosy() - 1) ;//on modifie la positon y
            return true;
        }
        return false;
    default:
        return false;
    }
}

bool Partie::isPorte()
{
    Joueur* J=&(this->joueurs[this->tourJoueur]);
    return plateau.getCase(J->getPosx(), J->getPosy())=='/';
}

Lieux Partie::detectePiece()
{
    ///on detecte la piece dans laquelle on rentre en fonction des coordonnees
    Joueur* J=&(this->joueurs[this->tourJoueur]);
    int x=J->getPosx();
    int y=J->getPosy();
    if(x==6)
    {
        switch(y)
        {
        case 14:
        case 15:
            return Lieux("Cuisine");
        case 27:
        case 28:
        case 29:
            return Lieux("Cellule");
        case 41:
        case 42:
            return Lieux("Bibliotheque");
        }
    }
    else if(x==8)
    {
        switch(y)
        {
        case 14:
        case 15:
            return Lieux("Cour");
        case 41:
        case 42:
            return Lieux("Salle de bain");
        }
    }
    else if(x==8)
    {
        switch(y)
        {
        case 14:
        case 15:
            return Lieux("Cour");
        case 41:
        case 42:
            return Lieux("Salle de bain");
        }
    }
    else if(x==15)
    {
        switch(y)
        {
        case 14:
        case 15:
            return Lieux("Cour");
        }
    }

    else if(x==14 && y==39)
    {
        return Lieux("Salle des gardes");
    }
    else if(x==17)
    {
        switch(y)
        {
        case 14:
        case 15:
            return Lieux("Infirmerie");
        case 27:
        case 28:
        case 29:
            return Lieux("Jardin botannique");
        }
    }
    else if(x==18 && (y==41 || y==42))
    {
        return Lieux("Soins intensifs");
    }
    else if(x==14 && y==28)
    {
        return Lieux("Escaliers");
    }
    return Lieux("Couloir");
}

Personnages Partie::choixSuspect()
{
    ///Menu accusation suspect
    int choix=1;
    while(1)
    {
        std::cout<<"Qui accusez vous?"<<std::endl;
        if(choix==1)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"1.Batman"<<std::endl;
        if(choix==1)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==2)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"2.Robin"<<std::endl;
        if(choix==2)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==3)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"3.Catwoman"<<std::endl;
        if(choix==3)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==4)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"4.Alfred"<<std::endl;
        if(choix==4)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==5)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"5.Oracle"<<std::endl;
        if(choix==5)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==6)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"6.Commissaire Gordon"<<std::endl;
        if(choix==6)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        int touche=getch();
        if(touche==224)
        {
            switch(getch())
            {
            case UP:
                choix--;
                if(choix<1)
                {
                    choix=6;
                }
                break;
            case DOWN:
                choix++;
                if(choix>6)
                {
                    choix=1;
                }
            }
        }
        else if(touche==32)
        {
            break;
        }
        clrscr();
    }
    switch(choix)
    {
    case 1:
        return Personnages("Batman");
    case 2:
        return Personnages("Robin");
    case 3:
        return Personnages("Catwoman");
    case 4:
        return Personnages("Alfred");
    case 5:
        return Personnages("Oracle");
    case 6:
        return Personnages("Commissaire Gordon");
    }
}

Lieux Partie::choixLieux()
{
    ///Menu choix lieux du crime
    int choix=1;
    while(1)
    {
        std::cout<<"Quel est le lieux du crime?"<<std::endl;
        if(choix==1)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"1.Cellule"<<std::endl;
        if(choix==1)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==2)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"2.Cuisine"<<std::endl;
        if(choix==2)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==3)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"3.Bibliotheque"<<std::endl;
        if(choix==3)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==4)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"4.Salle de bain"<<std::endl;
        if(choix==4)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==5)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"5.Infirmerie"<<std::endl;
        if(choix==5)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==6)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"6.Salle des gardes"<<std::endl;
        if(choix==6)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==7)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"7.Cour"<<std::endl;
        if(choix==7)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==8)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"8.Jardin botannique"<<std::endl;
        if(choix==8)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==9)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"9.Soins intensifs"<<std::endl;
        if(choix==9)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        int touche=getch();
        if(touche==224)
        {
            switch(getch())
            {
            case UP:
                choix--;
                if(choix<1)
                {
                    choix=9;
                }
                break;
            case DOWN:
                choix++;
                if(choix>9)
                {
                    choix=1;
                }
            }
        }
        else if(touche==32)
        {
            break;
        }
        clrscr();
    }
    switch(choix)
    {
    case 1:
        return Lieux("Cellule");
    case 2:
        return Lieux("Cuisine");
    case 3:
        return Lieux("Bibliotheque");
    case 4:
        return Lieux("Salle de bain");
    case 5:
        return Lieux("Infirmerie");
    case 6:
        return Lieux("Salle des gardes");
    case 7:
        return Lieux("Cour");
    case 8:
        return Lieux("Jardin botannique");
    case 9:
        return Lieux("Soins intensifs");
    }
}

Armes Partie::choixArme()
{
    ///Menu choix arme du crime
    int choix=1;
    while(1)
    {
        std::cout<<"Quelle est l'arme du crime?"<<std::endl;
        if(choix==1)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"1.Revolver"<<std::endl;
        if(choix==1)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==2)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"2.Corde"<<std::endl;
        if(choix==2)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==3)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"3.Poison"<<std::endl;
        if(choix==3)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==4)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"4.Hache"<<std::endl;
        if(choix==4)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==5)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"5.Poignard"<<std::endl;
        if(choix==5)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        if(choix==6)
        {
            textcolor(BLACK);
            textbackground(WHITE);
        }
        std::cout<<"6.Batarang"<<std::endl;
        if(choix==6)
        {
            textcolor(WHITE);
            textbackground(BLACK);
        }
        int touche=getch();
        if(touche==224)
        {
            switch(getch())
            {
            case UP:
                choix--;
                if(choix<1)
                {
                    choix=6;
                }
                break;
            case DOWN:
                choix++;
                if(choix>6)
                {
                    choix=1;
                }
            }
        }
        else if(touche==32)
        {
            break;
        }
        clrscr();
    }
    switch(choix)
    {
    case 1:
        return Armes("Revolver");
    case 2:
        return Armes("Corde");
    case 3:
        return Armes("Poison");
    case 4:
        return Armes("Hache");
    case 5:
        return Armes("Poignard");
    case 6:
        return Armes("Batarang");
    }
}
