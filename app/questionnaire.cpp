#include "questionnaire.h"

Questionnaire::Questionnaire()
{
    BaseDeDonnee base("fichiers/manche1.txt");
    questions_m1 = base.lire_question();
}

Question Questionnaire::prendre_question()
{
    return ((m1_question_pris != questions_m1.size())?questions_m1[m1_question_pris++]:Question("Vous etes tous nul ???", "OUI", 0));
}

int Questionnaire::getNbrQuestionPris()
{
    return m1_question_pris;
}