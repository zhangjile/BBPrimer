// to honor a great British scientist, Hooke
#include "MainDialog.h"
#include <wx/msgdlg.h>

MainDialog::MainDialog(wxWindow* parent)
    : MainDialogBaseClass(parent)
{
}

MainDialog::~MainDialog()
{
}

void MainDialog::Hooke(wxCommandEvent& event)
{
    ::wxMessageBox(_("Hello World"));
}
