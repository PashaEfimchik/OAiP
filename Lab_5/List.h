//---------------------------------------------------------------------------

#ifndef ListH
#define ListH

template <class T>  // шаблон класса Т
class List {
protected:
	struct Top {
		T value;   // значения
		Top* prev;    // предыдущий элемент
		Top* next;    // следующий элемент

		Top(){               // конструктор
			prev = nullptr;      // присваивает начальное значени = null
			next = nullptr;
		}
	};

	Top* Base;  // переменная структуры
public:
	List(){
		Base = new Top;      // назначение значений
		if(!Base)
			throw 100;
		Base->prev = Base;
		Base->next = Base;
	}

	struct iterator {     // структура для создания своего итератора
		Top* ptr;  // создание переменной структуры Top

		iterator(Top* x){
			ptr = x;
		}
		iterator(){
			ptr = nullptr;
		}

		iterator & operator ++(){ // перегрузка оператора ++
			(*this) = iterator(this->ptr->next);
			return *this;
		}
		iterator & operator --(){    // перегрузка оператора --
			(*this) = iterator(this->ptr->prev);
			return *this;
		}

		bool operator == (const iterator & it) const { // перегрузка оператора ==
			return this->ptr == it.ptr;
		}
		bool operator != (const iterator & it) const {  // перегрузка оператора !=
			return this->ptr != it.ptr;
		}

	};

	void clear(){
		while(begin() != end())  // функция очищения списка
			pop_back();
	}
	~List(){  // деструктор
		clear();
		delete Base;
	}

	void push_after(const iterator & it, const T & x){   // функция присваивания текущих элементов
		Top* tmp = new Top();
		if(!tmp) throw 100;
		tmp->prev = it.ptr;
		tmp->value = x;
		tmp->next = it.ptr->next;
		it.ptr->next->prev = tmp;
		it.ptr->next = tmp;
	}
	void push_back(const T & x){   // переопределение функции push_back
		push_after(Base->prev, x);
	}
	void push_front(const T & x){
		push_after(Base, x);
	}
	T erase(const iterator & it){    // стирание текущего элемента
		if(it == end()) throw 100;
		it.ptr->next->prev = it.ptr->prev;
		it.ptr->prev->next = it.ptr->next;
		T rtrn = it.ptr->value;
		delete it.ptr;
		return rtrn;
	}
	T pop_back(){
		return erase(Base->prev);   // стирание предыдущего элемента
	}
	T pop_front(){
		return erase(Base->next);   // стирание слеующего элемента
	}
	T & back(){
		return Base->prev->value;   // получение значений предыдущего
	}
	T & front(){
		return Base->next->value;   // получение значений следующего
	}

	iterator begin(){
		return Base->next;    // в начале используется следующий элемент
	}
	iterator last(){
		return Base->prev;
	}
	iterator end(){
		return Base;
	}
	T & operator [] (const iterator & it){
		return it.ptr->value;      // возвращение текущего элемента
	}
};

//---------------------------------------------------------------------------
#endif
