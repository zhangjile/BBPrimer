#include <wx/wx.h>

class OpenFile : public wxFrame
{
public:
    OpenFile (const wxString& tittle);
    
   void OnOpen (wxCommandEvent& event);
   wxTextCtrl* tc;
    
};
