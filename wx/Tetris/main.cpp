#include "main.h"
#include "tetris.h"

// Define the MainApp, the outermost shell of our app
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
                srand(time(nullptr));
                Tetris* tetris = new Tetris(wxT("Tetris"));
                tetris->Centre();
                tetris->Show(true);
                
                return true;
            
}


