//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "List.h"
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

#include <fstream>

struct Product     
{
	AnsiString Name;
	int Count;
	int Number;
};

List<Product> Database;  
List< List<Product>::iterator > CurList;   

AnsiString FormatProduct(const Product & x, AnsiString delta){    
	return x.Name + delta + IntToStr(x.Count) + delta + IntToStr(x.Number);
}

void ReWrite(){     
	CurList.clear();
	if(Form3->ComboBoxSearch->ItemIndex > 0){
		for(auto it = Database.begin(); it != Database.end(); ++it){ 
			bool flag = false;
			try {
				switch(Form3->ComboBoxSearch->ItemIndex){
				case 1:                         
					if(Database[it].Name.LowerCase().Pos(Form3->EditSearch->Text.Trim().LowerCase()) != 0)
						flag = true;
					break;
				case 2:                
					if(Database[it].Number == StrToInt(Form3->EditSearch->Text))
						flag = true;
					break;
				case 3:
					int Summ = 0;      
					for(auto itT = Database.begin(); itT != Database.end(); ++itT)
						if(Database[it].Number == Database[itT].Number)
							Summ += Database[itT].Count;
					if(Summ >= StrToInt(Form3->EditSearch->Text))
						flag = true;
					break;
				}
			} catch(...) {
				Form3->ListBox->Clear();
				return;
			}
			if(flag)
				CurList.push_back(it); 
		}
	} else {
		for(auto it = Database.begin(); it != Database.end(); ++it){
			CurList.push_back(it);
		}
	}
	Form3->ListBox->Clear();
	for(auto it = CurList.begin(); it != CurList.end(); ++it){
		Form3->ListBox->Items->Add(FormatProduct(Database[CurList[it]], " | ")); 
	}
}

const char delta = '|';
const char lend = '\n';

void __fastcall TForm3::ButtonSaveDialogClick(TObject *Sender)
{
	if (SaveDialog->Execute()) { 
		ofstream fout(SaveDialog->FileName.c_str());
		if(!fout){           
			ShowMessage("File is not founded");
			return;
		}                      
		for(auto it = Database.begin(); it != Database.end(); ++it){
			fout << delta << FormatProduct(Database[it], delta) << delta << lend;
		}
		fout.close();
	}
}

void __fastcall TForm3::ButtonDeleteClick(TObject *Sender)
{
	if(ListBox->ItemIndex != -1){  
		auto it = CurList.begin();
		for(int i = 0; i < ListBox->ItemIndex; i++)
			++it;
		Database.erase(CurList[it]); 
        CheckBoxAddProductClick(Sender);
		ReWrite();    
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ComboBoxSearchChange(TObject *Sender)
{
    EditSearch->Text = "";
	ReWrite();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonSearchClick(TObject *Sender)
{
	ReWrite();    
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ListBoxClick(TObject *Sender)
{
    if(ListBox->ItemIndex != -1){
		int p = ListBox->ItemIndex;
		auto it = CurList.begin();
		for(int i = 0; i < p; i++)
			++it;
		CheckBoxAddProduct->Checked = false; 
		EditName->Text = Database[CurList[it]].Name;  
		EditCount->Text = IntToStr(Database[CurList[it]].Count);
		EditNumber->Text = IntToStr(Database[CurList[it]].Number);
		ReWrite();    
		ListBox->ItemIndex = p; 
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonOpenDialogClick(TObject *Sender)
{
	if (OpenDialog->Execute()) {  
		ifstream fin(OpenDialog->FileName.c_str());
		if(!fin){
			ShowMessage("File is not founded");
			return;
		}
		Database.clear(); 
		while(true) {
			Product tmp;
			AnsiString str = "";
			char sym = 0;

			bool stop = false;

			while(sym != lend){

				if(fin.eof()) {
					fin.close();
					stop = true;
					break;
				}

				sym = fin.get();
				str += sym;
			}

			if(stop) break;

			int p = 2, i = 2;

			while(str[i] != delta) i++;
			tmp.Name = str.SubString(p, i - p); 
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Count = StrToInt(str.SubString(p, i - p)); 
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Number = StrToInt(str.SubString(p, i - p));  
			i++;
			p = i;

			Database.push_back(tmp); 
		}
		ButtonFlushListClick(Sender);
	}
}

//---------------------------------------------------------------------------

Product getProduct(){    
	Product tmp;

	tmp.Name = Form3->EditName->Text.Trim(); 
	if(tmp.Name.Length() == 0){
		ShowMessage("Invalid input");
		throw 0;
	}

	try {
		tmp.Count = StrToInt(Form3->EditCount->Text); 
	} catch (...) {
		ShowMessage("Invalid input");
		throw 0;
	}

	try {
		tmp.Number = StrToInt(Form3->EditNumber->Text); 
	} catch (...) {
		ShowMessage("Invalid input");
		throw 0;
	}

	return tmp;
}


void __fastcall TForm3::ButtonFlushListClick(TObject *Sender)
{
	ComboBoxSearch->ItemIndex = -1;
    ComboBoxSearch->Text = "List clear";
	EditSearch->Text = "";
	ReWrite();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::CheckBoxAddProductClick(TObject *Sender)
{
	ListBox->ItemIndex = -1; 
	EditName->Text = "";
	EditCount->Text = "";
	EditNumber->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonSaveChangesClick(TObject *Sender)
{
    if(CheckBoxAddProduct->Checked) {
		Product tmp;        
		try {
			tmp = getProduct();
		} catch(...) {
			return;
		}
		auto itExist = Database.end();
		for(auto it = Database.begin(); it != Database.end(); ++it)
			if(Database[it].Name == tmp.Name && Database[it].Number == tmp.Number)
				itExist = it;
		if(itExist != Database.end()){
			Database[itExist].Count += tmp.Count;
		} else {
			Database.push_back(tmp);
		}
		CheckBoxAddProductClick(Sender);
		ReWrite();
	} else {
		if(ListBox->ItemIndex != -1){  
			int p = ListBox->ItemIndex;
			auto itCur = CurList.begin();
			for(int i = 0; i < p; i++)
				++itCur;
			Product tmp;
			try {
				tmp = getProduct();
			} catch(...) {
				return;
			}
			auto itExist = Database.end();
			for(auto it = Database.begin(); it != Database.end(); ++it)
				if(Database[it].Name == tmp.Name && Database[it].Number == tmp.Number)
				if(it != CurList[itCur])
					itExist = it;
			if(itExist != Database.end()){
				Database[itExist].Count += tmp.Count;
				Database.erase(CurList[itCur]);
			} else {
				Database[CurList[itCur]] = tmp;
			}               
			CheckBoxAddProduct->Checked = true;
			ReWrite();
		}
	}
}
//---------------------------------------------------------------------------
