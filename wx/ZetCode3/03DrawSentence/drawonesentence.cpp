#include "drawonesentence.h"

DrawOneSentence::DrawOneSentence(const wxString& tittle)
    :wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(300,200))
    {
       Connect(wxEVT_PAINT, wxPaintEventHandler(DrawOneSentence::OnPaint));  //watch
        this->Centre();
    }
    
void DrawOneSentence::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);
    dc.DrawText(wxT("Xu Zhang Run, 许章润"), 40,60);
    dc.DrawText(wxT(" bilishi"), 70,90);
    
}
