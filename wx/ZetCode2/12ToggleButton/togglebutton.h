#include <wx/wx.h>
#include <wx/tglbtn.h>

class ToggleButton : public wxFrame
{
public:
    ToggleButton (const wxString& tittle);
    
    void OnToggleRed (wxCommandEvent& event);
    void OnToggleGreen (wxCommandEvent& event);
    void OnToggleBlue (wxCommandEvent& event);
    
protected:      //historical moment to see the protected specifier in action for the first time
    wxToggleButton* m_tgbutton1;
    wxToggleButton* m_tgbutton2;
    wxToggleButton* m_tgbutton3;
    
    wxPanel* m_panel;
    wxColour* colour;
    
};

const int ID_TGBUTTON1 = 100;
const int ID_TGBUTTON2 = 200;
const int ID_TGBUTTON3 = 300;