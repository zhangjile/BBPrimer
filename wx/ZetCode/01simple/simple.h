//simple.h

#include <wx/wx.h>

class Simple : public wxFrame
{
public:
    Simple(const wxString& title);

};


Simple::Simple(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(550, 350))
{
  Centre();
}