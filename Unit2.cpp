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
  gameStateReset();
}
//---------------------------------------------------------------------------
void __fastcall Tfr_GameWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  fr_ConfigWindow->Visible = true;
  fr_GameWindow->Visible = false;
}
//---------------------------------------------------------------------------

void Tfr_GameWindow::showGameWindow() {
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

void Tfr_GameWindow::startGame() {
  int refreshRate = 50; // Hz
  showGameWindow();
  countdownToStartGame(5);
  runGame = true;
  tm_RunGame->Interval = 1000/refreshRate;
  tm_RunGame->Enabled = true;
}

void Tfr_GameWindow::gameStateReset() {
  runGame = false;
  pauseGame = false;
}

void Tfr_GameWindow::countdownToStartGame(int numberOfseconds) {
  lb_CounterText->Visible = true;
  lb_Counter->Caption = IntToStr(numberOfseconds);
  lb_Counter->Visible = true;
  tm_Counter->Enabled = true;
}

void Tfr_GameWindow::showGameResult() {

}

void __fastcall Tfr_GameWindow::tm_CounterTimer(TObject *Sender)
{
  int timeLeft = StrToInt(lb_Counter->Caption);
  timeLeft--;
  if (timeLeft <0) {
    tm_Counter->Enabled = false;
    lb_CounterText->Visible = false;
    lb_Counter->Visible = false;
  } else {
    lb_Counter->Caption = IntToStr(timeLeft);
  }
}


//---------------------------------------------------------------------------


