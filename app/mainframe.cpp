#include "mainframe.h"

MainFrame::MainFrame(const wxString& title)
{
    srand((unsigned)time(NULL));
    Create(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    SetMinSize(wxSize(WIDTH, HEIGHT));
    SetMaxSize(wxSize(WIDTH, HEIGHT));
    Center();

    m_panel1 = new wxPanel(this);

    page_Acceuil();

}

 void MainFrame::page_Acceuil()
 {
    wxBitmap TempBitmap;
	TempBitmap.LoadFile("images/QPUC.jpg",wxBITMAP_TYPE_JPEG);
	acceuilBackground = new wxBackgroundBitmap(TempBitmap);
	m_panel1->PushEventHandler(acceuilBackground);

    start = new wxButton(m_panel1, ID_START_APP, "Commencer", wxPoint(270,450), wxSize(150, 50));

    Connect(ID_START_APP, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::page_Menu));
 }

void MainFrame::page_Menu(wxCommandEvent &event)
{ 
    this->Hide();
    menu = new PageMenu(this, "Question Pour un champion - Menu");
}

MainFrame::~MainFrame()
{
    m_panel1->RemoveEventHandler(acceuilBackground);
}