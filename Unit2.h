//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tfr_GameWindow : public TForm
{
__published:	// IDE-managed Components
  TImage *Image1;
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
  __fastcall Tfr_GameWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfr_GameWindow *fr_GameWindow;
//---------------------------------------------------------------------------
#endif
