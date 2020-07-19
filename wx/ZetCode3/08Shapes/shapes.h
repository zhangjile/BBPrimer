#include <wx/wx.h>

class Shapes : public wxFrame
{
public:
    Shapes(const wxString& tittle);
    
    void OnPaint(wxPaintEvent& event);
    
    
};

