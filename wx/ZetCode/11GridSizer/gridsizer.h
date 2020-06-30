#include <wx/wx.h>

class GridSizer : public wxFrame
{
public:
    GridSizer(const wxString& tittle);
    
    wxMenuBar *menubar;
    wxMenu *file;
    
    wxBoxSizer *sizer;
    wxGridSizer* gs;
    wxTextCtrl *display;

};