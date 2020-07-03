#include <wx/wx.h>

class BitmapButton : public wxFrame
{
public:
    BitmapButton (const wxString& tittle);
    
    wxSlider* slider;
    wxBitmapButton* button;
    int pos;
    
   void OnScroll (wxScrollEvent& event);
   
    
};

const int ID_SLIDER = 100;