#include "ident.h"

Ident::Ident(const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(250,180)) {
        wxPanel* panel = new wxPanel(this, -1);
        wxGridSizer* grid = new wxGridSizer(3,2,2,1);   //3 rows, 2 colums, 2 row-spaces and 1 colum-spaces!
        
        grid->Add(new wxButton(panel, wxID_CANCEL), 0, wxTOP | wxLEFT, 9);
        grid->Add(new wxButton(panel, wxID_DELETE), 0, wxTOP, 9);
        grid->Add(new wxButton(panel, wxID_SAVE), 0, wxLEFT, 9);
        grid->Add(new wxButton(panel, wxID_EXIT));
        grid->Add(new wxButton(panel, wxID_STOP), 0, wxLEFT, 9);
        grid->Add(new wxButton(panel, wxID_NEW));
        
        panel->SetSizer(grid);
        Centre();
        
    }