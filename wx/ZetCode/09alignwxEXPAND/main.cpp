//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include "main.h"
#include "align.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    Align *align = new Align(wxT("To demonstrate") );
    align->Show (true);

    return true;
}