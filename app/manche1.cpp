#include "manche1.h"

wxBEGIN_EVENT_TABLE(Manche1, wxDialog)
    EVT_TIMER(ID_TIMER1_M1, Manche1::OnTimeLeft)
    EVT_TEXT_ENTER(ID_ANSWERS, Manche1::OnValidAnswers)
wxEND_EVENT_TABLE()

Manche1::Manche1(wxWindow *parent, const wxString& title):m_parent(parent), m_timer1(this, ID_TIMER1_M1), 
    robot_timer(this, ID_ROBOT_TIMER)
{
    Create(parent, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT+50));
    SetMinSize(wxSize(WIDTH, HEIGHT));
    SetMaxSize(wxSize(WIDTH, HEIGHT));
    Center();

    m_panel1 = new wxPanel(this);
    wxBoxSizer *sizer_vertical = new wxBoxSizer(wxVERTICAL);
    
    wxBoxSizer *boxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    active_question = animateur.poser_question();
    question = new wxRichTextCtrl(m_panel1, ID_QUESTION_MANCHE1, wxString::Format("Question:\n%s", active_question.get_enonce()),wxDefaultPosition, wxDefaultSize, wxRE_READONLY|wxRE_MULTILINE);
    question->Disable();
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    wxBoxSizer *boxSizer3 = new wxBoxSizer(wxVERTICAL);
    point = new wxRichTextCtrl(m_panel1, wxID_ANY,  wxString::Format("Question de %d point(s)", active_question.get_point()), wxDefaultPosition, wxDefaultSize, wxRE_READONLY|wxRE_MULTILINE);
    point->Disable();

    //Temps d'attente en secondes avant Buzz de chaque Robot
    robot_time_waiting[0] = rand()%(M1_QUIZ_TIME - RBT_MIN_TIME + 1) + RBT_MIN_TIME;
    robot_time_waiting[1] = rand()%(M1_QUIZ_TIME - RBT_MIN_TIME + 1) + RBT_MIN_TIME;
    robot_time_waiting[2] = rand()%(M1_QUIZ_TIME - RBT_MIN_TIME + 1) + RBT_MIN_TIME;

    wxRichTextAttr rchtxtAttr_2;
    rchtxtAttr_2.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    time_left = new wxRichTextCtrl(m_panel1, wxID_ANY, std::to_string(time), wxDefaultPosition, wxDefaultSize, wxRE_READONLY|wxRE_MULTILINE);
    time--;
    time_left->Disable();
    wxRichTextAttr rchtxtAttr_3;
    rchtxtAttr_3.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    boxSizer3->Add(point,1 ,wxALL|wxEXPAND, 5);
    boxSizer3->Add(time_left,1 ,wxALL|wxEXPAND, 5);
    
    boxSizer2->Add(question,1 ,wxALL|wxEXPAND, 5);
    boxSizer2->Add(boxSizer3,1 ,wxALL|wxEXPAND, 5);

    wxBoxSizer *boxSizer4 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *boxSizer5 = new wxBoxSizer(wxVERTICAL);

    wxFlexGridSizer *flexGridSizer1 = new wxFlexGridSizer(3, 4, 0, 0);
    player1 = new wxStaticText(m_panel1, wxID_ANY, wxEmptyString,wxDefaultPosition, wxSize(155,17), wxALIGN_CENTRE);
    flexGridSizer1->Add(player1, 1, wxALL|wxEXPAND, 5);
    player2 = new wxStaticText(m_panel1, wxID_ANY, wxEmptyString,wxDefaultPosition, wxSize(155,17), wxALIGN_CENTRE);
    flexGridSizer1->Add(player2, 1, wxALL|wxEXPAND, 5);
    player3 = new wxStaticText(m_panel1, wxID_ANY, wxEmptyString,wxDefaultPosition, wxSize(155,17), wxALIGN_CENTRE);
    flexGridSizer1->Add(player3, 1, wxALL|wxEXPAND, 5);
    player4 = new wxStaticText(m_panel1, wxID_ANY, wxEmptyString,wxDefaultPosition, wxSize(155,17), wxALIGN_CENTRE);
    flexGridSizer1->Add(player4, 1, wxALL|wxEXPAND, 5);
    score1 = new wxRichTextCtrl(m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(75,75), wxRE_READONLY|wxRE_MULTILINE);
    wxRichTextAttr rchtxtAttr_4;
    rchtxtAttr_4.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    rchtxtAttr_4.SetTextColour(wxColour(40,245,27));
    wxFont Font_4(31,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    rchtxtAttr_4.SetFontFaceName(Font_4.GetFaceName());
    rchtxtAttr_4.SetFontSize(Font_4.GetPointSize());
    rchtxtAttr_4.SetFontStyle(Font_4.GetStyle());
    rchtxtAttr_4.SetFontUnderlined(Font_4.GetUnderlined());
    rchtxtAttr_4.SetFontWeight(Font_4.GetWeight());

    wxRichTextAttr rchtxtAttr_time;
    rchtxtAttr_time.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    rchtxtAttr_time.SetFontFaceName(Font_4.GetFaceName());
    rchtxtAttr_time.SetFontSize(Font_4.GetPointSize());
    rchtxtAttr_time.SetFontStyle(Font_4.GetStyle());
    rchtxtAttr_time.SetFontUnderlined(Font_4.GetUnderlined());

    time_left->SetBasicStyle(rchtxtAttr_time);
    score1->SetBasicStyle(rchtxtAttr_4);
    score1->Disable();
    flexGridSizer1->Add(score1, 1, wxALL|wxEXPAND, 5);
    score2 = new wxRichTextCtrl(m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(75,75), wxRE_READONLY|wxRE_MULTILINE);
    score2->SetBasicStyle(rchtxtAttr_4);
    score2->Disable();
    flexGridSizer1->Add(score2, 1, wxALL|wxEXPAND, 5);
    score3 = new wxRichTextCtrl(m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(75,75), wxRE_READONLY|wxRE_MULTILINE);
    score3->SetBasicStyle(rchtxtAttr_4);
    score3->Disable();
    flexGridSizer1->Add(score3, 1, wxALL|wxEXPAND, 5);
    score4 = new wxRichTextCtrl(m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(75,75), wxRE_READONLY|wxRE_MULTILINE);
    score4->SetBasicStyle(rchtxtAttr_4);
    score4->Disable();
    flexGridSizer1->Add(score4, 1, wxALL|wxEXPAND, 5);
    buzzer[0] = new wxButton(m_panel1, ID_BUZZ1, wxT("Buzzer"));
    buzzer[0]->SetFocus();
    flexGridSizer1->Add(buzzer[0], 1, wxALL|wxEXPAND, 5);
    buzzer[1] = new wxButton(m_panel1, ID_BUZZ2, wxT("Buzzer"));
    buzzer[1]->Disable();
    flexGridSizer1->Add(buzzer[1], 1, wxALL|wxEXPAND, 5);
    buzzer[2] = new wxButton(m_panel1, ID_BUZZ3, wxT("Buzzer"));
    buzzer[2]->Disable();
    flexGridSizer1->Add(buzzer[2], 1, wxALL|wxEXPAND, 5);
    buzzer[3] = new wxButton(m_panel1, ID_BUZZ4, wxT("Buzzer"));
    buzzer[3]->Disable();
    flexGridSizer1->Add(buzzer[3], 1, wxALL|wxEXPAND, 5);
    boxSizer5->Add(flexGridSizer1, 1, wxALL|wxEXPAND, 5);
    animateurMessage = new wxRichTextCtrl(m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(670,60),wxRE_READONLY|wxRE_MULTILINE);
    animateurMessage->Disable();
    boxSizer5->Add(animateurMessage, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer *boxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    answers = new wxTextCtrl(m_panel1, ID_ANSWERS, wxEmptyString, wxDefaultPosition, wxSize(491, 34), wxTE_PROCESS_ENTER);
    answers->Disable();
    answers->SetFocus();
    boxSizer6->Add(new wxStaticText(m_panel1, wxID_ANY, wxT("Saisir votre réponse:")), 1, wxALL, 5);
    boxSizer6->Add(answers, 1, wxALL|wxEXPAND,5);

    pause = new wxButton(m_panel1, ID_PAUSE, wxT("Pause"), wxPoint(5, 5));

    boxSizer4->Add(boxSizer5,1, wxALL|wxEXPAND, 5);
    boxSizer4->Add(boxSizer6,0, wxALL|wxEXPAND, 5);

    sizer_vertical->Add(new wxStaticText(m_panel1, wxID_ANY, wxT("MANCHE 1"), wxDefaultPosition, wxSize(73,32)), 0, wxALIGN_CENTER_HORIZONTAL);
    sizer_vertical->Add(boxSizer2,1,wxALL|wxEXPAND,5);
    sizer_vertical->Add(boxSizer4,1,wxALL|wxEXPAND,5);

    m_panel1->SetSizer(sizer_vertical);

    Show();
    m_timer1.Start(1000);
    Connect(wxID_ANY, wxEVT_CLOSE_WINDOW, wxCommandEventHandler(Manche1::OnBtnQuitterClicked)); 
    Connect(ID_BUZZ1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Manche1::OnBuzzer1BtnClicked));
    Connect(ID_BUZZ2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Manche1::OnBuzzer2BtnClicked));
    Connect(ID_BUZZ3, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Manche1::OnBuzzer3BtnClicked));
    Connect(ID_BUZZ4, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Manche1::OnBuzzer4BtnClicked));
    Connect(ID_PAUSE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Manche1::PauseGame));
    //Bind(wxEVT_CHAR_HOOK, &Manche1::OnBuzzer1BtnClicked, this);
}

