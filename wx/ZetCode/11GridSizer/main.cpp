//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include "main.h"
#include "gridsizer.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    GridSizer *gridsizer = new GridSizer(wxT("Grid") );
    gridsizer->Show (true);

    return true;
}