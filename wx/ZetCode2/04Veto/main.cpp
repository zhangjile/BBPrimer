#include "main.h"
#include "veto.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Veto *ve = new Veto(wxT("Veto event"));
    ve->Show(true);

    return true;
}