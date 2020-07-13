#include <wx/wx.h>

class DrawOneSentence : public wxFrame
{
public:
    DrawOneSentence (const wxString& tittle);
    
    void OnPaint(wxPaintEvent& event);
    
    
};

