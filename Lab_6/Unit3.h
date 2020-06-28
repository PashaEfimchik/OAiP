//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TTreeView *TreeView1;
	TStringGrid *StringGrid1;
	TButton *ButtonAdd;
	TButton *ButtonClear;
	TButton *ButtonDelete;
	TEdit *EditKey;
	TEdit *EditValue;
	TButton *Button1;
	TEdit *EditDelKey;
	TButton *ButtonNew;
	TButton *ButtonRandom;
	TStringGrid *StringGridLevels;
	TMemo *Memo1;
	TRadioGroup *RadioGroup1;
	TButton *ButtonFind;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonMoveClick(TObject *Sender);
	void __fastcall ButtonNewClick(TObject *Sender);
	void __fastcall ButtonRandomClick(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall ButtonFindClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
