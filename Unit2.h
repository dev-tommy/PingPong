//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tfr_GameWindow : public TForm
{
__published:	// IDE-managed Components
  TImage *im_Game;
  TTimer *tm_RunGame;
  TTimer *tm_Counter;
  TLabel *lb_CounterText;
  TLabel *lb_Counter;
  TShape *sh_PlayerOne;
  TShape *sh_PlayerTwo;
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall tm_CounterTimer(TObject *Sender);
  void __fastcall tm_RunGameTimer(TObject *Sender);
  void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
  void __fastcall FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
private:	// User declarations
  bool runGame;
  bool pauseGame;
  int speedPlayerOne;
  int speedPlayerTwo;
  int directionPlayerOne;
  int directionPlayerTwo;
  int speedBall;
  int directionBallX;
  int directionBallY;

  void showGameWindow();
  void gameStateReset();
  void countdownToStartGame(int numberOfseconds);
  void showGameResult();
  void resetPlayersAndBallPosition();

public:		// User declarations
  __fastcall Tfr_GameWindow(TComponent* Owner);

  void startGame();



};
//---------------------------------------------------------------------------
extern PACKAGE Tfr_GameWindow *fr_GameWindow;
//---------------------------------------------------------------------------
#endif
