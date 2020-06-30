//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include "main.h"
#include "gotoclass.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    GotoClass *gotoclass = new GotoClass(wxT("To demonstrate") );
    gotoclass->Show (true);

    return true;
}