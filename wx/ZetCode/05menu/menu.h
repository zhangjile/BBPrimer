#include <wx/wx.h>
#include <wx/menu.h>

class SimpleMenu : public wxFrame
{
public:
    SimpleMenu (const wxString& tittle);
    void OnQuit (wxCommandEvent& event);
    
    wxMenuBar *menubar;
    wxMenu *file;
    wxMenu *imp;
    wxMenuItem *quit;
    
};