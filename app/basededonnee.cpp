#include "basededonnee.h"

BaseDeDonnee::BaseDeDonnee(string nom)
{
    base.open(nom.c_str());
    if(!base.is_open())
        std::cout<<"Erreur !";
}

void BaseDeDonnee::enregistrer_vainqueur()
{

}

bool BaseDeDonnee::create_player(string pseudo)
{
    std::ofstream new_player(pseudo);
    if(new_player.is_open())
    {
        new_player<<pseudo<<std::endl;
        return true;
    }
    return false;
}


vector<Question> BaseDeDonnee::lire_question()
{
    int i{1};
    string lu, enonce, reponse;
    vector<Question> retour;
    while(getline(base, lu))
    {
        istringstream ss{lu};
        getline(ss, enonce, '|');
        getline(ss, reponse);
        retour.push_back(Question(enonce, reponse, i));
        i = (++i == 4)?1:i;
    }
    return retour;
}

vector<string> BaseDeDonnee::possible_robot_answers(int line)
{
    vector<string> possible_answers;
    string lu, ans;
    for(int i{}; i < line; i++) getline(base, lu);
    if(lu != "")
    {

        istringstream ss{lu};
        while(getline(ss, ans, '|'))
        {
            possible_answers.push_back(ans);
        }
    }
    return possible_answers;
}
/*
Theme BaseDeDonnee::lire_theme()
{

}*/