#include "main.h"
#include "openfile.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    OpenFile *mess = new OpenFile(wxT("OpenHere!"));
    mess->Show(true);

    return true;
}