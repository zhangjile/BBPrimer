#include "gotoclass.h"

GotoClass::GotoClass( const wxString& title)
    : wxFrame(nullptr, -1, title, wxPoint(-1,-1), wxSize(500,200) )
    {
        wxPanel *panel = new wxPanel(this, -1);
        
        wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
        
        
        
        panel->SetSizer(vbox);
        
        Centre();
        
    }