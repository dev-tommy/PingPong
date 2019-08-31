//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfr_ConfigWindow *fr_ConfigWindow;
//---------------------------------------------------------------------------
__fastcall Tfr_ConfigWindow::Tfr_ConfigWindow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tfr_ConfigWindow::bt_CloseGameClick(TObject *Sender)
{
  if( Application->MessageBoxA("Czy na pewno chcesz zako�czy� gr�?","Koniec gry",
  MB_YESNO | MB_ICONQUESTION) == IDYES ) {
    Application->Terminate();
  }
}
//---------------------------------------------------------------------------
void __fastcall Tfr_ConfigWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  fr_ConfigWindow->bt_CloseGameClick(Sender);
}
//---------------------------------------------------------------------------
