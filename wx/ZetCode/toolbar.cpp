#include "toolbar.h"

Toolbar::Toolbar( const wxString& tittle )
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(300,250) ) {
        wxImage :: AddHandler(new wxPNGHandler);
        wxBitmap exit (wxT("right-click.png"), wxBITMAP_TYPE_PNG );
        wxBitmap newb (wxT("gdm-setup.png"), wxBITMAP_TYPE_PNG );
        wxBitmap openb(wxT("gdm-xnest.png"), wxBITMAP_TYPE_PNG );
        wxBitmap saveb(wxT("language-selector.png"), wxBITMAP_TYPE_PNG);
        
        wxBoxSizer *vbox = new wxBoxSizer (wxVERTICAL);
        
        toolbar1 = new wxToolBar(this, wxID_ANY);
        toolbar1->AddTool(wxID_EXIT, wxT("Exit application"),exit );
        toolbar1->AddTool(wxID_ANY, wxT("New"), newb );
        toolbar1->AddTool(wxID_ANY, wxT("Open"), openb );
        toolbar1->AddTool(wxID_ANY, wxT("Save"), saveb );   //there's a '.' before saveb, it throws an error!
        toolbar1->Realize();
        
        vbox->Add(toolbar1, 0, wxEXPAND);
        
        SetSizer(vbox);
        
        
        Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Toolbar :: OnQuit) );
        
    }

void Toolbar :: OnQuit(wxCommandEvent& WXUNUSED( event )){
            Close(true);
}
