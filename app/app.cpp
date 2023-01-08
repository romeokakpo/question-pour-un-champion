#include "app.h"
#include "mainframe.h"

IMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame *fen = new MainFrame(_T("Question pour un Champion"));
    fen->Show();
    return true;
}