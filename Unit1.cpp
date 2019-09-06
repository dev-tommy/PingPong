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
void __fastcall Tfr_ConfigWindow::bt_NewGameClick(TObject *Sender)
{
  fr_GameWindow->startGame();
}
//---------------------------------------------------------------------------



void __fastcall Tfr_ConfigWindow::rg_GameModeClick(TObject *Sender)
{
  if (rg_GameMode->ItemIndex == 1) {
    rg_DifficultyLevel->Enabled = true;
  } else {
    rg_DifficultyLevel->Enabled = false;
  }
}
//---------------------------------------------------------------------------


void __fastcall Tfr_ConfigWindow::FormCreate(TObject *Sender)
{
    Application->MessageBox("Witaj w grze PingPong!\n\n"
                          "Sterowanie paletkami:\n"
                          "Lewy gracz: A - w g�r�, Z - w d�\n"
                          "Prawy gracz: J - w g�r�, M - w d�\n\n"
                          "Udanej zabawy :) !",

                          "PingPong", MB_OK);
}
//---------------------------------------------------------------------------

