#include "pagemenu.h"

PageMenu::PageMenu(wxWindow *parent, const wxString& title):m_parent(parent)
{
    Create(parent, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    SetMinSize(wxSize(WIDTH, HEIGHT));
    SetMaxSize(wxSize(WIDTH, HEIGHT));
    Center();

    m_panel1 = new wxPanel(this);

    play = new wxButton(m_panel1, ID_PLAY, _("Jouer une partie"), wxPoint(230,122), wxSize(208,50));
    lastChampions = new wxButton(m_panel1, ID_LASTCHAMPIONS, _("Historique des champions"), wxPoint(230,186), wxSize(208,50));
    regle = new wxButton(m_panel1, ID_REGLE, wxT("Règle du jeu"), wxPoint(230,250), wxSize(208,50));
    about = new wxButton(m_panel1, ID_ABOUT, _("A propos"), wxPoint(230,314), wxSize(208,50));
    quit = new wxButton(m_panel1, ID_QUIT, _("Quitter"), wxPoint(230,378), wxSize(208,50));
    Show();

    Connect(wxID_ANY, wxEVT_CLOSE_WINDOW, wxCommandEventHandler(PageMenu::OnBtnQuitterClicked));
    Connect(ID_PLAY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageMenu::page_inscription));
    Connect(ID_ABOUT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageMenu::OnBtnAboutClicked));
    Connect(ID_REGLE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageMenu::OnBtnRegleClicked));
    Connect(ID_QUIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageMenu::OnBtnQuitterClicked));
    Connect(ID_LASTCHAMPIONS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageMenu::OnBtnHistoryClicked));
}


void PageMenu::page_inscription(wxCommandEvent &event)
{
    this->Hide();
    m_inscription = new PageInscription(m_parent,this, "Question Pour un champion - Inscription");
}

void PageMenu::OnBtnRegleClicked(wxCommandEvent &event)
{
    std::ifstream fic("fichiers/regle.txt");
    if(fic.is_open())
    {
        std::string lu, affichage;
        while(getline(fic, lu))
            affichage += lu + "\n";
        wxDialog *affiche = new wxDialog(this, wxID_ANY,_T("Règle du jeu"), wxDefaultPosition, wxSize(600,500));
        affiche->Center();
        wxPanel *afPanel = new wxPanel(affiche);
        wxBoxSizer *sizer1 = new wxBoxSizer(wxVERTICAL);

        wxRichTextCtrl *rich1 = new wxRichTextCtrl(afPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxRE_READONLY|wxRE_MULTILINE);
        rich1->WriteText(affichage.c_str());
        sizer1->Add(rich1, 1, wxALL|wxEXPAND, 5);

        afPanel->SetSizer(sizer1);
        affiche->ShowModal();
    }
    else
        wxMessageBox(wxT("Une erreur interne est survenue.\n"), wxT("Echec du chargement"),wxOK|wxICON_WARNING, this);
}

void PageMenu::OnBtnHistoryClicked(wxCommandEvent &event)
{
    wxMessageBox(wxT("Pas encore de champions\n"), wxT("Historique des Champions"),wxOK|wxICON_INFORMATION, this);
}
void PageMenu::OnBtnAboutClicked(wxCommandEvent &event)
{
    wxMessageBox(wxT("Question pour un Champion\n\nUn super gestionnaire du jeu Question pour un champion.\n\nAuteurs:\n\tKAKPO Roméo\n\tALODEHOU Osée\n\tGNELE Mauriac\n\nSuperviseur:\n\tMédésu SOGBOHOSSOU\n\nCopyright (c) 2022\n"), wxT("A propos"),wxOK|wxICON_INFORMATION, this);
}

void PageMenu::OnBtnQuitterClicked(wxCommandEvent &event)
{
    wxMessageDialog *msg = new wxMessageDialog(NULL, wxT("Etes vous sur de vouloir quitter ?"), wxT("Quitter"), wxYES_NO|wxCENTRE|wxICON_QUESTION|wxNO_DEFAULT);
    if(msg->ShowModal() == wxID_YES)
    {
        Hide();
        m_parent->Close();
    }
}


//-----------------MANCHE 1--------------------

