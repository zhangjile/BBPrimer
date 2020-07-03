#include "main.h"
#include "checkbox.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    CheckBox *check = new CheckBox(wxT("CheckBox!"));
    check->Show(true);

    return true;
}