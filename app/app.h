#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

class App: public wxApp
{
    public:
        virtual bool OnInit();
};

DECLARE_APP(App);

#endif //APP_H_INCLUDES