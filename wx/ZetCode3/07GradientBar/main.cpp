//graphics device interface, device context
#include "main.h"
#include "gradient.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit ()
{
    Gradient* grad = new Gradient(wxT("gradient bar"));
    grad->Show(true);
    
    return true;
    
}