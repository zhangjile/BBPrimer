#include <wx/wx.h>

class Move : public wxFrame
{
public:
    Move(const wxString& tittle);
    void OnMove (wxMoveEvent& event);
    
    wxStaticText *st1;
    wxStaticText *st2;
    
};