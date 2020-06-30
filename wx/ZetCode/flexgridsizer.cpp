#include "flexgridsizer.h"

FlexGridSizer::FlexGridSizer( const wxString& title)
    : wxFrame(nullptr, -1, title, wxPoint(-1,-1), wxSize(370,320) )
    {
        wxPanel *panel = new wxPanel(this, -1);
        wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
        wxFlexGridSizer * fgs = new wxFlexGridSizer(3, 2, 9, 25);
        
        wxStaticText *thetittle = new wxStaticText(panel, -1, wxT("Tittle") );
        wxStaticText *author = new wxStaticText(panel, -1, wxT("Autor") );
         wxStaticText *review = new wxStaticText(panel, -1, wxT("Review") );
        
        wxTextCtrl *tc1 = new wxTextCtrl(panel, -1);
        wxTextCtrl *tc2 = new wxTextCtrl(panel, -1);
        wxTextCtrl *tc3 = new wxTextCtrl(panel, -1, wxT(""), wxPoint(-1,-1), wxSize(-1,-1), wxTE_MULTILINE);
        
        
        fgs->Add(thetittle);
        fgs->Add(tc1, 1, wxEXPAND);
        fgs->Add(author);
        fgs->Add(tc2, 1, wxEXPAND);
        fgs->Add(review, 1, wxEXPAND);
        fgs->Add(tc3, 1, wxEXPAND);
        
        fgs->AddGrowableRow(2,1);
        fgs->AddGrowableCol(1,1);
        
        hbox->Add(fgs, 1, wxALL | wxEXPAND,15);     //if padding of 15 pixels is missing, ugly!
        panel->SetSizer(hbox);
        
        Centre();
        
    }