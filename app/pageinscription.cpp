#include "pageinscription.h"

//-------------------Page Inscrition----------------------
//Cette Page contient les champs pour l'inscription
PageInscription::PageInscription(wxWindow *parent, wxWindow *prev, const wxString& title):m_parent(parent), m_prev(prev)
{
    Create(parent, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    SetMinSize(wxSize(WIDTH, HEIGHT));
    SetMaxSize(wxSize(WIDTH, HEIGHT));
    Center();

    m_panel1 = new wxPanel(this);

    wxBoxSizer *sizer_vertical = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *sizer_horz1 = new wxBoxSizer(wxHORIZONTAL);
    retour = new wxButton(m_panel1, ID_RETOUR, _("Retour"));
    sizer_horz1->Add(retour, 1, wxALL, 5);

    startGame = new wxButton(m_panel1, ID_START_GAME, _("Commencer la partie"), wxPoint(275, 500));
    startGame->Disable();
    
    wxStaticBoxSizer *bSizer1 = new wxStaticBoxSizer(wxVERTICAL, m_panel1, _("Nouveau Joueur"));
    wxFlexGridSizer *flexGridSizer1 = new wxFlexGridSizer(4, 2, 0, 0);
    flexGridSizer1->AddGrowableCol(1);
    flexGridSizer1->Add(new wxStaticText(m_panel1, wxID_ANY,wxT("Pseudo")), 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    pseudo = new wxTextCtrl(m_panel1, ID_PSEUDO, wxEmptyString);
    flexGridSizer1->Add(pseudo, 1, wxALL|wxEXPAND, 5);
    flexGridSizer1->Add(new wxStaticText(m_panel1, wxID_ANY,wxT("Profession")), 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    profession = new wxTextCtrl(m_panel1, ID_PROFESSION, wxEmptyString);
    flexGridSizer1->Add(profession, 1, wxALL|wxEXPAND, 5);
    flexGridSizer1->Add(new wxStaticText(m_panel1, wxID_ANY,wxT("Pays")), 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    pays = new wxTextCtrl(m_panel1, ID_PAYS, wxEmptyString);
    flexGridSizer1->Add(pays, 1, wxALL|wxEXPAND, 5);

    wxString choices1[] = {"Mode Solo", "Multi-Joueurs"};
    game_mode = new wxRadioBox(m_panel1, ID_GAMEMODE, wxT("Mode de Jeu"), wxDefaultPosition, wxDefaultSize, 2, choices1, 0, wxRA_SPECIFY_COLS|wxBORDER_NONE);
    bSizer1->Add(flexGridSizer1, 1, wxALL|wxEXPAND, 5);
    flexGridSizer1->Add(game_mode, 1, wxALL|wxEXPAND, 5);

    m_panel2 = new wxPanel(m_panel1);
    bSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, m_panel2, _("Multi-Joueur"));
    wxStaticBoxSizer *bSizer3 = new wxStaticBoxSizer(wxVERTICAL, m_panel2, wxT("Créer la partie"));
    wxStaticBoxSizer *bSizer4 = new wxStaticBoxSizer(wxVERTICAL, m_panel2, _("Rejoindre la partie"));

    creer = new wxButton(m_panel2, ID_CREER, wxT("Créer la partie"));
    rejoindre = new wxButton(m_panel2, ID_REJOINDRE, wxT("Rejoindre"));
    creer->Disable();
    rejoindre->Disable();
    code = new wxTextCtrl(m_panel2, ID_CODE,wxEmptyString);
    code->Disable();
    wxString choices2[] = {"2", "3", "4"};
    nbr_players = new wxRadioBox(m_panel2, wxID_ANY, wxT("Nombre de Joueurs"), wxDefaultPosition, wxDefaultSize, 3, choices2, 0, wxRA_SPECIFY_COLS|wxBORDER_NONE);
    bSizer3->Add(nbr_players, 1, wxALL|wxEXPAND, 5);
    bSizer3->Add(creer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
    bSizer4->Add(code, 1, wxALL|wxEXPAND,5);
    bSizer4->Add(rejoindre, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    bSizer2->Add(bSizer3, 1, wxALL|wxEXPAND, 5);
    bSizer2->Add(bSizer4, 1, wxALL|wxEXPAND, 5);

    m_panel2->SetSizer(bSizer2);
    sizer_vertical->Add(sizer_horz1, 0, wxALL, 5);
    sizer_vertical->Add(bSizer1, 0, wxALL|wxEXPAND, 5);
    sizer_vertical->Add(m_panel2, 0, wxALL|wxEXPAND, 5);

    m_panel1->SetSizer(sizer_vertical);
    Show();
    m_panel2->Disable();
    Connect(wxID_ANY, wxEVT_CLOSE_WINDOW, wxCommandEventHandler(PageInscription::OnBtnQuitterClicked)); 
    Connect(ID_RETOUR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageInscription::OnBtnRetourClicked));
    Connect(ID_START_GAME, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageInscription::page_start));
    Connect(ID_REJOINDRE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageInscription::page_start));
    Connect(ID_GAMEMODE, wxEVT_RADIOBOX, wxCommandEventHandler(PageInscription::OnGameModeClicked));
    Connect(ID_PSEUDO, wxEVT_TEXT, wxCommandEventHandler(PageInscription::OnTextEnter));
    Connect(ID_PROFESSION, wxEVT_TEXT, wxCommandEventHandler(PageInscription::OnTextEnter));
    Connect(ID_PAYS, wxEVT_TEXT, wxCommandEventHandler(PageInscription::OnTextEnter));
}

void PageInscription::OnTextEnter(wxCommandEvent& event)
{
    if(!(pseudo->IsEmpty()) && !(profession->IsEmpty()) && !(pays->IsEmpty()))
    {
        startGame->Enable();
        creer->Enable();
        rejoindre->Enable();
    }   
    else
    {
        startGame->Disable();
        creer->Disable();
        rejoindre->Disable();
    }     
}

void PageInscription::OnGameModeClicked(wxCommandEvent &event)
{
    if(game_mode->GetSelection())
    {
        m_panel2->Enable();
    }    
    else
        m_panel2->Disable();
}

void PageInscription::OnBtnQuitterClicked(wxCommandEvent &event)
{
    wxMessageDialog *msg = new wxMessageDialog(NULL, wxT("Etes vous sur de vouloir quitter ?"), wxT("Quitter"), wxYES_NO|wxCENTRE|wxICON_QUESTION|wxNO_DEFAULT);
    if(msg->ShowModal() == wxID_YES)
    {
        this->Hide();
        m_parent->Close();
    }
}

void PageInscription::page_start(wxCommandEvent &event)
{
    Hide();
    m_manche1 = new Manche1(m_parent, "Question Pour un champion - Manche 1");
    m_manche1->creerPlayers(string(pseudo->GetValue()),string(profession->GetValue()),string(pays->GetValue()));

    //Partie du mode multi-joueur non implémenté
}

void PageInscription::OnBtnRetourClicked(wxCommandEvent &event)
{
    this->Hide();
    m_prev->Show();
}