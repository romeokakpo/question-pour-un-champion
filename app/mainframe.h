#ifndef MAINFRAME_H_INCLUDED
#define MAINFRAME_H_INCLUDED
#include "wxBitmapBackground.h"
#include "pagemenu.h"

class MainFrame: public wxFrame
{
    public:
        MainFrame(const wxString& title);
        void page_Acceuil();
        void page_Menu(wxCommandEvent &event);
        ~MainFrame();

    private:
        wxPanel *m_panel1;
        PageMenu *menu;
        wxBackgroundBitmap* acceuilBackground;
        wxButton *start;
};

#endif //MAINFRAME_H_INCLUDED
