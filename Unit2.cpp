//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
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
void __fastcall Tfr_GameWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  fr_ConfigWindow->Visible = true;
  fr_GameWindow->Visible = false;
}
//---------------------------------------------------------------------------
