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
	TButton *ButtonAdd;
	TListBox *ListBox;
	TListBox *ListBoxPos;
	TListBox *ListBoxNeg;
	TButton *ButtonMake;
	TButton *ButtonDel;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TButton *Button1;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonMakeClick(TObject *Sender);
	void __fastcall ButtonDelClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
