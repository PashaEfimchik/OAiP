//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Tree.h"
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

class TestTree : public Tree<int, AnsiString> {
	AnsiString Format(Top* vrt) {
		return "[" + IntToStr(vrt->key) + "] " + vrt->value;
	}
					
	void Redraw(TTreeView* TV, TTreeNode* prev, Top* vrt) {
		if (!vrt)
			return;
		if (vrt->right)
			Redraw(TV, TV->Items->AddChild(prev, Format(vrt->right)), vrt->right);
		if (vrt->left)
			Redraw(TV, TV->Items->AddChild(prev, Format(vrt->left)), vrt->left);
	}
				
	void dfs(Top* vrt, int lvl, int* levels) {
		if (!vrt)
			return;
		if (!vrt->left && !vrt->right)
			levels[lvl]++;
		dfs(vrt->left, lvl + 1, levels);
		dfs(vrt->right, lvl + 1, levels);
	}
	
	void NLR(Top* vrt, TMemo* M) {
		if (!vrt)
			return;
		M->Lines->Add("[" + IntToStr(vrt->key) + "] " + vrt->value);
		NLR(vrt->left, M);
		NLR(vrt->right, M);
	}
						
	void LRN(Top* vrt, TMemo* M) {
		if (!vrt)
			return;
		LRN(vrt->left, M);
		LRN(vrt->right, M);
		M->Lines->Add("[" + IntToStr(vrt->key) + "] " + vrt->value);
	}
						
	void LNR(Top* vrt, TMemo* M) {
		if (!vrt)
			return;
		LNR(vrt->left, M);
		M->Lines->Add("[" + IntToStr(vrt->key) + "] " + vrt->value);
		LNR(vrt->right, M);
	}

public:
	void redraw(TTreeView* TV) { 
		TV->Items->Clear();
		if (root)
			Redraw(TV, TV->Items->Add(nullptr, Format(root)), root);
		TV->FullExpand();
	}

	void levels(TStringGrid* SG) {  
		SG->ColCount = 1;
		int lvls[42];
		for (int i = 0; i < 10; i++)
			lvls[i] = 0;
		dfs(root, 1, lvls);
		for (int i = 1; i < 10; i++) {
			SG->ColCount++;
			SG->Cells[i][0] = IntToStr(i);
			SG->Cells[i][1] = IntToStr(lvls[i]);
		}
	}
					  
	void straight(TMemo* M) {
		NLR(root, M);
	}
						
	void back(TMemo* M) {
		LRN(root, M);
	}
						
	void ascending(TMemo* M) {
		LNR(root, M);
	}
};

TestTree a;

void Redraw(TObject *Sender) {  
	a.redraw(Form3->TreeView1);
	a.levels(Form3->StringGridLevels);
	Form3->RadioGroup1Click(Sender);
}

void __fastcall TForm3::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "Key";
	StringGrid1->Cells[1][0] = "Info";
	StringGrid1->Cells[0][1] = "0";
	StringGrid1->Cells[1][1] = "Hello, world!";

	StringGridLevels->ColWidths[0] = 75;
	StringGridLevels->Cells[0][0] = "Level";
	StringGridLevels->Cells[0][1] = "Leafs";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonAddClick(TObject *Sender)
{
	int key;
	try {
		key = StrToInt(EditKey->Text.Trim()); 
	}
	catch (...) {
		ShowMessage("Wrong  number");
		return;
	}
	if (a.find(key) != a.end()) {      
		ShowMessage("Key already exists");
		return;
	}
	AnsiString value = EditValue->Text; 
	if (value.IsEmpty()) {
		ShowMessage("Empty info");
		return;
	}
	a[key] = value;
	Redraw(Sender);
	StringGrid1->RowCount++; 
	StringGrid1->Cells[0][StringGrid1->RowCount - 1] = IntToStr(key);
	StringGrid1->Cells[1][StringGrid1->RowCount - 1] = value;
	EditKey->Text = "";
	EditValue->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonClearClick(TObject *Sender)
{
	a.clear();     
	Redraw(Sender);
	StringGrid1->RowCount = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonDeleteClick(TObject *Sender)
{
	int key;
	try {             
		key = StrToInt(EditDelKey->Text.Trim());
	}
	catch (...) {
		ShowMessage("Wrong key number");
		return;
	}
	if (a.find(key) == a.end()) {
		ShowMessage("There is no such key");
		return;
	}
	a.erase(key); 
	Redraw(Sender);  
	int p;
	for (p = 1; p < StringGrid1->RowCount; p++)
		if (StrToInt(StringGrid1->Cells[0][p]) == key)
			break;
	for (int i = p + 1; i < StringGrid1->RowCount; i++)
		StringGrid1->Rows[i - 1] = StringGrid1->Rows[i];
	if (p < StringGrid1->RowCount)      
		StringGrid1->RowCount--;
	EditDelKey->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonMoveClick(TObject *Sender)
{
	a.clear();          
	for (int i = StringGrid1->RowCount - 1; i > 0; i--) {
		StringGrid1->Cells[0][i] = StringGrid1->Cells[0][i].Trim();
		int passnum;
		try {
			passnum = StrToInt(StringGrid1->Cells[0][i]);
		}
		catch (...) {
			ShowMessage("Wrong key number '" + StringGrid1->Cells[0][i] + "'");
			Redraw(Sender);
			return;
		}
		if (a.find(passnum) != a.end()) {
			ShowMessage("Key " + IntToStr(passnum) + " already exists");
			Redraw(Sender);
			return;
		}
		if (StringGrid1->Cells[1][i].IsEmpty()) {
			ShowMessage("Empty info [" + IntToStr(passnum) + "]");
			Redraw(Sender);
			return;
		}
		a[passnum] = StringGrid1->Cells[1][i];
	}
	Redraw(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonNewClick(TObject *Sender)
{
	StringGrid1->RowCount++;  
	StringGrid1->Cells[0][StringGrid1->RowCount - 1] = "Enter pass num";
	StringGrid1->Cells[1][StringGrid1->RowCount - 1] = "Enter info";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonRandomClick(TObject *Sender)
{
	StringGrid1->RowCount++; 
	StringGrid1->Cells[0][StringGrid1->RowCount - 1] = IntToStr(rand());
	StringGrid1->Cells[1][StringGrid1->RowCount - 1] = "";
	for (int i = rand() % 10; i < 13; i++)
		StringGrid1->Cells[1][StringGrid1->RowCount - 1] += (char)('A' + rand() % 26);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::RadioGroup1Click(TObject *Sender)
{
	Memo1->Lines->Clear();      
	switch (RadioGroup1->ItemIndex) {
	case 0:
		a.straight(Memo1); 
		break;
	case 1:
		a.back(Memo1);  
		break;
	case 2:
		a.ascending(Memo1); 
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonFindClick(TObject *Sender)
{
    int key;
	try {
		key = StrToInt(EditDelKey->Text.Trim()); 
	}
	catch (...) {
		ShowMessage("Wrong number");
		return;
	}
	if (a.find(key) == a.end()) { 
		ShowMessage("There is no such key");
		return;
	}
	ShowMessage("[" + IntToStr(key) + "] => " + a[key]);
}
//---------------------------------------------------------------------------
