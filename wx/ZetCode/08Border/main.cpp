//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include "main.h"
#include "border.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    Border *border = new Border(wxT("To demonstrate") );
    border->Show (true);

    return true;
}