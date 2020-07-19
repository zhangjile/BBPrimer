//the burning/downloading process is visually displayed
#include "main.h"
#include "burning.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit ()
{
    Burning* bu = new Burning(wxT("progress of burning/downloading"));
    bu->Show(true);
    
    return true;
    
}