#ifndef QUESTION_H_INCLUDE
#define QUESTION_H_INCLUDE
#include "constantes.h"

class Question
{
    private:
        string enonce, reponse;
        int point;
    public:
        Question(){}
        Question(string _enonce, string _reponse, int _point);
        string get_enonce();
        string get_reponse();
        int get_point();
};

#endif //QUESTION_H_INCLUDE
