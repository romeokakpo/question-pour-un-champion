#ifndef MANCHE1_H_INCLUDED
#define MANCHE1_H_INCLUDED

#include <wx/richtext/richtextctrl.h>
#include "constantes.h"
#include "animateur.h"

#define M1_QUIZ_TIME 20
#define RBT_MIN_TIME 5

class Manche1: public wxDialog
{
    public:
        Manche1(wxWindow *parent, const wxString& title);
        void creerPlayers(string, string, string, int mode = 1, int nbr_players = 2);
        void OnBuzzer1BtnClicked(wxCommandEvent &event);
        void OnBuzzer2BtnClicked(wxCommandEvent &event);
        void OnBuzzer3BtnClicked(wxCommandEvent &event);
        void OnBuzzer4BtnClicked(wxCommandEvent &event);
        void PauseGame(wxCommandEvent &event);
        void OnBtnQuitterClicked(wxCommandEvent &event);
        void OnValidAnswers(wxCommandEvent &event);
        void OnValidRobotAnswers();
        void handleBuzzerClick(int player_id);
        void OnTimeLeft(wxTimerEvent& event);
        void next();

    private:
        wxPanel *m_panel1;
        wxWindow *m_parent;
        wxRichTextCtrl *question, *time_left, *point;
        wxStaticText *player1, *player2, *player3, *player4;
        wxButton *buzzer[4], *pause;
        wxRichTextCtrl *score1, *score2, *score3, *score4, *animateurMessage;
        wxTextCtrl *answers;
        wxTimer m_timer1, robot_timer;
        int whoBuzz;

        //Backend process
        Joueur *joueurs[4];
        Robot *robots[3];
        Animateur animateur;
        Question active_question;
        int time{M1_QUIZ_TIME}, player_left{4};
        int robot_time_waiting[3];

        wxDECLARE_EVENT_TABLE();
};

#endif