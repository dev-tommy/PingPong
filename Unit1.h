//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tfr_ConfigWindow : public TForm
{
__published:	// IDE-managed Components
  TTimer *tm_MainGame;
  TButton *bt_NewGame;
  TImage *im_GameArea;
  TPanel *pn_GameOptions;
  TButton *bt_CloseGame;
  TRadioGroup *rg_GameMode;
  TRadioGroup *rg_DifficultyLevel;
  TLabel *lb_GameName;
  void __fastcall bt_CloseGameClick(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall Tfr_ConfigWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfr_ConfigWindow *fr_ConfigWindow;
//---------------------------------------------------------------------------
#endif
 