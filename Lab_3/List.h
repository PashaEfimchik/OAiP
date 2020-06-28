//---------------------------------------------------------------------------

#ifndef ListH
#define ListH

template <class T>  // универсальный шаблон класса Т
class List {
	struct Top {
		T value; // значение элемента
		Top* prev; // предыдущий элемент
		Top* next; // следующий элемент

		Top(){    // конструктор с начальными значениями null
			prev = nullptr;
			next = nullptr;
		}
	};

	Top* Base;   // переменная структуры Тор класса
	int Size = 0;

public:
	List(){   // конструктор с начальной инициализацией
		Size = 0;
		Base = new Top;
		if(!Base)
			throw 100;
		Base->prev = Base;
		Base->next = Base;
	}
	struct iterator {  // создание своего итератора
		Top* ptr;

		iterator(Top* x){
			ptr = x;
		}
		iterator(){  // конструктор задающий null элементам
			ptr = nullptr;
		}

		iterator & operator ++(){   // перегрузка оператора ++
			(*this) = iterator(this->ptr->next);
			return *this;
		}
						  // перегрузка оператора ==
		bool operator == (const iterator & it) const {
			return this->ptr == it.ptr;
		}                // перегрузка оператора !=
		bool operator != (const iterator & it) const {
			return this->ptr != it.ptr;
		}
	};

	void clear(){  // функция очищения списка
		while(begin() != end())
			pop_back();
	}
	~List(){  // деструктор
		clear();
		delete Base;
	}
							 // получение текущих значений
	void push_after(const iterator & it, const T & x){
		Top* tmp = new Top();
		if(!tmp)
			throw 100;
		tmp->prev = it.ptr;
		tmp->value = x;
		tmp->next = it.ptr->next;
		it.ptr->next->prev = tmp;
		it.ptr->next = tmp;
		Size++;
	}
	void push_back(const T & x){  // добавление в конец
		push_after(Base->prev, x);
	}
	void push_front(const T & x){   // добавление в начало
		push_after(Base, x);
	}
	void erase(const iterator & it){ // стирание текущих элементов
		if(it == end()) return;
		it.ptr->next->prev = it.ptr->prev;
		it.ptr->prev->next = it.ptr->next;
		delete it.ptr;  // очистка памяти
		Size--;
	}
	void pop_back(){  // стирание с конца
		erase(Base->prev);
	}
	void pop_front(){   // стирание с начала
		erase(Base->next);
	}

	iterator begin(){
		return Base->next;
	}
	iterator end(){
		return Base;
	}                          // перегрузка оператора индексации
	T & operator [] (const iterator & it) {
		return it.ptr->value;
	}

	int size(){
		return Size;
	}
};

//---------------------------------------------------------------------------
#endif
