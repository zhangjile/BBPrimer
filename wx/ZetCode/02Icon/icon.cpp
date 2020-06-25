#include "icon.h"

icon::icon(const wxString& tittle)
    :wxFrame(NULL, wxID_ANY, tittle, wxDefaultPosition, wxSize(250,150) )
{
    SetIcon(wxIcon( wxT("vim.xpm") ));
    Centre ();
}
