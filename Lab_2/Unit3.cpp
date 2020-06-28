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

#include <fstream>   // для записи и чтения данных из файла
#include <vector>    // хранит шаблон вектора
#include <string>
#include <map>       // подключение STL контейнера

using namespace std;

const int MaxWardCapacity = 4;

struct Patient   // структура данных
{
    AnsiString Name;
	AnsiString Sex;
	int Age;
	AnsiString Diagnosis;
	int Ward;
};

vector<Patient> Database;  // объявление вектора с типом данных структры

AnsiString FormatPatient(int i, AnsiString _name, AnsiString _sex, AnsiString _age, AnsiString _diag){
	return Database[i].Name + _name +            // инициализация данных вектора структуры Patient
			Database[i].Sex + _sex +
			IntToStr(Database[i].Age) + _age +
			Database[i].Diagnosis + _diag +
			Database[i].Ward;
}

AnsiString FormatPatient(int i, AnsiString _add){
	return FormatPatient(i, _add, _add, _add, _add);
}

bool compWard(int a, int b){       // функция сравнения по палатам
	if(Database[a].Ward != Database[b].Ward)
		return Database[a].Ward < Database[b].Ward;
	return Database[a].Name < Database[b].Name;
}
bool compDiagnosis(int a, int b){     // функция сравнения по диагнозу болезни
	if(Database[a].Diagnosis != Database[b].Diagnosis)
		return Database[a].Diagnosis < Database[b].Diagnosis;
	if(Database[a].Ward != Database[b].Ward)   // в одной палате не могут быть люди с разными болезнями
		return Database[a].Ward < Database[b].Ward;
	return Database[a].Name < Database[b].Name;
}
bool compName(int a, int b){     // функция сравнения по имени
	if(Database[a].Name != Database[b].Name)
		return Database[a].Name < Database[b].Name;
	return Database[a].Ward < Database[b].Ward;
}

vector<int> ListInds;  // объявление вектора с типом данных int списка

void ReWrite(){   // функция перезаписи списка
	ListInds.clear();   // очищение списка
	if(Form3->RadioButtonList->ItemIndex == 0)
		for(int i = 0; i < Database.size(); i++)
			if(Database[i].Ward != 0)
				ListInds.push_back(i);  // добавление элементов в конец вектора
	switch(Form3->ComboBoxSearch->ItemIndex){
		case 0:
			sort(ListInds.begin(), ListInds.end(), compWard); // сортировка по палатам
			break;
		case 1:
			sort(ListInds.begin(), ListInds.end(), compDiagnosis); // сортировка по диагнозу
			break;
		case 2:
			sort(ListInds.begin(), ListInds.end(), compName); // сортировка по имени
			break;
	}

	Form3->ListBox->Clear();
	Form3->ListBox->TabWidth = 111;
	for(int i = 0; i < ListInds.size(); i++)
	if(Form3->EditSearch->Text.Trim().Length() == 0 ||
		Database[ListInds[i]].Name.LowerCase().Pos(Form3->EditSearch->Text.Trim().LowerCase()) != 0 ||
		Database[ListInds[i]].Diagnosis.LowerCase().Pos(Form3->EditSearch->Text.Trim().LowerCase()) != 0 ||
		IntToStr(Database[ListInds[i]].Ward).Pos(Form3->EditSearch->Text.Trim().LowerCase()) != 0)
		 // проверка на введенные данные
		{
			Form3->ListBox->Items->Add(FormatPatient(ListInds[i], (AnsiString)(char)9 + " | ", " | ", " | ", (AnsiString)(char)9 + " | "));
		// если данные введены, то они записываются в список и отображаются в ListBox
		}
}

const char delta = '|';
const char lend = '\n';

const AnsiString SexM = "Men";
const AnsiString SexW = "Women";

