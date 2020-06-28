//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditName;
	TEdit *EditCount;
	TLabel *Label3;
	TEdit *EditNumber;
	TButton *ButtonSaveChanges;
	TButton *ButtonDelete;
	TComboBox *ComboBoxSearch;
	TEdit *EditSearch;
	TListBox *ListBox;
	TButton *ButtonOpenDialog;
	TButton *ButtonSaveDialog;
	TButton *ButtonFlushList;
	TCheckBox *CheckBoxAddProduct;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ComboBoxSearchChange(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall ListBoxClick(TObject *Sender);
	void __fastcall ButtonOpenDialogClick(TObject *Sender);
	void __fastcall ButtonSaveDialogClick(TObject *Sender);
	void __fastcall ButtonFlushListClick(TObject *Sender);
	void __fastcall CheckBoxAddProductClick(TObject *Sender);
	void __fastcall ButtonSaveChangesClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
