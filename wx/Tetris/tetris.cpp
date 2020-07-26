#include "tetris.h"
#include "board.h"

Tetris::Tetris(const wxString& tittle)
            : wxFrame(nullptr, wxID_ANY, tittle, wxDefaultPosition, wxSize(280,480))
            {
                    wxStatusBar* sb = CreateStatusBar ();
                    sb->SetStatusText(wxT("0"));
                    Board* board = new Board(this);
                    board->SetFocus();
                    board->Start();
            }
