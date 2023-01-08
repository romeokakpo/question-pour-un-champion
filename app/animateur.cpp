#include "animateur.h"

Animateur::Animateur()
{
    manche = 1;
}

int Animateur::getManche()
{
    return manche;
}

string Animateur::jeu_commence()
{
    return "Alors on commence, qui sera le champion de cette partie ?";
}

Question Animateur::poser_question()
{
    return questionnaire.prendre_question();
}

int Animateur::get_nbr_quizz_m1()
{
    return questionnaire.getNbrQuestionPris();
}

/*void Animateur::enregistrer_joueur(string)
{

}

Joueur* Animateur::donner_vainqueur()
{

}
string Animateur::proposer_theme()
{

}
*/