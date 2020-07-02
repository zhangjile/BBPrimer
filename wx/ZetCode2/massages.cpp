#include "massages.h"

Massages::Massages(const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(210, 120)) {
        wxPanel* panel = new wxPanel(this, -1);     //wxID_ANY
        
        wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
        wxGridSizer* gs = new wxGridSizer(2,2,2,2);
        
        wxButton* but1 = new wxButton(panel, ID_INFO, wxT("Info") );
        wxButton* but2 = new wxButton(panel, ID_ERROR, wxT("Error") );
        wxButton* but3 = new wxButton(panel, ID_QUESTION, wxT("Q") );
        wxButton* but4 = new wxButton(panel, ID_ALERT, wxT("Alert") );
        
        Connect(ID_INFO, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Massages::ShowMessage1));
        Connect(ID_ERROR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Massages::ShowMessage2));
        Connect(ID_QUESTION, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Massages::ShowMessage3));
        Connect(ID_ALERT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Massages::ShowMessage4));
        
        gs->Add(but1, 1, wxEXPAND);
        gs->Add(but2, 1);
        gs->Add(but3, 1);
        gs->Add(but4,1);
        
        hbox->Add(gs, 0, wxALL, 15);
        panel->SetSizer(hbox);
        
        Centre();
        
    }
    
    void Massages::ShowMessage1(wxCommandEvent& event){
        wxMessageDialog* dial = new wxMessageDialog(nullptr, wxT("Download completed"), wxT("Info"), wxOK);
        dial->ShowModal();
    }
    
    void Massages::ShowMessage2(wxCommandEvent& event) 
{
   wxMessageDialog *dial = new wxMessageDialog(NULL, 
      wxT("Error loading file"), wxT("Error"), wxOK | wxICON_ERROR);
   dial->ShowModal();
}

void Massages::ShowMessage3(wxCommandEvent& event) 
{
  wxMessageDialog *dial = new wxMessageDialog(NULL, 
      wxT("Are you sure to quit?"), wxT("Question"), 
      wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
  dial->ShowModal();
}

void Massages::ShowMessage4(wxCommandEvent& event) 
{
  wxMessageDialog *dial = new wxMessageDialog(NULL, 
      wxT("Unallowed operation"), wxT("Exclamation"), 
      wxOK | wxICON_EXCLAMATION);
  dial->ShowModal();
}
    
    