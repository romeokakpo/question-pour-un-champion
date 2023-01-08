#ifndef WXBITMAPBACKGROUND_H_INCLUDES
#define WXBITMAPBACKGROUND_H_INCLUDES

class wxBackgroundBitmap : public wxEvtHandler {
    typedef wxEvtHandler Inherited;
public:
    wxBackgroundBitmap(const wxBitmap &B) : Bitmap(B), wxEvtHandler() { }
    virtual bool ProcessEvent(wxEvent &Event);
protected:
    wxBitmap  Bitmap;
};

#endif //WXBITMAPBACKGROUND_H_INCLUDES