void Manche1::PauseGame(wxCommandEvent &event)
{
    if(pause->GetLabel() == wxString("Pause"))
    {
        pause->SetLabel("Reprendre");
        m_timer1.Stop();
    }
    else
    {
        pause->SetLabel("Pause");
        m_timer1.Start();
    }
}

void Manche1::OnBuzzer1BtnClicked(wxCommandEvent &event)
{
    buzzer[0]->SetBackgroundColour(wxColor(255, 51, 51));
    handleBuzzerClick(1); 
}

void Manche1::OnBuzzer2BtnClicked(wxCommandEvent &event)
{
    buzzer[1]->SetBackgroundColour(wxColor(255, 51, 51));
    handleBuzzerClick(2);
}

void Manche1::OnBuzzer3BtnClicked(wxCommandEvent &event)
{
    buzzer[2]->SetBackgroundColour(wxColor(255, 51, 51));
    handleBuzzerClick(3);
}

void Manche1::OnBuzzer4BtnClicked(wxCommandEvent &event)
{
    buzzer[3]->SetBackgroundColour(wxColor(255, 51, 51));
    handleBuzzerClick(4);
}

void Manche1::handleBuzzerClick(int player_id)
{
    m_timer1.Stop();
    animateurMessage->Clear();
    switch(player_id)
    {
        case 1:
            animateurMessage->WriteText(wxString::Format("%s a buzzer",joueurs[0]->getPseudo()));
            answers->Enable();
            answers->SetFocus();
            buzzer[0]->Disable();
            whoBuzz = 1;
            break;
        case 2:
        case 3:
        case 4:
            animateurMessage->WriteText(wxString::Format("%s a buzzer",robots[player_id-2]->getPseudo()));
            buzzer[0]->Disable();
            answers->Disable();
            whoBuzz = player_id;
            answers->AppendText(robots[player_id-2]->repondre(animateur.get_nbr_quizz_m1(), animateur.getManche()));
            OnValidRobotAnswers();
            break;
    }
    answers->Clear();
}

