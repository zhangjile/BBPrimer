#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class Button : public wxFrame
{
public:
    Button(const wxString& title);
    void OnQuit(wxCommandEvent &event );

};


Button::Button(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(550, 350))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    
    wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Exit"), wxPoint(20,20) );
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler (Button::OnQuit) );
    button->SetFocus();
    Centre();
}

void Button::OnQuit (wxCommandEvent &WXUNUSED(event) ){
    Close(true);
}