//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Hash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

class TestHash : public Hash<int> {
	static int HashInt(const int & x) {  
		return x;
	}

public:
	TestHash(int tableSize) : Hash(tableSize, HashInt) {
	}

	void Show(TMemo* Mem) {   
		Mem->Lines->Clear(); 
		for (int i = 0; i < TSize; i++) {
			AnsiString s;
			s += IntToStr(i) + ": ";
			for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
				s += IntToStr(Table[i][it]) + " | ";
			Mem->Lines->Add(s); 
		}
	}

	void Randomize() {  
		for (int i = rand() % 13; i < 100; i++)
			insert(99 - rand() % 199);
	}

	int FindMaxInd() {  
		int maxind = -1, maxval;
		for (int i = 0; i < TSize; i++)
			for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
				if (maxind == -1 || Table[i][it] > maxval) {
					maxind = i;
					maxval = Table[i][it];
				}
		return maxind;
	}

	int FindMaxVal() {  
		int maxind = -1, maxval;
		for (int i = 0; i < TSize; i++)
			for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
				if (maxind == -1 || Table[i][it] > maxval) {
					maxind = i;
					maxval = Table[i][it];
				}
		return maxval;
	}
};
TestHash* a;

void __fastcall TForm3::ButtonRandomizeClick(TObject *Sender)
{
	a->Randomize();  
	a->Show(Memo1); 
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonClearClick(TObject *Sender)
{
	delete a; 
	try {
		int hashSize = StrToInt(EditHash->Text);  
		if (hashSize < 1) 
			throw;
		a = new TestHash(hashSize);
	}
	catch (...) {
		ShowMessage("FATAL: Wrong hash table size");
		Application->Terminate();   
	}
	a->Show(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonDeleteClick(TObject *Sender)
{
	try {
		a->deletion(StrToInt(EditNumber->Text)); 
	}
	catch (...) {
		ShowMessage("Wrong number"); 
	}
	a->Show(Memo1);  
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonFindMaxClick(TObject *Sender)
{
	if (IntToStr(a->FindMaxInd()) == -1) {
			ShowMessage("Table is clear");
	}
	else
	{
		ShowMessage("Max number is in " + IntToStr(a->FindMaxInd()) + "th array is " + IntToStr(a->FindMaxVal()));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonAddClick(TObject *Sender)
{
    try {
		a->insert(StrToInt(EditNumber->Text)); 
	}
	catch (...) {
		ShowMessage("Wrong number");
	}
	a->Show(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonFindClick(TObject *Sender)
{
	try {
		if (a->contain(StrToInt(EditNumber->Text)))   
			ShowMessage("Element " + EditNumber->Text + " exist on table");
		else
			ShowMessage("Element " + EditNumber->Text + " is absent");
	}
	catch (...) {
		ShowMessage("Wrong number");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	a = new TestHash(StrToInt(EditHash->Text)); 
	a->Show(Memo1); 
}
//---------------------------------------------------------------------------
void __fastcall TForm3::EditNumberClick(TObject *Sender)
{
	EditNumber->Clear(); 
}
//---------------------------------------------------------------------------
