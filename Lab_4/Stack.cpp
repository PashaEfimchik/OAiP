//---------------------------------------------------------------------------

#pragma hdrstop

#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Stack::Push(char ch)  
{
	Item* item = new Item(ch);
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

void Stack::Push(float num)  
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

void Stack::Pop()       
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

Item* Stack::Back()    
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

bool Stack::Empty()   
{
	if(this->Tail == NULL)
	{
		return true;
	}
	return false;
}
