//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
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
  if( Application->MessageBoxA("Czy na pewno chcesz zakoñczyæ grê?","Koniec gry",
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
void __fastcall Tfr_ConfigWindow::bt_NewGameClick(TObject *Sender)
{
  int screenWidth, screenHeight, gameWindowWidth, gameWindowHeight;

  screenWidth = Screen->Width;
  screenHeight = Screen->Height;
  gameWindowWidth = fr_GameWindow->Width;
  gameWindowHeight = fr_GameWindow->Height;

  if (screenWidth < gameWindowWidth  || screenHeight < gameWindowHeight) {
    fr_GameWindow->WindowState = wsMaximized;
  }

  fr_ConfigWindow->Visible = false;
  fr_GameWindow->Visible = true;
}
//---------------------------------------------------------------------------
