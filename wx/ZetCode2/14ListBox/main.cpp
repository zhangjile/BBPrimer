#include "main.h"
#include "listbox.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    ListBox *lb = new ListBox(wxT("Listbox, itmes"));
   lb->Show(true);
    return true;
}