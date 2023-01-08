#ifndef JOUEUR_H_INCLUDE
#define JOUEUR_H_INCLUDE
#include "personnage.h"
#include "basededonnee.h"

class Joueur:public Personnage
{
    public:
        Joueur();
        Joueur(string, string, string);
        bool buzzer();
        string getPseudo();
        int getScore();
        void setScore(int _score);
        string repondre(Question*);
        Theme choisir_theme(Theme*);
    private:
        string m_pseudo;
        int score;
        bool actif;
        TYPE type;
        string m_pays, m_profession, themeChoisi;
};

#endif //JOUEUR_H_INCLUDE