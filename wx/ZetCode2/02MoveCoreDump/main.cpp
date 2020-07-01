#include "main.h"
#include "move.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Move *move = new Move(wxT("Move Event") );
    move -> Show (true);
    
    return true;
    
    
}
