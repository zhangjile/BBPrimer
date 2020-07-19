#include "gradient.h"

Gradient::Gradient(const wxString& tittle)
    :wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(250,300))
    {
       Connect(wxEVT_PAINT, wxPaintEventHandler(Gradient::OnPaint));  
        Centre();
    }
    
void Gradient::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);
    
    wxColour col1, col2;
    
    col1.Set(wxT("#ff0000"));
    col2.Set(wxT("#000000"));
    
    dc.GradientFillLinear(wxRect(20,20,180,40), col1, col2, wxNORTH);
    dc.GradientFillLinear(wxRect(20,80,180,40), col1, col2, wxSOUTH);
    dc.GradientFillLinear(wxRect(20,140,180,40), col1, col2, wxEAST);
    dc.GradientFillLinear(wxRect(20,200,180,40), col1, col2, wxWEST);
    
    
    
}
