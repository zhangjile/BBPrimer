#include <wx/wx.h>

class Gradient : public wxFrame
{
public:
    Gradient(const wxString& tittle);
    
    void OnPaint(wxPaintEvent& event);
    
    
};

