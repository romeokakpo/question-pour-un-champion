#ifndef QUESTIONNAIRE_H_INCLUDE
#define QUESTIONNAIRE_H_INCLUDE
#include "question.h"
#include "theme.h"
#include "basededonnee.h"

class Questionnaire
{
    public:
        Questionnaire();
        int getNbrQuestionPris();
        Question prendre_question();
    private:
        std::vector<Question> questions_m1;
        std::vector<Theme> themes;
        int m1_question_pris = 0;
};

#endif //QUESTIONNAIRE_H_INCLUDE