void Manche1::OnValidAnswers(wxCommandEvent &event)
{
    m_timer1.Start();
    animateurMessage->Clear();
    animateurMessage->WriteText(wxString::Format("%s a ecrit:\n%s",joueurs[0]->getPseudo(),string(answers->GetValue())));   
    next();
}

void Manche1::OnValidRobotAnswers()
{
    animateurMessage->Clear();
    animateurMessage->WriteText(wxString::Format("%s a ecrit:\n%s",robots[whoBuzz-2]->getPseudo(),string(answers->GetValue())));   
    m_timer1.Start();
    next();
}

void Manche1::OnBtnQuitterClicked(wxCommandEvent &event)
{
    wxMessageDialog *msg = new wxMessageDialog(NULL, wxT("Etes vous sur de vouloir quitter ?\nLa progression sera perdue !"), wxT("Quitter"), wxYES_NO|wxCENTRE|wxICON_QUESTION|wxNO_DEFAULT);
    if(msg->ShowModal() == wxID_YES)
    {
        Hide();
        m_parent->Close();
    }
}

void Manche1::creerPlayers(string pseudo,string profession, string pays, int mode, int nbr_players)
{
    if(mode == 1)
    {
        joueurs[0] = new Joueur(pseudo,  profession, pays);
        player1->SetLabel(pseudo);
        robots[0] = new Robot("Romeo");
        robots[1] = new Robot("Osee");
        robots[2] = new Robot("Mauriac");

        player2->SetLabel(robots[0]->getPseudo().c_str());
        player3->SetLabel(robots[1]->getPseudo().c_str());
        player4->SetLabel(robots[2]->getPseudo().c_str());

        score1->WriteText(wxString::Format("%d",joueurs[0]->getScore()));
        score2->WriteText(wxString::Format("%d",robots[0]->getScore()));
        score3->WriteText(wxString::Format("%d",robots[1]->getScore()));
        score4->WriteText(wxString::Format("%d",robots[2]->getScore()));

        animateurMessage->WriteText(wxString::Format("Animateur:\n%s",animateur.jeu_commence()));
    }
    else if(mode == 2)
    {
        //Mode Multi-joueur
    }
}

