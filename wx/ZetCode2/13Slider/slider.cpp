#include "slider.h"

Slider::Slider(const wxString& tittle)
    : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(360, 350)) {
        
        panel = new MyPanel(this);
        
        Centre();
    }
    
MyPanel::MyPanel(wxFrame* parent)
        :wxPanel(parent, wxID_ANY)
        {
            fill = 0;
            slider = new wxSlider(this, ID_SLIDER, 0,0,140, wxPoint(50,30), wxSize(-1, 140), wxSL_VERTICAL);
            Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(MyPanel::OnScroll ));
            Connect(wxEVT_PAINT, wxPaintEventHandler(MyPanel::OnPaint ));
        }
  
void MyPanel::OnScroll(wxScrollEvent& event) {
        fill = slider->GetValue();
        Refresh();
}

void MyPanel::OnPaint(wxPaintEvent& event) {
        wxPaintDC dc(this);

        wxPen pen(wxColour(212, 212, 212));
        dc.SetPen(pen);

        dc.DrawRectangle(wxRect(140, 30, 80, 140));  

        wxBrush brush1(wxColour(186,54,101)); //first time I use rgb value, wow!
        dc.SetBrush(brush1);

        dc.DrawRectangle(wxRect(140, 30, 80, fill));
}
  

    
    
