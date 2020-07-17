#include "points.h"
#include <time.h>

Points::Points(const wxString& tittle)
    :wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(360,250))
    {
       Connect(wxEVT_PAINT, wxPaintEventHandler(Points::OnPaint));  //watch
        srand(time(nullptr));
        Centre();
    }
    
void Points::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);
    
    wxCoord x = 0, y = 0;
    
    wxSize size = this->GetSize();
    
    for(int i = 0; i < 100; ++i){
        x = rand () % size.x + 1;
        y = rand () % size.y + 1;
        dc.DrawPoint(x,y);
    }
    
    wxColour col1, col2;
    col1.Set(wxT("#0c0c0c"));
    col2.Set(wxT("#000000"));
    
    wxBrush brush(wxColour (255,255,255), wxBRUSHSTYLE_TRANSPARENT);
//    wxBrush brush(wxColour (255,255,255), wxTRANSPARENT);     //deprecated
    dc.SetBrush(brush);
    
    dc.SetPen(wxPen(col1, 1, wxPENSTYLE_SOLID));
//    dc.SetPen(wxPen(col1, 1, wxSOLID));
    dc.DrawRectangle(10, 15, 90,60);
    
    dc.SetPen(wxPen(col1, 1, wxPENSTYLE_DOT));
  dc.DrawRectangle(130, 15, 90, 60);

  dc.SetPen(wxPen(col1, 3, wxPENSTYLE_LONG_DASH));
  dc.DrawRectangle(250, 15, 90, 60);

  dc.SetPen(wxPen(col1, 1, wxPENSTYLE_SHORT_DASH));
  dc.DrawRectangle(10, 105, 90, 60);

  dc.SetPen(wxPen(col1, 1, wxPENSTYLE_DOT_DASH));
  dc.DrawRectangle(130, 105, 90, 60);

  dc.SetPen(wxPen(col1, 1, wxPENSTYLE_TRANSPARENT));    //no errors, no warnings!
  dc.DrawRectangle(250, 105, 90, 60);
    
    dc.DrawText(wxT("Xu Zhang Run            许章润"), 12,20);
    dc.DrawText(wxT(" bilishi"), 30,110);
    
}
