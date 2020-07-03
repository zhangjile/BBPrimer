#include "checkbox.h"

CheckBox::CheckBox(const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(400, 320)) {
        
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        m_cb = new wxCheckBox(panel, ID_CHECKBOX, wxT("Show/Hide TittleBar Text"), wxPoint(20,10));
        m_cb->SetValue(true);
        
        Connect(ID_CHECKBOX, wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CheckBox::OnToggle));

        Centre();
        
    }
    
   void CheckBox::OnToggle(wxCommandEvent& WXUNUSED (event)) {
       if(m_cb->GetValue()) {
           this -> SetTitle(wxT("Hide and See"));
       } else {
           this -> SetTitle(wxT("  "));
       }
   }
   
    
    