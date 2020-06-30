//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include "main.h"
#include "flexgridsizer.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    FlexGridSizer *gridsizer = new FlexGridSizer(wxT("FlexGrid") );
    gridsizer->Show (true);

    return true;
}