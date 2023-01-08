#ifndef ANIMATEUR_H_INCLUDED
#define ANIMATEUR_H_INCLUDED
#include "joueur.h"
#include "robot.h"
#include "questionnaire.h"

class Animateur
{
    public:
        Animateur();
        string jeu_commence();
        void enregistrer_joueur(char*);
        Question poser_question();
        Joueur* donner_vainqueur();
        string proposer_theme();
        int get_nbr_quizz_m1();
        int getManche();
        
    private:
        int manche, nbr_joueurs, nbr_robots;
        Joueur *joueurs;
        Robot *robots;
        Questionnaire questionnaire;
};

#endif //ANIMATEUR_H_INCLUDE