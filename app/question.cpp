#include "question.h"

Question::Question(string _enonce, string _reponse, int _point):
    enonce(_enonce), reponse(_reponse), point(_point)
{
}

string Question::get_enonce()
{
    return enonce;
}

string Question::get_reponse()
{
    return reponse;
}

int Question::get_point()
{
    return point;
}
