//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton
//the icon file doesn't load actually, though there's no error message.

#include "main.h"
#include "icon.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    icon *icon1 = new icon(wxT("Iconic") );
    icon1->Show (true);

    return true;
}
