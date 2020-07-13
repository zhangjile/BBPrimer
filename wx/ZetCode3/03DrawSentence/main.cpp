//graphics device interface, device context
#include "main.h"
#include "drawonesentence.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit ()
{
    DrawOneSentence* ds = new DrawOneSentence(wxT("draw a sentence"));
    ds->Show(true);
    
    return true;
    
}