#include "scrwindow.h"

ScrWindow::ScrWindow(const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(300, 200)) {
        wxImage::AddHandler(new wxJPEGHandler);
        wxScrolledWindow* sw = new wxScrolledWindow(this);
        
        wxBitmap bmp(wxT("bird.jpeg"), wxBITMAP_TYPE_JPEG);
        wxStaticBitmap* sb = new wxStaticBitmap(sw, -1, bmp);       //warning, unused variable
        
        int width = bmp.GetWidth();
        int height = bmp.GetHeight();
        
        sw->SetScrollbars(10,10, width/10, height/10);
        sw->Scroll(50,10);
        
        Centre();
    }
    
    
  

