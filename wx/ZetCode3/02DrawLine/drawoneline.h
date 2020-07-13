#include <wx/wx.h>

class DrawOneLine : public wxFrame
{
public:
    DrawOneLine (const wxString& tittle);
    
    void OnPaint(wxPaintEvent& event);
    
    
};

