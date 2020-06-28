//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
//---------------------------------------------------------------------------

class Item
{
	public:
	char Value;
	float floatValue;
	Item* Next;
	Item(char ch)
	{
		Next = NULL;
		Value = ch;
		floatValue = 0;
	}

	Item(float num)
	{
		Next = NULL;
		floatValue = num;
	}
};

class Stack
{
	public:
	Item* Tail;
	Stack()
	{
		Tail = NULL;
	}

	void Push(char);
	void Push(float);
	void Pop();
	Item* Back();
    bool Empty();
};

#endif
