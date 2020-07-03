#include <wx/wx.h>

class CheckBox : public wxFrame
{
public:
    CheckBox (const wxString& tittle);
    
   void OnToggle (wxCommandEvent& event);
   
   wxCheckBox* m_cb;
    
};

const int ID_CHECKBOX = 100;