#include "menu.h"


SimpleMenu::SimpleMenu(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{

  menubar = new wxMenuBar;
  file = new wxMenu;
  
  file->Append(wxID_ANY, wxT("&New") );
  file->Append(wxID_ANY, wxT("&Open") );
  file->Append(wxID_ANY, wxT("&Save") );
  file->AppendSeparator();
  
  imp = new wxMenu;
  imp->Append(wxID_ANY, wxT("Import newsfeed list ...") );
  imp->Append(wxID_ANY, wxT("Import Bookmarks ...") );
  imp->Append(wxID_ANY, wxT("Import emails ...") );
  
  file->AppendSubMenu(imp,  wxT ("&Import   "));        //observe the effect
  
  quit = new wxMenuItem(file, wxID_EXIT, wxT ("&Quit\tCtrl + W") );
  file->Append(quit );
  
  menubar->Append(file, wxT("&File"));
  SetMenuBar(menubar);

  Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(SimpleMenu::OnQuit));
  Centre();

}

void SimpleMenu::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  Close(true);
}