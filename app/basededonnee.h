#ifndef BASEDEDONNEE_H_INCLUDED
#define BASEDEDONNEE_H_INCLUDED
#include "theme.h"

class BaseDeDonnee
{
    public:
        BaseDeDonnee(std::string);
        void enregistrer_vainqueur();
        static bool create_player(string pseudo);
        static string get_this_player();
        vector<Question> lire_question();
        vector<string> possible_robot_answers(int);
        Theme lire_theme();
    private:
        std::fstream base;
};

#endif //BASEDEDONNEE_H_INCLUDED
