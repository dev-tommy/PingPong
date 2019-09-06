//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfr_GameWindow *fr_GameWindow;
//---------------------------------------------------------------------------
__fastcall Tfr_GameWindow::Tfr_GameWindow(TComponent* Owner)
  : TForm(Owner)
{
  DoubleBuffered = true;
}
//---------------------------------------------------------------------------
void __fastcall Tfr_GameWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  gameStateReset();
  fr_GameWindow->Visible = false;
  runGame = true;
  pauseGame = true;
  fr_GameWindow->tm_Counter->Enabled = false;
  fr_GameWindow->tm_RunGame->Enabled = false;
  fr_GameWindow->lb_ScorePlayerOne->Caption = "0";
  fr_GameWindow->lb_ScorePlayerTwo->Caption = "0";

  fr_ConfigWindow->Visible = true;
  }
//---------------------------------------------------------------------------

void Tfr_GameWindow::showGameWindow() {
  int screenWidth, screenHeight, gameWindowWidth, gameWindowHeight;

  screenWidth = Screen->Width;
  screenHeight = Screen->Height;
  gameWindowWidth = fr_GameWindow->Width;
  gameWindowHeight = fr_GameWindow->Height;

  // If the screen resolution is smaller than the size of the game window
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
     Application->ProcessMessages();   // check the interaction with the window
     Sleep(500);
  }

  tm_RunGame->Interval = 1000/refreshRate;
  if (!pauseGame) tm_RunGame->Enabled = true;

  sh_PlayerOne->Visible = true;
  sh_PlayerTwo->Visible = true;
  sh_Ball->Visible = true;
  lb_ScorePlayerOne->Visible = true;
  lb_ScorePlayerTwo->Visible = true;

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

void Tfr_GameWindow::stopGame(int playerNumber) {
  //add score
  if (playerNumber == 1) {
    lb_ScorePlayerOne->Caption = IntToStr(StrToInt(lb_ScorePlayerOne->Caption)+1);
  }
  if (playerNumber == 2) {
    lb_ScorePlayerTwo->Caption = IntToStr(StrToInt(lb_ScorePlayerTwo->Caption)+1);
  }
  startGame();

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
  // Top and bottom margin
  int marginPlayer = 10;
  int marginBall = 10;

  // move player One
  sh_PlayerOne->Top += directionPlayerOne*speedPlayerOne;

  // move player Two by CPU
  if (fr_ConfigWindow->rg_DifficultyLevel->Enabled) {
    if ((sh_Ball->Top + sh_Ball->Height) <= (sh_PlayerTwo->Top + sh_PlayerTwo->Height/2)) {
      directionPlayerTwo = -1;
    }
    else if ((sh_Ball->Top) >= (sh_PlayerTwo->Top + sh_PlayerTwo->Height)) {
      directionPlayerTwo = 1;
    }
    else {
      directionPlayerTwo = 0;
    }
      speedPlayerTwo = 10 + fr_ConfigWindow->rg_DifficultyLevel->ItemIndex * 10;
  }

  // move player Two
  sh_PlayerTwo->Top += directionPlayerTwo*speedPlayerTwo;

  // check player's movement area

  if (sh_PlayerOne->Top < marginPlayer) sh_PlayerOne->Top = marginPlayer;
  if (sh_PlayerOne->Top > maxShiftDownPlayerOne - marginPlayer) sh_PlayerOne->Top = maxShiftDownPlayerOne - marginPlayer;

  if (sh_PlayerTwo->Top < marginPlayer) sh_PlayerTwo->Top = marginPlayer;
  if (sh_PlayerTwo->Top > maxShiftDownPlayerTwo - marginPlayer) sh_PlayerTwo->Top = maxShiftDownPlayerTwo - marginPlayer;

  // move ball
  sh_Ball->Left += speedBall* directionBallX;
  sh_Ball->Top += speedBall*directionBallY;

  // check the ball collision with the player one
  if ( sh_Ball->Left <= sh_PlayerOne->Left + sh_PlayerOne->Width) {
    if ((sh_Ball->Top+sh_Ball->Height >= sh_PlayerOne->Top) && (sh_Ball->Top <= sh_PlayerOne->Top + sh_PlayerOne->Height)) {
      directionBallX *= -1;
      speedBall += 1;
    }
  }
  // check the ball collision with the player two
  if ( sh_Ball->Left + sh_Ball->Width >= sh_PlayerTwo->Left) {
    if ((sh_Ball->Top+sh_Ball->Height >= sh_PlayerTwo->Top) && (sh_Ball->Top <= sh_PlayerTwo->Top + sh_PlayerTwo->Height)) {
      directionBallX *= -1;
      speedBall += 1;
    }
  }

  // if the ball falls out of the game add score
  if (sh_Ball->Left <= -sh_Ball->Width) stopGame(2);  //inc score player two
  if (sh_Ball->Left >=  im_Game->Width) stopGame(1);  //inc score player one

  // check the collision of the ball with the upper and lower edges of the table
  if (sh_Ball->Top < marginBall) directionBallY *= -1;
  if (sh_Ball->Top > (im_Game->Height-sh_Ball->Height - marginBall)) directionBallY *= -1;

}
//---------------------------------------------------------------------------


void __fastcall Tfr_GameWindow::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == 'A') directionPlayerOne = -1;
  if (Key == 'Z') directionPlayerOne = 1;

  if (!fr_ConfigWindow->rg_DifficultyLevel->Enabled) {
    if (Key == 'J') directionPlayerTwo = -1;
    if (Key == 'M') directionPlayerTwo = 1;
  }

}
//---------------------------------------------------------------------------

void __fastcall Tfr_GameWindow::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == 'A') directionPlayerOne = 0;
  if (Key == 'Z') directionPlayerOne = 0;
  if (!fr_ConfigWindow->rg_DifficultyLevel->Enabled) {
    if (Key == 'J') directionPlayerTwo = 0;
    if (Key == 'M') directionPlayerTwo = 0;
  }  
}
//---------------------------------------------------------------------------

