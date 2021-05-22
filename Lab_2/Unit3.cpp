//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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
#include <vector>    
#include <string>
#include <map>       

using namespace std;

const int MaxWardCapacity = 4;

struct Patient   
{
    AnsiString Name;
	AnsiString Sex;
	int Age;
	AnsiString Diagnosis;
	int Ward;
};

vector<Patient> Database;  

AnsiString FormatPatient(int i, AnsiString _name, AnsiString _sex, AnsiString _age, AnsiString _diag){
	return Database[i].Name + _name +            
			Database[i].Sex + _sex +
			IntToStr(Database[i].Age) + _age +
			Database[i].Diagnosis + _diag +
			Database[i].Ward;
}

AnsiString FormatPatient(int i, AnsiString _add){
	return FormatPatient(i, _add, _add, _add, _add);
}

bool compWard(int a, int b){       
	if(Database[a].Ward != Database[b].Ward)
		return Database[a].Ward < Database[b].Ward;
	return Database[a].Name < Database[b].Name;
}
bool compDiagnosis(int a, int b){     
	if(Database[a].Diagnosis != Database[b].Diagnosis)
		return Database[a].Diagnosis < Database[b].Diagnosis;
	if(Database[a].Ward != Database[b].Ward)   
		return Database[a].Ward < Database[b].Ward;
	return Database[a].Name < Database[b].Name;
}
bool compName(int a, int b){     
	if(Database[a].Name != Database[b].Name)
		return Database[a].Name < Database[b].Name;
	return Database[a].Ward < Database[b].Ward;
}

vector<int> ListInds; 

void ReWrite(){   
	ListInds.clear();   
	if(Form3->RadioButtonList->ItemIndex == 0)
		for(int i = 0; i < Database.size(); i++)
			if(Database[i].Ward != 0)
				ListInds.push_back(i);  
	switch(Form3->ComboBoxSearch->ItemIndex){
		case 0:
			sort(ListInds.begin(), ListInds.end(), compWard); 
			break;
		case 1:
			sort(ListInds.begin(), ListInds.end(), compDiagnosis);
			break;
		case 2:
			sort(ListInds.begin(), ListInds.end(), compName); 
			break;
	}

	Form3->ListBox->Clear();
	Form3->ListBox->TabWidth = 111;
	for(int i = 0; i < ListInds.size(); i++)
	if(Form3->EditSearch->Text.Trim().Length() == 0 ||
		Database[ListInds[i]].Name.LowerCase().Pos(Form3->EditSearch->Text.Trim().LowerCase()) != 0 ||
		Database[ListInds[i]].Diagnosis.LowerCase().Pos(Form3->EditSearch->Text.Trim().LowerCase()) != 0 ||
		IntToStr(Database[ListInds[i]].Ward).Pos(Form3->EditSearch->Text.Trim().LowerCase()) != 0)
		{
			Form3->ListBox->Items->Add(FormatPatient(ListInds[i], (AnsiString)(char)9 + " | ", " | ", " | ", (AnsiString)(char)9 + " | "));
		}
}

const char delta = '|';
const char lend = '\n';

const AnsiString SexM = "Men";
const AnsiString SexW = "Women";

Patient getPatient(){  
	Patient tmp;  

	tmp.Name = Form3->EditName->Text.Trim(); 
	if(tmp.Name.Length() == 0){    
		ShowMessage("Input Name");
		throw 0;
	}

	if(Form3->RadioGroupSex->ItemIndex == 0) 
		tmp.Sex = SexM;
	else if(Form3->RadioGroupSex->ItemIndex == 1)
		tmp.Sex = SexW;
	else {
		ShowMessage("Wrong select sex"); 
		throw 0;
	}

	try {
		tmp.Age = StrToInt(Form3->EditAge->Text);  
		if(tmp.Age <= 18)
			throw 0;
		if(tmp.Age > 110)
			throw 0;
	} catch (...) {
		ShowMessage("Wrong age");
			throw 0;
	}

	tmp.Diagnosis = Form3->EditDiag->Text.Trim(); 
	if(tmp.Diagnosis.Length() == 0){
		ShowMessage("Wrong diagnosis");
		throw 0;
	}

	try {
		tmp.Ward = StrToInt(Form3->EditWard->Text);  
	} catch (...) {
		ShowMessage("Wrong ward");
		throw 0;
	}

	return tmp;  
}

