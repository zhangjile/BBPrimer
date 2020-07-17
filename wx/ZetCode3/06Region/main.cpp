//graphics device interface, device context
#include "main.h"
#include "regions.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit ()
{
    Regions* r = new Regions(wxT("regions"));
    r->Show(true);
    
    return true;
    
}