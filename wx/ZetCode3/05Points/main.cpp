//graphics device interface, device context
#include "main.h"
#include "points.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit ()
{
    Points* p = new Points(wxT("draw points"));
    p->Show(true);
    
    return true;
    
}