Patient getPatient(){  // добавление данных
	Patient tmp;  // переменная структуры

	tmp.Name = Form3->EditName->Text.Trim(); // получение имени
	if(tmp.Name.Length() == 0){    // проверка на наличие данных
		ShowMessage("Input Name");
		throw 0;
	}

	if(Form3->RadioGroupSex->ItemIndex == 0) // определение пола
		tmp.Sex = SexM;
	else if(Form3->RadioGroupSex->ItemIndex == 1)
		tmp.Sex = SexW;
	else {
		ShowMessage("Wrong select sex"); // ошибка выбора пола
		throw 0;
	}

	try {
		tmp.Age = StrToInt(Form3->EditAge->Text);  // определение возраста
		if(tmp.Age <= 18)
			throw 0;
		if(tmp.Age > 110)
			throw 0;
	} catch (...) {
		ShowMessage("Wrong age");
			throw 0;
	}

	tmp.Diagnosis = Form3->EditDiag->Text.Trim(); // определение диагноза
	if(tmp.Diagnosis.Length() == 0){
		ShowMessage("Wrong diagnosis");
		throw 0;
	}

	try {
		tmp.Ward = StrToInt(Form3->EditWard->Text);  // определение палаты
	} catch (...) {
		ShowMessage("Wrong ward");
		throw 0;
	}

	return tmp;   // получение переменной со значениями структыру
}

void __fastcall TForm3::ButtonSaveChangesClick(TObject *Sender)
{
		if(CheckBoxAddPatient->Checked) {   // проверка включения флага
		Patient tmp;
		bool flag = true;
		try {
			tmp = getPatient();
			try {
			Form3->RadioButtonList->ItemIndex = 0;
					map<int, int> s;  //
					for(int i = 0; i < Database.size(); i++)
						s[Database[i].Ward] += 1; // добавление данных
					if(s[tmp.Ward] == MaxWardCapacity)
						throw (AnsiString)"Invalid input";
					for(int i = 0; i < Database.size(); i++)
						if(Database[i].Ward == tmp.Ward && Database[i].Sex != tmp.Sex)
							throw (AnsiString)"There can only be one sex in one ward";
							// проверка на разные пола в одной палате
				}
			 catch (AnsiString err) {
				ShowMessage(err);
				throw 0;
			}
		} catch(...) {
			flag = false;
		}
		if(flag){
			Database.push_back(tmp);   // добавление данных в конец структуры
			RadioButtonListClick(Sender);  // получение адреса пацинтов
			CheckBoxAddPatientClick(Sender);   // получение адреса флага
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
				Database[ListInds[p]] = tmp; // изменение данных
				RadioButtonListClick(Sender);
				CheckBoxAddPatient->Checked = true;  // включение флага
			}
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonDeleteClick(TObject *Sender)
{
	if(ListBox->ItemIndex != -1){      // проверка на наличие элементов списка
		Database.erase(Database.begin() + ListInds[ListBox->ItemIndex]);
		// перезапись списка без выбранного элемента
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
		int p = ListBox->ItemIndex;  // создание новой переменной идлекса списка
		int i = ListInds[p];
		CheckBoxAddPatient->Checked = false;   // если флаг добаления пациентов выключен
		EditName->Text = Database[i].Name;     // поля для записи инициализируются данными из списка
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
		ListBox->ItemIndex = p; // присваивание нового индекса списку
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonOpenDialogClick(TObject *Sender)
{
	if (OpenDialog->Execute()) {
		ifstream fin(OpenDialog->FileName.c_str());  // создание переменной для чтения из файла
		if(!fin){
			ShowMessage("File is not founded");  // если файл не найден, вызывается сообщение
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
			tmp.Name = str.SubString(p, i - p);  // показать имя с i-ого по i-p символ
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

			Database.push_back(tmp); // добавление данных в конец структуры

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
		ofstream fout(SaveDialog->FileName.c_str());   // создание переменной для записи в файл
		if(!fout){
			ShowMessage("File is not founded"); // если файл не открыт, вызывается сообщение
			return;
		}
		for(int i = 0; i < Database.size(); i++) {
			fout << delta << FormatPatient(i, delta) << delta << lend; // запись данных в файл
		}
	fout.close();  // закрытие файла
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
	EditSearch->Text = ""; // обнуление введенных для поиска данных
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
