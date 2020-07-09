#include "main.h"
#include "NoteBook.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    NoteBook *nb = new NoteBook(wxT("NoteBook, Spreadsheet"));
   nb->Show(true);
    return true;
}