#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include "header.h"

Compte::Compte(std::string _pseudo)
{
    //lit dans le fichier
    this->m_pseudo=_pseudo;
    std::string nomFichier=_pseudo+".score";
    bool existe=access(nomFichier.c_str(), F_OK)!=-1;//dis si fichier existe ou non
    if(existe==false)
    {
        this->m_partiesJ=0;
        this->m_partiesG=0;
        this->Save();
        std::cout<<"Nouveau compte cree"<<std::endl;
        std::cout<<"parties jouees: "<<this->m_partiesJ<<std::endl;
        std::cout<<"parties gagnees: "<<this->m_partiesG<<std::endl;;
        std::cout<<"niveau DEBUTANT "<<std::endl;;
        getch();
    }
    else
    {
        std::ifstream fichier(nomFichier);//ouvrir fichier
        if(fichier.is_open()==false)//impossible d'ouvrir fichier
        {
            this->m_partiesJ=0;
            this->m_partiesG=0;
            this->Save();
            std::cout<<"Nouveau compte cree"<<std::endl;
            std::cout<<"parties jouees: "<<this->m_partiesJ<<std::endl;
            std::cout<<"parties gagnees: "<<this->m_partiesG<<std::endl;;
            std::cout<<"niveau DEBUTANT "<<std::endl;;
            getch();
            return;
        }
        char sep;
        fichier>>this->m_partiesJ;
        fichier>>sep;
        fichier>>this->m_partiesG;//recupere 2 int separés par ; dans le fichier
        fichier.close();
        std::cout<<"compte deja existant, informations a suivre:"<<std::endl;
        std::cout<<"parties jouees: "<<this->m_partiesJ<<std::endl;
        std::cout<<"parties gagnees: "<<this->m_partiesG<<std::endl;
        std::cout<<"niveau: ";
        if(this->m_partiesG!=0 && (this->m_partiesJ/this->m_partiesG)>0.25)
        {
            std::cout<<"EXPERT"<<std::endl;
        }
        else
        {
            std::cout<<"AMATEUR"<<std::endl;
        }
        getch();
    }
}

Compte::~Compte()
{

}

void Compte::Save()//ecrit dans fichier
{
    std::string nomFichier=this->m_pseudo+".score";
    bool existe=access(nomFichier.c_str(), F_OK)!=-1;//dis si fichier existe ou non
    if(existe==false)
    {
        std::fstream f(nomFichier, std::ios_base::out);//créer le fichier
        f.close();
    }
    std::ofstream fichier(nomFichier, std::ofstream::in);//ouvrir fichier
    if(fichier.is_open()==false)//impossible d'ouvrir fichier
    {
        return;
    }
    fichier<<this->m_partiesJ;
    fichier<<";";
    fichier<<this->m_partiesG;//recupere 2 int separés par ; dans le fichier
    fichier.close();
}

void Compte::ajouterJ()
{
    this->m_partiesJ++;
    this->Save();
}

void Compte::ajouterG()
{
    this->m_partiesJ++;
    this->m_partiesG++;
    this->Save();
}

