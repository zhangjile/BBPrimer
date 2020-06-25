//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include "main.h"
#include "menu.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    SimpleMenu *menu1 = new SimpleMenu(wxT("A menu") );
    menu1->Show (true);

    return true;
}