void Manche1::OnTimeLeft(wxTimerEvent& event)
{
    time_left->Clear();
    time_left->WriteText(wxString::Format("%d", time));
    for(int i{}; i < 3; i++)
    {
        robot_time_waiting[i]--;
        if(!robot_time_waiting[i] && robots[i]->getScore() != 9)
        {
            wxCommandEvent click(wxEVT_COMMAND_BUTTON_CLICKED, buzzer[i+1]->GetId());
            click.SetEventObject(buzzer[i+1]);
            buzzer[i+1]->Command(click);
        }
    }
    if(joueurs[0]->getScore() == 9) buzzer[0]->Disable();
    if(!time)
    {
        m_timer1.Stop();
        next();
        time++;
    }
    time--;
}

void Manche1::next()
{
    if(!time)
    {
        //Donner la réponse
        animateurMessage->Clear();
        animateurMessage->BeginTextColour(wxColour(51, 255, 0));
        animateurMessage->WriteText(wxString::Format("Animateur: Temps ecoule !\nLa reponse est: %s",active_question.get_reponse()));
        animateurMessage->EndTextColour();
        this->Update();
        if(joueurs[0]->getScore() == 9) 
            wxSleep(1);
        else
            wxSleep(3);
        animateurMessage->Clear();
    }
    else
    {
        //vÉRIFICATION DE LA RÉPONSE
        string reponse_user{answers->GetValue()};
        transform(reponse_user.begin(), reponse_user.end(), reponse_user.begin(), toupper);
        if(whoBuzz == 1)
        {   
            answers->Clear();
            answers->Disable();
            if(reponse_user == active_question.get_reponse())
            { 
                joueurs[0]->setScore(joueurs[0]->getScore()+active_question.get_point());
                player_left -=  (joueurs[0]->getScore() == 9)?1:0;

                animateurMessage->BeginTextColour(wxColour(51, 255, 0));
                animateurMessage->WriteText(" ---> BONNE REPONSE !!!");
                animateurMessage->EndTextColour();
                score1->Clear();
                score1->WriteText(wxString::Format("%d",joueurs[0]->getScore()));
                score2->Clear();
                score2->WriteText(wxString::Format("%d",robots[0]->getScore()));
                score3->Clear();
                score3->WriteText(wxString::Format("%d",robots[1]->getScore()));
                score4->Clear();
                score4->WriteText(wxString::Format("%d",robots[2]->getScore()));
                this->Update();
                wxSleep(3);
                animateurMessage->Clear();
            }
            else
            {
                animateurMessage->BeginTextColour(wxColour(204, 0, 0));
                animateurMessage->WriteText(" ---> FAUX !!!");
                animateurMessage->EndTextColour();
                buzzer[0]->Disable();
                return;
            }
        }
        else
        {
            if(reponse_user == active_question.get_reponse())
            {
                robots[whoBuzz-2]->setScore(robots[whoBuzz-2]->getScore()+active_question.get_point());
                player_left -=  (robots[whoBuzz-2]->getScore() == 9)?1:0;

                animateurMessage->BeginTextColour(wxColour(51, 255, 0));
                animateurMessage->WriteText(" ---> BONNE REPONSE !!!");
                animateurMessage->EndTextColour();
                score1->Clear();
                score1->WriteText(wxString::Format("%d",joueurs[0]->getScore()));
                score2->Clear();
                score2->WriteText(wxString::Format("%d",robots[0]->getScore()));
                score3->Clear();
                score3->WriteText(wxString::Format("%d",robots[1]->getScore()));
                score4->Clear();
                score4->WriteText(wxString::Format("%d",robots[2]->getScore()));
                this->Update();
                if(joueurs[0]->getScore() == 9) 
                    wxSleep(1);
                else
                    wxSleep(3);
                animateurMessage->Clear();
            }
            else
            {
                animateurMessage->BeginTextColour(wxColour(204, 0, 0));
                animateurMessage->WriteText(" ---> FAUX !!!");
                animateurMessage->EndTextColour();
                buzzer[0]->Enable();
                buzzer[0]->SetFocus();
                return;
            }
        }

        if(player_left == 1)
        {
            m_timer1.Stop();
            vector<string> v;
            if(joueurs[0]->getScore() == 9)
                buzzer[0]->SetBackgroundColour(wxColour(51, 255, 0));
            if(robots[0]->getScore() == 9)
                buzzer[1]->SetBackgroundColour(wxColour(51, 255, 0));
            if(robots[1]->getScore() == 9)
                buzzer[2]->SetBackgroundColour(wxColour(51, 255, 0));
            if(robots[2]->getScore() == 9)
                buzzer[3]->SetBackgroundColour(wxColour(51, 255, 0));
            if(joueurs[0]->getScore() == 9) v.push_back(joueurs[0]->getPseudo());
            for(int i{}; i < 3; i++)
            {
                if(robots[i]->getScore() == 9) v.push_back(robots[i]->getPseudo());
            }
            wxMessageBox(wxString::Format("Vainqueur de la manche 1:\n\n%s\n%s\n%s\n\nA la prochaine pour manche 2 !", v[0],v[1],v[2]), wxT("Vainqueur de la manche 1"),wxOK|wxICON_INFORMATION, this);
            pause->Disable();
            return;
        }
    } 

    //Passage à la prochaine question
    active_question = animateur.poser_question();

    time = M1_QUIZ_TIME;
    m_timer1.Start();
    
    question->Clear();
    question->WriteText(wxString::Format("Question:\n%s", active_question.get_enonce()));

    point->Clear();
    point->WriteText(wxString::Format("Question de %d point(s)", active_question.get_point()));

    //Temps d'attente en secondes avant Buzz de chaque Robot
    robot_time_waiting[0] = rand()%(M1_QUIZ_TIME - RBT_MIN_TIME + 1) + RBT_MIN_TIME;
    robot_time_waiting[1] = rand()%(M1_QUIZ_TIME - RBT_MIN_TIME + 1) + RBT_MIN_TIME;
    robot_time_waiting[2] = rand()%(M1_QUIZ_TIME - RBT_MIN_TIME + 1) + RBT_MIN_TIME;
    //Remettre les Buzzers
    buzzer[0]->Enable();
    for(int i{}; i < 4; i++)
        buzzer[i]->SetBackgroundColour(wxTransparentColour);
    if(joueurs[0]->getScore() == 9)
        buzzer[0]->SetBackgroundColour(wxColour(51, 255, 0));
    if(robots[0]->getScore() == 9)
        buzzer[1]->SetBackgroundColour(wxColour(51, 255, 0));
    if(robots[1]->getScore() == 9)
        buzzer[2]->SetBackgroundColour(wxColour(51, 255, 0));
    if(robots[2]->getScore() == 9)
        buzzer[3]->SetBackgroundColour(wxColour(51, 255, 0));
    buzzer[0]->SetFocus();
}