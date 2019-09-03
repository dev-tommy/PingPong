//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfr_GameWindow *fr_GameWindow;
Player *gracz;
//---------------------------------------------------------------------------
__fastcall Tfr_GameWindow::Tfr_GameWindow(TComponent* Owner)
  : TForm(Owner)
{
  gracz = new Player(50);
  DoubleBuffered = true;
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
  int countdownTime = 3; // seconds
  
  gameStateReset();
  showGameWindow();
  countdownToStartGame(countdownTime);
  while(!runGame){
     Application->ProcessMessages();
     Sleep(500);
  }

  tm_RunGame->Interval = 1000/refreshRate;
  tm_RunGame->Enabled = true;

  sh_PlayerOne->Visible = true;
  sh_PlayerTwo->Visible = true;
  sh_Ball->Visible = true;

}

void Tfr_GameWindow::gameStateReset() {
  runGame = false;
  pauseGame = false;
  tm_RunGame->Enabled = false;
  tm_Counter->Enabled = false;
  sh_PlayerOne->Visible = false;
  sh_PlayerTwo->Visible = false;
  sh_Ball->Visible = false;
  lb_Counter->Visible = false;
  lb_CounterText->Visible = false;

  speedPlayerOne = 40;
  speedPlayerTwo = 40;
  directionPlayerOne = 0;
  directionPlayerTwo = 0;
  speedBall = 10;
  directionBallX = 1;
  directionBallY = 1;

  resetPlayersAndBallPosition();
}

void Tfr_GameWindow::resetPlayersAndBallPosition() {
  int leftMargin = 25;
  int rightMargin = 25;

  sh_PlayerOne->Left = leftMargin;
  sh_PlayerOne->Top = im_Game->Height/2 - sh_PlayerOne->Height/2;

  sh_PlayerTwo->Left = im_Game->Width - sh_PlayerTwo->Width - rightMargin;
  sh_PlayerTwo->Top = im_Game->Height/2 - sh_PlayerTwo->Height/2;

  sh_Ball->Left = (im_Game->Width - sh_Ball->Width)/2;
  sh_Ball->Top = (im_Game->Height - sh_Ball->Height)/2;
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
    runGame = true;
  } else {
    lb_Counter->Caption = IntToStr(timeLeft);
  }
}


//---------------------------------------------------------------------------



void __fastcall Tfr_GameWindow::tm_RunGameTimer(TObject *Sender)
{
  int maxShiftDownPlayerOne = im_Game->Height - sh_PlayerOne->Height;
  int maxShiftDownPlayerTwo = im_Game->Height - sh_PlayerTwo->Height;
  int marginPlayer = 10;
  int marginBall = 10;
  sh_PlayerOne->Top += directionPlayerOne*speedPlayerOne;
  sh_PlayerTwo->Top += directionPlayerTwo*speedPlayerTwo;

  if (sh_PlayerOne->Top < marginPlayer) sh_PlayerOne->Top = marginPlayer;
  if (sh_PlayerOne->Top > maxShiftDownPlayerOne - marginPlayer) sh_PlayerOne->Top = maxShiftDownPlayerOne - marginPlayer;

  if (sh_PlayerTwo->Top < marginPlayer) sh_PlayerTwo->Top = marginPlayer;
  if (sh_PlayerTwo->Top > maxShiftDownPlayerTwo - marginPlayer) sh_PlayerTwo->Top = maxShiftDownPlayerTwo - marginPlayer;

  sh_Ball->Left += speedBall*directionBallX;
  sh_Ball->Top += speedBall*directionBallY;

  if (sh_Ball->Left < marginBall) directionBallX *= -1;
  if (sh_Ball->Left > (im_Game->Width-sh_Ball->Width - marginBall)) directionBallX *= -1;

  if (sh_Ball->Top < marginBall) directionBallY *= -1;
  if (sh_Ball->Top > (im_Game->Height-sh_Ball->Height - marginBall)) directionBallY *= -1;

}
//---------------------------------------------------------------------------


void __fastcall Tfr_GameWindow::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == 'A') directionPlayerOne = -1;
  if (Key == 'Z') directionPlayerOne = 1;

  if (Key == 'J') directionPlayerTwo = -1;
  if (Key == 'M') directionPlayerTwo = 1;

  //if (Key == 'Z') gracz.move(1);

}
//---------------------------------------------------------------------------

void __fastcall Tfr_GameWindow::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == 'A') directionPlayerOne = 0;
  if (Key == 'Z') directionPlayerOne = 0;

  if (Key == 'J') directionPlayerTwo = 0;
  if (Key == 'M') directionPlayerTwo = 0;
}
//---------------------------------------------------------------------------

