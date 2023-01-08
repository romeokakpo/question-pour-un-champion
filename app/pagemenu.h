#ifndef PAGES_H_INCLUDED
#define PAGES_H_INCLUDED
#include "pageinscription.h"

class PageMenu: public wxDialog
{
    public: 
        PageMenu(wxWindow *parent, const wxString& title);
        void OnClose(wxCloseEvent& event);
        void page_inscription(wxCommandEvent &event);
        void OnBtnRegleClicked(wxCommandEvent &event);
        void OnBtnAboutClicked(wxCommandEvent &event);
        void OnBtnQuitterClicked(wxCommandEvent &event);
        void OnBtnHistoryClicked(wxCommandEvent &event);
    private:
        wxPanel *m_panel1;
        wxWindow *m_parent;
        PageInscription *m_inscription;
        wxButton *play, *quit, *lastChampions, *about, *regle;
};

#endif //PAGES_H_INCLUDE
