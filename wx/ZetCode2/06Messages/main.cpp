#include "main.h"
#include "massages.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Massages *mess = new Massages(wxT("massage!"));
    mess->Show(true);

    return true;
}