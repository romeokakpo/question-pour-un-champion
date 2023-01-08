#ifndef THEME_H_INCLUDE
#define THEME_H_INCLUDE
#include "question.h"

class Theme
{
    public:
        void ajouter_question();
    private:
        string nom;
        vector<Question> questions;
};

#endif //THEME_H_INCLUDE
