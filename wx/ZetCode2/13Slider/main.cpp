#include "main.h"
#include "slider.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Slider *sl = new Slider(wxT("vertical Slider, rgb value "));
   sl->Show(true);
    return true;
}
