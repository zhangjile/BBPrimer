//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include "main.h"
#include "toolbar.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    Toolbar *toolbar = new Toolbar(wxT("ToolBar") );
    toolbar->Show (true);

    return true;
}