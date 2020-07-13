//graphics device interface, device context
#include "main.h"
#include "drawoneline.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit ()
{
    DrawOneLine* dl = new DrawOneLine(wxT("draw a line"));
    dl->Show(true);
    
    return true;
    
}