#include <wx/wx.h>

class Pen : public wxFrame
{
public:
    Pen (const wxString& tittle);
    
    void OnPaint(wxPaintEvent& event);
    
    
};

