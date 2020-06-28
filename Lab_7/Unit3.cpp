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

class TestHash : public Hash<int> { // наследование от класса Hash
	static int HashInt(const int & x) {   // поле с размером хеша
		return x;
	}

public:
	TestHash(int tableSize) : Hash(tableSize, HashInt) {
	}

	void Show(TMemo* Mem) {    // функция вывода таблицы в Memo
		Mem->Lines->Clear(); // очистка Memo
		for (int i = 0; i < TSize; i++) {
			AnsiString s;
			s += IntToStr(i) + ": ";
			for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
				s += IntToStr(Table[i][it]) + " | ";
			Mem->Lines->Add(s); // добавление в Memo
		}
	}

	void Randomize() {  // функция генерации случайных чисел для таблицы
		for (int i = rand() % 13; i < 100; i++)
			insert(99 - rand() % 199);
	}

	int FindMaxInd() {  // функция поиска индекса самого большого элемента
		int maxind = -1, maxval;
		for (int i = 0; i < TSize; i++)
			for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
				if (maxind == -1 || Table[i][it] > maxval) {
					maxind = i;
					maxval = Table[i][it];
				}
		return maxind;
	}

	int FindMaxVal() {    // функция поиска значения самого большого элемента
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
	a->Randomize();  // заполнение рандомными числами таблицы
	a->Show(Memo1);  // запись этих чисел на Memo
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonClearClick(TObject *Sender)
{
	delete a;   // удаление хеша
	try {
		int hashSize = StrToInt(EditHash->Text);   // установка размера таблицы хеша
		if (hashSize < 1)  // проверка на ввод только положительных чисел
			throw;
		a = new TestHash(hashSize);
	}
	catch (...) {
		ShowMessage("FATAL: Wrong hash table size");
		// сообщение об ошибке ввода размера таблицы хеша
		Application->Terminate();    // закрытие
	}
	a->Show(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonDeleteClick(TObject *Sender)
{
	try {
		a->deletion(StrToInt(EditNumber->Text)); // ввод числа для удаления
	}
	catch (...) {
		ShowMessage("Wrong number");  // проверка на ввод
	}
	a->Show(Memo1);  // перезапись всех элементов в Memo
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonFindMaxClick(TObject *Sender)
{
	if (IntToStr(a->FindMaxInd()) == -1) { // если таблица пуста вызывается сообщение
			ShowMessage("Table is clear");
	}
	else
	{
		ShowMessage("Max number is in " + IntToStr(a->FindMaxInd()) + "th array is " + IntToStr(a->FindMaxVal()));
		// иначе появляется сообщение с индексом самого большого числа и с его значением
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonAddClick(TObject *Sender)
{
    try {
		a->insert(StrToInt(EditNumber->Text)); // добавление в таблицу
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
		if (a->contain(StrToInt(EditNumber->Text)))   // ввод данных
			ShowMessage("Element " + EditNumber->Text + " exist on table");
			//если верно то выводится сообщения что данный номер присутствует в таблицу
		else
			ShowMessage("Element " + EditNumber->Text + " is absent");
			// иначе сообщение об отсутствии
	}
	catch (...) {
		ShowMessage("Wrong number");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	a = new TestHash(StrToInt(EditHash->Text)); // создание хеш таблицы
	a->Show(Memo1);  // показать в Мemo
}
//---------------------------------------------------------------------------
void __fastcall TForm3::EditNumberClick(TObject *Sender)
{
	EditNumber->Clear();  // очистка EditNumber
}
//---------------------------------------------------------------------------
