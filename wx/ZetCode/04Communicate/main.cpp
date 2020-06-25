//g++ main.cpp button.h  `wx-config --cxxflags --libs` -o ExitButton

#include "main.h"
#include "communicate.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Communicate *communicate = new Communicate(wxT("Widgets communicate"));
    communicate->Show(true);

    return true;
}