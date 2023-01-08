#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED
#include "personnage.h"
#include "basededonnee.h"

class Robot: public Personnage
{
    public:
        Robot();
        Robot(string);
        string getPseudo();
        int getScore();
        void setScore(int _score);
        bool buzzer();
        string repondre(int numero_question, int manche);
        Theme choisir_theme(Theme*);
    private:
        string m_pseudo;
        int score;
        bool actif;
        TYPE type;
};

#endif //ROBOT_H_INCLUDE
