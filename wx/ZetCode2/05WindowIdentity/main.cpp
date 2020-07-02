#include "main.h"
#include "ident.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Ident *id = new Ident(wxT("window identity number"));
    id->Show(true);

    return true;
}