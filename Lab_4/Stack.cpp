//---------------------------------------------------------------------------

#pragma hdrstop

#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Stack::Push(char ch)  // функция добавления переменных в вверх стека
{
	Item* item = new Item(ch);
	if(this->Empty()) // если экземпляр класса Item пустой
	{
		item->Next = NULL;  // присваивание начальных значений NULL
		this->Tail = item;  // последний равен текущему
	}
	else
	{
		item->Next = this->Tail; // следующий равен последнему
		this->Tail = item;        // последний равен текущему
	}
}

void Stack::Push(float num)  // добавление значений в вверх стека
{
	Item* item = new Item(num);
	if(this->Empty())
	{
		item->Next = NULL;
		this->Tail = item;
	}
	else
	{
		item->Next = this->Tail;
		this->Tail = item;
	}
}

void Stack::Pop()       // функция удаления элемента с вершины стека
{
	if(!this->Empty())
	{
		this->Tail = this->Tail->Next;
	}
	else
	{
		throw 13;
	}
}

Item* Stack::Back()    // функция возвращения последнего элемента стека
{
	if(!this->Empty())
	{
		return this->Tail;
	}
	else
	{
		throw 13;
	}
}

bool Stack::Empty()   // функция проверки на пустоту стека
{
	if(this->Tail == NULL)
	{
		return true;
	}
	return false;
}
