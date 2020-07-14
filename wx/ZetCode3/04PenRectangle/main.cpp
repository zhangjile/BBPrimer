//graphics device interface, device context
#include "main.h"
#include "pen.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit ()
{
    Pen* ds = new Pen(wxT("draw a square"));
    ds->Show(true);
    
    return true;
    
}