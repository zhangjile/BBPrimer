#include "openfile.h"

OpenFile::OpenFile(const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(400, 320)) {
        
        wxMenuBar * menubar = new wxMenuBar;
        wxMenu* file = new wxMenu;
        file->Append(wxID_OPEN, wxT("&Open"));
        menubar->Append(file, wxT("&File"));
        SetMenuBar(menubar);
        
        Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, 
      wxCommandEventHandler(OpenFile::OnOpen));


        tc = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1), 
      wxSize(-1, -1), wxTE_MULTILINE);

        
        Centre();
        
    }
    
   void OpenFile::OnOpen(wxCommandEvent& event){
       wxFileDialog* OpenFileDialog = new wxFileDialog(this);
       if(OpenFileDialog->ShowModal() == wxID_OK) {
           wxString FileName = OpenFileDialog->GetPath();
           tc->LoadFile(FileName);
       }
       
       
   }
   
    
    