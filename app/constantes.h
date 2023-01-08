#ifndef CONSTANTES_H_INCLUDE
#define CONSTANTES_H_INCLUDE

#define WIDTH 700
#define HEIGHT 600

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cstdlib>

using std::string; using std::vector;
using std::istringstream;

//Enumération pour les constantes
enum
{
    ID_START_APP = wxID_HIGHEST + 1,
    ID_PLAY,
    ID_QUIT,
    ID_LASTCHAMPIONS,
    ID_ABOUT,
    ID_REGLE,
    ID_RETOUR,
    ID_START_GAME,
    ID_PSEUDO,
    ID_PAYS,
    ID_PROFESSION,
    ID_REJOINDRE, 
    ID_CREER,
    ID_CODE,
    ID_QUESTION_MANCHE1,
    ID_GAMEMODE,
    ID_TIMERM1,
    ID_BUZZ1,
    ID_BUZZ2,
    ID_BUZZ3,
    ID_BUZZ4,
    ID_TIMER1_M1,
    ID_ANSWERS,
    ID_ROBOT_TIMER,
    ID_PAUSE
};

//Pour retirer les espaces de début et de fin
/*void string_trim(std::string& str)
{
    str.erase(str.begin(),std::find_if_not(str.begin(), str.end(), isspace));
    std::reverse(str.begin(), str.end());
    str.erase(str.begin(),std::find_if_not(str.begin(), str.end(), isspace));
    std::reverse(str.begin(), str.end());
}*/

#endif //CONSTANTES_H_INCLUDE