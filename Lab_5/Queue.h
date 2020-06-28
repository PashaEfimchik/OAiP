//---------------------------------------------------------------------------
#include "List.h"

#ifndef QueueH
#define QueueH

//---------------------------------------------------------------------------

template <class T>  // универсальный шаблон класса Т
class Queue : public List<T> {

typedef typename List<T>::iterator iterator;  // создание своего итератора

private:
	void push_into(List<T> & to, iterator & it){  // функция разыменования
		it.ptr->prev = to.last().ptr;
		it.ptr->next = to.end().ptr;
		to.last().ptr->next = it.ptr;
		to.end().ptr->prev = it.ptr;
	}

public:

			// функция разделения списков
	void split(List<T> & out1, List<T> & out2, bool (*rule) (const T & a)){
		for (iterator it = List<T>::begin(); it != List<T>::end(); )
		{
			iterator next = it;
			++next;
			if (rule(it.ptr->value))
			{
				push_into(out1, it);
			}
			else
			{
				push_into(out2, it);
			}
			it = next;
		}
		List<T>::end().ptr->prev = List<T>::end().ptr->next = List<T>::end().ptr;
	}

};

//---------------------------------------------------------------------------
#endif
