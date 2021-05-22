//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "List.h"
#include "Queue.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Queue<int> in;
List<int> a, b;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void Redraw()
{
	Form3->ListBox->Clear();    
	Form3->ListBoxPos->Clear();
	Form3->ListBoxNeg->Clear();

	for(auto it = in.begin(); it != in.end(); ++it)   
		Form3->ListBox->Items->Add(IntToStr(in[it]));
	for(auto it = a.begin(); it != a.end(); ++it)    
		Form3->ListBoxNeg->Items->Add(IntToStr(a[it]));
	for(auto it = b.begin(); it != b.end(); ++it)      
		Form3->ListBoxPos->Items->Add(IntToStr(b[it]));
}

bool rule (const int & x) {
	return x < 0;
}

void __fastcall TForm3::ButtonAddClick(TObject *Sender)
{
	in.push_back(((rand()%2)*(-2)+1) * (1+rand()%100));  
	Redraw();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonMakeClick(TObject *Sender)
{
	a.clear();  
	b.clear();  
	in.split(a, b, rule);   
	Redraw();  
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonDelClick(TObject *Sender)
{
	if(in.begin() != in.end()) 
		in.pop_front(); 
	Redraw();      
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
