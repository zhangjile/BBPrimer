#include "button.h"

MyButton::MyButton (const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(370, 220) )
    {
        wxPanel *panel = new wxPanel (this, wxID_ANY);  // if 'new' was missing, LOL
        wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(20,20)  );
        Centre ();
    }
    
    void MyButton::OnQuit(wxCommandEvent& WXUNUSED(event)) {
        Close (true);
    }
    
    BEGIN_EVENT_TABLE(MyButton, wxFrame)
            EVT_BUTTON(wxID_EXIT, MyButton::OnQuit)
    END_EVENT_TABLE ()
    