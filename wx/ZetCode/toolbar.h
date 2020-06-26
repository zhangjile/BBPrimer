//simple toolbar interface

#include <wx/wx.h>

class Toolbar : public wxFrame
{
public:
    Toolbar (const wxString & tittle);
    void OnQuit (wxCommandEvent& event);
    
    wxToolBar * toolbar1;
    wxToolBar * toolbar2;
};

