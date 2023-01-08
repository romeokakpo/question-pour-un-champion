#include "joueur.h"

Joueur::Joueur(): type(TYPE::HUMAN)
{

}

Joueur::Joueur(string pseudo, string profession, string pays):m_pseudo(pseudo),
    m_profession(profession), m_pays(pays), score(0),  type(TYPE::HUMAN)
{

}

string Joueur::getPseudo()
{
    return m_pseudo;
}

void Joueur::setScore(int _score)
{
    score = (_score <= 9)?_score:9;
}

int Joueur::getScore()
{
    return score;
}

bool Joueur::buzzer()
{
    return true;
}

string Joueur::repondre(Question*)
{
    return "hi";
}

Theme Joueur::choisir_theme(Theme*)
{
    Theme theme;
    return theme;
}
