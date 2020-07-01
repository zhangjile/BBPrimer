//not successful yet

#include "move.h"

Move::Move (const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(250, 130) )
    {
        wxPanel *panel = new wxPanel (this, -1);    //what does -1 stand for?
        
        st1 = new wxStaticText(panel, -1, wxT(""), wxPoint(10,10) );
        st1 = new wxStaticText(panel, -1, wxT(""), wxPoint(10,30) );
        
        Connect(wxEVT_MOVE, wxMoveEventHandler(Move::OnMove) );

        Centre ();
    }
    
    void Move::OnMove( wxMoveEvent& event) {
        wxPoint size = event.GetPosition();
        st1->SetLabel(wxString::Format (wxT("x:  %d"),  size.x  ) );
        st2->SetLabel(wxString::Format (wxT("y:  %d"),  size.y  ) );
       
    }
    
    
    
