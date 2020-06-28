//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <string>
#include <sstream>
#include "Stack.h"

using namespace std;
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Task;
	TEdit *AEdit;
	TEdit *BEdit;
	TEdit *CEdit;
	TEdit *DEdit;
	TEdit *EEdit;
	TEdit *Result;
	TEdit *Notation;
	TButton *SolveButton;
	TButton *FillVariantButton;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TStaticText *StaticText8;
	TButton *Button1;
	TStaticText *StaticText9;
	void __fastcall SolveButtonClick(TObject *Sender);
	void __fastcall FillVariantButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
