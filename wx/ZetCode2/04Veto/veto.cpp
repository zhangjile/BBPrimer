#include "veto.h"

Veto::Veto(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(380, 280)) {
        Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(Veto::OnClose));
        Centre();
    }
    
    void Veto::OnClose(wxCloseEvent& event){
        wxMessageDialog* dial = new wxMessageDialog(nullptr, wxT("Are you sure to quit? "), wxT("warning!"), wxYES_NO | wxYES_DEFAULT | wxICON_EXCLAMATION);
        
        int ret = dial->ShowModal();
        dial->Destroy();
        
        if(ret == wxID_YES) {
            Destroy();
        } else {
            event.Veto();
        }
        
    }