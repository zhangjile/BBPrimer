//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton
//make 3 changes in absolute.cpp file and absolute positioning is switched to flexible positioning using sizer

#include "main.h"
#include "absolute.h"

IMPLEMENT_APP(cApp)

bool cApp::OnInit()
{

    Absolute *absolute = new Absolute(wxT("To demonstrate") );
    absolute->Show (true);

    return true;
}
