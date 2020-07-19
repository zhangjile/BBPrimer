//graphics device interface, device context
#include "main.h"
#include "shapes.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit ()
{
    Shapes* sh = new Shapes(wxT("geometric shapes"));
    sh->Show(true);
    
    return true;
    
}