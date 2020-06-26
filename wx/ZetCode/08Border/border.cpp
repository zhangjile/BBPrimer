#include "border.h"

Border::Border(const wxString & tittle)
        : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(250, 200 ))
    {
        wxColor col1, col2;
        col1.Set(wxT("#d10028"));
        col2.Set(wxT("#e18a08") );
        
        wxPanel *panel = new wxPanel(this, -1);
        panel->SetBackgroundColour(col1);
        wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
        
        wxPanel * midpan = new wxPanel(panel, wxID_ANY);
        midpan->SetBackgroundColour(col2);
        
        vbox->Add(midpan, 1, wxEXPAND | wxALL, 40);
        panel->SetSizer(vbox);
        
        Centre();
        
        
    }