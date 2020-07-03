#include "bitmapbutton.h"

BitmapButton::BitmapButton(const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(400, 320)) {
        
        wxImage::AddHandler(new wxPNGHandler); 
        wxPanel* panel = new wxPanel(this);
        slider = new wxSlider(panel, ID_SLIDER, 0, 0, 100, wxPoint(10,30), wxSize(140,-1));
        
        button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("gdm-foot-logo.png"), wxBITMAP_TYPE_PNG), wxPoint(180,20));
        
        
        Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(BitmapButton::OnScroll ));

        Centre();
        
    }
    
   void BitmapButton::OnScroll(wxScrollEvent& event)
{
  pos = slider->GetValue(); 

  if (pos == 0) {
      button->SetBitmapLabel(wxBitmap(wxT("gdm-foot-logo.png"), wxBITMAP_TYPE_PNG));
  } else if (pos > 0 && pos <= 30 ) {
      button->SetBitmapLabel(wxBitmap(wxT("gdm-setup.png"), wxBITMAP_TYPE_PNG));
  } else if (pos > 30 && pos < 80 ) {
      button->SetBitmapLabel(wxBitmap(wxT("gdm-xnest.png"), wxBITMAP_TYPE_PNG));
  } else {
      button->SetBitmapLabel(wxBitmap(wxT("nohost.png"), wxBITMAP_TYPE_PNG));
  }
}
   
    
    