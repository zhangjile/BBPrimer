#include "main.h"
#include "togglebutton.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    ToggleButton *tbt = new ToggleButton(wxT("Toggle button"));
    tbt->Centre();
    tbt->Show(true);

    return true;
}