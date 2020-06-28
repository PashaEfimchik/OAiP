//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditName;
	TRadioGroup *RadioGroupSex;
	TEdit *EditAge;
	TEdit *EditDiag;
	TEdit *EditWard;
	TButton *ButtonSaveChanges;
	TButton *ButtonDelete;
	TComboBox *ComboBoxSearch;
	TEdit *EditSearch;
	TListBox *ListBox;
	TButton *ButtonOpenDialog;
	TButton *ButtonSaveDialog;
	TButton *ButtonFlushList;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TCheckBox *CheckBoxAddPatient;
	TRadioGroup *RadioButtonList;
	void __fastcall ButtonSaveChangesClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall ListBoxClick(TObject *Sender);
	void __fastcall ButtonOpenDialogClick(TObject *Sender);
	void __fastcall ButtonSaveDialogClock(TObject *Sender);
	void __fastcall RadioButtonListClick(TObject *Sender);
	void __fastcall ButtonFlushListClick(TObject *Sender);
	void __fastcall CheckBoxAddPatientClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
