//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfr_GameWindow *fr_GameWindow;
//---------------------------------------------------------------------------
__fastcall Tfr_GameWindow::Tfr_GameWindow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tfr_GameWindow::bt_CloseGameClick(TObject *Sender)
{
  if( Application->MessageBoxA("Czy na pewno chcesz zakoñczyæ grê?","Koniec gry",
  MB_YESNO | MB_ICONQUESTION) == IDYES ) {
    Application->Terminate();
  }
}
//---------------------------------------------------------------------------
void __fastcall Tfr_GameWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  fr_GameWindow->bt_CloseGameClick(Sender);
}
//---------------------------------------------------------------------------
