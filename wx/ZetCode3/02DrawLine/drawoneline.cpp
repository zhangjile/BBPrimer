#include "drawoneline.h"

DrawOneLine::DrawOneLine(const wxString& tittle)
    :wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(500,400))
    {
       Connect(wxEVT_PAINT, wxPaintEventHandler(DrawOneLine::OnPaint));  //watch
        this->Centre();
    }
    
void DrawOneLine::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);
    
    wxCoord x1 = 50, y1 = 60;
    wxCoord x2 = 390, y2 = 60;
    
    dc.DrawLine(x1,y1,x2,y2);
    
    x1 = 50, y1 = 260;
    x2 = 390, y2 = 260;
    
    dc.DrawLine(x1,y1,x2,y2);
    
}
