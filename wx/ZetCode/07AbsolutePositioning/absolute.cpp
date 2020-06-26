#include "absolute.h"

//make 4 changes 
/*The wxTextCtrl object is placed inside the wxFrame widget. The wxFrame widget has a special built-in sizer. We can put only one widget inside the wxFrame container. The child widget occupies all the space, which is not given to the borders, menu, toolbar, and the statusbar. */
Absolute::Absolute (const  wxString& tittle )
    : wxFrame(nullptr, -1, tittle, wxDefaultPosition, wxSize(350, 250) ) {
 // : wxFrame(nullptr, -1, tittle, wxPoint(-1,-1), wxSize(350, 250) ) {
        wxPanel *panel = new wxPanel (this, -1);	//take it out
        
        menubar =  new wxMenuBar;
        file = new wxMenu;
        edit = new wxMenu;
        help = new wxMenu;
        
        menubar->Append(file, wxT("&File"));
        menubar->Append( edit, wxT("&Edit"));
        menubar->Append(help, wxT("&Help") );
        SetMenuBar(menubar);
        
        textctrl = new wxTextCtrl(panel, -1, wxT(""), wxDefaultPosition, wxSize(250,150), wxTE_MULTILINE );
	//textctrl = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1,-1), wxSize(250,150), wxTE_MULTILINE );
        Centre (); // the subtle effect of this line is to be discovered
    }
