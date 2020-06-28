//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelHash;
	TMemo *Memo1;
	TButton *ButtonRandomize;
	TButton *ButtonClear;
	TButton *ButtonDelete;
	TEdit *EditNumber;
	TEdit *EditHash;
	TButton *ButtonFindMix;
	TButton *ButtonAdd;
	TButton *ButtonFind;
	void __fastcall ButtonRandomizeClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonFindMaxClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonFindClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall EditNumberClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
