#ifndef MAINDIALOG_H
#define MAINDIALOG_H
#include "wxcrafter.h"

class MainDialog : public MainDialogBaseClass
{
public:
    MainDialog(wxWindow* parent);
    virtual ~MainDialog();
protected:
    virtual void Hooke(wxCommandEvent& event);
};
#endif // MAINDIALOG_H
