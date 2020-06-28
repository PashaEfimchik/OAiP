//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
float a, b, c, d, e;

bool IsVar(char ch) // функция проверки на ввод только a, b, c, d, e
{
	if (96 < ch && ch < 102)
	{
		return true;
	}
	return false;
}

int IsOper(char ch)  // переопределение знаков в числа
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	if (ch == '*' || ch == '/')
	{
		return 2;
	}
	if (ch == '(')
	{
		return 3;
	}
	if( ch == ')')
	{
		return 4;
	}
    if( ch == ']')
	{
		return 5;
	}
	return 0;
}

float GetValue(char ch)  // функция получение значений
{
	switch(ch)
	{
		case 'a':
		{
			return a;
			break;
		}
		case 'b':
		{
			return b;
			break;
		}
		case 'c':
		{
			return c;
			break;
		}
		case 'd':
		{
			return d;
			break;
		}
		case 'e':
		{
			return e;
			break;
		}
		default:
		{
			throw 8;
		}
	}
}

float Calc(float a, float b, char ch) // функция операций между a и b
{
switch(ch)
	{
		case '+':
		{
			return a + b;
			break;
		}
		case '-':
		{
			return a - b;
			break;
		}
		case '*':
		{
			return a * b;
			break;
		}
		case '/':
		{
			if (b != 0)  // проверка на нулевое значение знаменателя
			{
				return a / b;
			}
			throw 0;
			break;
		}
		default:
		{
			throw 8;
		}
	}
}

float Calculate(string inp)
{
	Stack vars;
	Stack ops;
	float result = 0;
	char A, B;
	float a, b;

	for (int i = 0; i < inp.length(); i++)
	{
		if(IsVar(inp[i]))
		{
			vars.Push((float)GetValue(inp[i])); // вставка элемента в вершину Stack
		}
		else
		{
			b = vars.Back()->floatValue;  // присваивание данных из последовательности для поддержания pop и push
			vars.Pop();
			a = vars.Back()->floatValue;
			vars.Pop(); // удаление элемента с вершины Stack
			vars.Push(Calc(a, b, inp[i]));
		}
	}
	return vars.Back()->floatValue;
}

AnsiString Convert(string inp)
{
	Stack ops;         // переменная стек
	AnsiString str;
	int brackets = 0;  // переменная количества скобок

	inp += ']';

	for (int i = 0; i < inp.length(); i++)
	{
		if(IsVar(inp[i]))   // проверка на запись a, b, c, d, e
		{
			str += inp[i];
		}
		else
		{
			switch(IsOper(inp[i]))
			{
				case 1:
				{
					if(!ops.Empty() && ops.Back()->Value != '(')  // перенос '(' в стек
					{
						str += ops.Back()->Value; // присваивание pyfxtybq
						ops.Pop();
					}
					ops.Push(inp[i]); // добавление значений в стек
					break;
				}
				case 2:
				{
					if(!ops.Empty() && ops.Back()->Value != '(')
					{
						if(IsOper(ops.Back()->Value) == 2) // если происходи умножение или деление
						{
							str += ops.Back()->Value;
							ops.Pop(); // удаление из стек
						}
					}
					ops.Push(inp[i]);     // добавление в стек
					break;
				}
				case 3:
				{
					ops.Push(inp[i]);  // добавление в стек
					brackets++;     // закрытие скобок
					break;
				}
				case 4:
				{
					if(!ops.Empty() && brackets != 0)  // проверка на наличие скобок и значений
					{
						while(ops.Back()->Value != '(' && !ops.Empty()) // считает все если нет скобок
						{
							str += ops.Back()->Value;
							ops.Pop();
						}
						ops.Pop();  // удаление из стек
					}
					else
					{
						ShowMessage("Balance of brackets is not respected");
						// баланс скобок не соблюден
						throw 8;  // вызов исключения
					}
					break;
				}
				case 5:
				{
					while(!ops.Empty())   // очистка стек
					{
						str += ops.Back()->Value;
						ops.Pop();
					}
					break;
				}
				default:
				{
					ShowMessage("No such variable or operator available");
					// нет такой переменной или оператора
					throw 8;
					break;
				}
			}
		}
	}
	delete ops.Tail;
	return str;
}

__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner)
{

Task->Clear();    // обнуление данных Edit
AEdit->Clear();
BEdit->Clear();
CEdit->Clear();
DEdit->Clear();
EEdit->Clear();
}

//---------------------------------------------------------------------------
void __fastcall TForm3::SolveButtonClick(TObject *Sender)
{

wstringstream s; // потоковый класс для работы со строками с большим значением

	a = (float)AEdit->Text.ToDouble();  // присваивание значений переменным
	b = (float)BEdit->Text.ToDouble();
	c = (float)CEdit->Text.ToDouble();
	d = (float)DEdit->Text.ToDouble();
	e = (float)EEdit->Text.ToDouble();
	Notation->Text = Convert(((AnsiString)Task->Text).c_str()); // конвертирование обозначений
	Result->Text = Calculate(((AnsiString)Notation->Text).c_str()); // получение результата

}
//---------------------------------------------------------------------------
void __fastcall TForm3::FillVariantButtonClick(TObject *Sender)
{
									// авто заполнение своего (8) варианта
AEdit->Text = "8,5";
	BEdit->Text = "0,3";
	CEdit->Text = "2,4";
	DEdit->Text = "7,9";
	EEdit->Text = "1,6";
	Task->Text = "a/(b*(c+d))-e";
	ShowMessage("Answer should be 1,151");
	SolveButtonClick(Sender);

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
Close();        // закрытие формы
}
//---------------------------------------------------------------------------
