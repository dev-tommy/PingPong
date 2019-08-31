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
  TTimer *tm_PlayerOne;
  TTimer *tm_PlayerTwo;
  TTimer *tm_Ball;
  TTimer *tm_Counter;
  TLabel *lb_CounterText;
  TLabel *lb_Counter;
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall tm_CounterTimer(TObject *Sender);
private:	// User declarations
  bool runGame;
  bool pauseGame;

  void showGameWindow();
  void gameStateReset();
  void countdownToStartGame(int numberOfseconds);
public:		// User declarations
  __fastcall Tfr_GameWindow(TComponent* Owner);

  void startGame();



};
//---------------------------------------------------------------------------
extern PACKAGE Tfr_GameWindow *fr_GameWindow;
//---------------------------------------------------------------------------
#endif
