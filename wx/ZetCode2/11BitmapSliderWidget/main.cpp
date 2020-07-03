#include "main.h"
#include "bitmapbutton.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    BitmapButton *bbt = new BitmapButton(wxT("Bitmap"));
    bbt->Show(true);

    return true;
}