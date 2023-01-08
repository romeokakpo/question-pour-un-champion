#include "robot.h"

Robot::Robot()
{

}

Robot::Robot(string pseudo): m_pseudo(pseudo), score(0)
{

}

string Robot::getPseudo()
{
    return m_pseudo;
}

int Robot::getScore()
{
    return score;
}

void Robot::setScore(int _score)
{
    score = (_score <= 9)?_score:9;
}

bool Robot::buzzer()
{
    return true;
}

Theme Robot::choisir_theme(Theme*)
{
    Theme theme;
    return theme;
}

string Robot::repondre(int numero_question, int manche)
{
    string result;
    switch(manche)
    {
        case 1:
            BaseDeDonnee base("fichiers/mche1_robot_answers");
            vector<string> ans = base.possible_robot_answers(numero_question);
            return ans[rand()%(ans.size())];
            break;
    }
    return string{};
}