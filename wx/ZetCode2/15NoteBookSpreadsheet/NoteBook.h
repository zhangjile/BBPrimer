#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/grid.h>

class NoteBook : public wxFrame
{
public:
    NoteBook (const wxString& tittle);
    
    void OnQuit (wxCommandEvent& event);
    
};


class MyGrid : public wxGrid
{
public:
    MyGrid (wxNotebook* parent);
    
};

