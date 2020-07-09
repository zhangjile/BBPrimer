#include <wx/wx.h>
#include <wx/listbox.h>

class MyPanel : public wxPanel
{
public:
    MyPanel (wxPanel* parent);
    
    void OnNew (wxCommandEvent& event);
    void OnRename(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    
    wxListBox* m_lb;
    
    wxButton* m_newb;
    wxButton *m_renameb;
    wxButton *m_clearb;
    wxButton *m_deleteb;
    
};

//well, class MyPanel must be declared before class ListBox
class ListBox : public wxFrame
{
public:
    ListBox (const wxString& tittle);
    
    void OnDBClick (wxCommandEvent& event);
    wxListBox* listbox;
    MyPanel* btnPanel;
    
};

const int ID_RENAME = 1;
const int ID_LISTBOX = 5;