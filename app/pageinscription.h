#ifndef PAGEINSCRIPTION_H_INCLUDED
#define PAGEINSCRIPTION_H_INCLUDED

#include "manche1.h"

class PageInscription: public wxDialog
{
    public:
        PageInscription(wxWindow *parent, wxWindow *prev, const wxString& title);
        void page_start(wxCommandEvent &event);
        void OnBtnQuitterClicked(wxCommandEvent &event);
        void OnBtnRetourClicked(wxCommandEvent &event);
        void OnGameModeClicked(wxCommandEvent &event);
        void OnTextEnter(wxCommandEvent& event);

    private:
        wxWindow *m_parent, *m_prev;
        wxPanel *m_panel1, *m_panel2;
        Manche1 *m_manche1;
        wxButton *retour, *startGame, *rejoindre, *creer;
        wxTextCtrl *pseudo, *profession, *pays, *code;
        wxRadioBox *game_mode, *nbr_players;
        wxStaticBoxSizer *bSizer2;
};

#endif