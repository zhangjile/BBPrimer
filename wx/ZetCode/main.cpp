//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "button.h"

class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Button *btnapp = new Button(wxT("globe"));
    btnapp->Show(true);

    return true;
}