void __fastcall TForm3::ButtonSaveChangesClick(TObject *Sender)
{
		if(CheckBoxAddPatient->Checked) {   
		Patient tmp;
		bool flag = true;
		try {
			tmp = getPatient();
			try {
			Form3->RadioButtonList->ItemIndex = 0;
					map<int, int> s;  //
					for(int i = 0; i < Database.size(); i++)
						s[Database[i].Ward] += 1; 
					if(s[tmp.Ward] == MaxWardCapacity)
						throw (AnsiString)"Invalid input";
					for(int i = 0; i < Database.size(); i++)
						if(Database[i].Ward == tmp.Ward && Database[i].Sex != tmp.Sex)
							throw (AnsiString)"There can only be one sex in one ward";
				}
			 catch (AnsiString err) {
				ShowMessage(err);
				throw 0;
			}
		} catch(...) {
			flag = false;
		}
		if(flag){
			Database.push_back(tmp);   
			RadioButtonListClick(Sender);  
			CheckBoxAddPatientClick(Sender);   
		}
	} else {
		if(ListBox->ItemIndex != -1){
			int p = ListBox->ItemIndex;
			Patient tmp;
			bool flag = true;
			try {
				tmp = getPatient();
				try {
						map<int, int> s;
						for(int i = 0; i < Database.size(); i++)
							if(ListInds[p] != i)
								s[Database[i].Ward] += 1;
						if(s[tmp.Ward] == MaxWardCapacity)
							throw (AnsiString)"Invalid input";
						for(int i = 0; i < Database.size(); i++)
							if(ListInds[p] != i)
							if(Database[i].Ward == tmp.Ward && Database[i].Sex != tmp.Sex)
								throw (AnsiString)"There can only be one sex in one ward";
					}
				 catch (AnsiString err) {
					ShowMessage(err);
					throw 0;
				}
			} catch(...) {
				flag = false;
			}
			if(flag){
				Database[ListInds[p]] = tmp; 
				RadioButtonListClick(Sender);
				CheckBoxAddPatient->Checked = true;  
			}
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonDeleteClick(TObject *Sender)
{
	if(ListBox->ItemIndex != -1){      
		Database.erase(Database.begin() + ListInds[ListBox->ItemIndex]);
		
		RadioButtonListClick(Sender);
	}
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
		int i = ListInds[p];
		CheckBoxAddPatient->Checked = false;   
		EditName->Text = Database[i].Name;     
		if(Database[i].Sex == SexM)
			RadioGroupSex->ItemIndex = 0;
		else if(Database[i].Sex == SexW)
			RadioGroupSex->ItemIndex = 1;
		else
			RadioGroupSex->ItemIndex = -1;
		EditAge->Text = IntToStr(Database[i].Age);
		EditDiag->Text = Database[i].Diagnosis;
		EditWard->Text = IntToStr(Database[i].Ward);
		RadioButtonListClick(Sender);
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
			Patient tmp;
			AnsiString str = "";
			char sym = 0;

			bool flag2 = false;

			while(sym != lend){

				if(fin.eof()) {
					fin.close();
					flag2 = true;
					break;
				}

				sym = fin.get();
				str += sym;
			}

			if(flag2) break;

			int p = 2, i = 2;

			while(str[i] != delta) i++;
			tmp.Name = str.SubString(p, i - p);  
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Sex = str.SubString(p, i - p);
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Age = StrToInt(str.SubString(p, i - p));
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Diagnosis = str.SubString(p, i - p);
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Ward = StrToInt(str.SubString(p, i - p));
			i++;
			p = i;

			Database.push_back(tmp); 
		}
		ButtonFlushListClick(Sender);
		Form3->RadioButtonList->ItemIndex = 0;
		RadioButtonListClick(Sender);
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonSaveDialogClock(TObject *Sender)
{
	if (SaveDialog->Execute()) {
		ofstream fout(SaveDialog->FileName.c_str());  
		if(!fout){
			ShowMessage("File is not founded"); 
			return;
		}
		for(int i = 0; i < Database.size(); i++) {
			fout << delta << FormatPatient(i, delta) << delta << lend; 
		}
	fout.close();  
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::RadioButtonListClick(TObject *Sender)
{
	ReWrite();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonFlushListClick(TObject *Sender)
{
	EditSearch->Text = ""; 
	ReWrite();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::CheckBoxAddPatientClick(TObject *Sender)
{
	ListBox->ItemIndex = -1;
	EditName->Text = "";
	RadioGroupSex->ItemIndex = -1;
	EditAge->Text = "";
	EditDiag->Text = "";
	EditWard->Text = "";
}
//---------------------------------------------------------------------------
