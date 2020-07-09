#include "main.h"
#include "scrwindow.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    ScrWindow *sw = new ScrWindow(wxT("scroll to view"));
   sw->Show(true);
    return true;
}