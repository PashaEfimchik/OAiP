// ---------------------------------------------------------------------------

#ifndef ListH
#define ListH

template<class T>   // шаблон класса Т
class List {
protected:
	struct Top {
		T value;    // значение элемента
		Top* prev;  // предыдущий элемент
		Top* next;  // следующий элемент

		Top() {        // конструктор с начальными значениями null
			prev = nullptr;
			next = nullptr;
		}
	};

	Top* base;  // переменная структуры Тор класса

public:
	List() {    // конструктор с начальной инициализацией
		base = new Top;
		if (!base)
			throw 100;
		base->prev = base;
		base->next = base;
	}

	struct Iter {   // создание своего итератора
		Top* ptr;

		Iter(Top* x) {
			ptr = x;
		}

		Iter() {     // конструктор задающий null элементам
			ptr = nullptr;
		}

		Iter & operator++() {  // перегрузка оператора ++
			(*this) = Iter(this->ptr->next);
			return *this;
		}

		Iter & operator--() {   // перегрузка оператора --
			(*this) = Iter(this->ptr->prev);
			return *this;
		}

		bool operator == (const Iter & it) const {  // перегрузка оператора ==
			return this->ptr == it.ptr;
		}

		bool operator != (const Iter & it) const { // перегрузка оператора !=
			return this->ptr != it.ptr;
		}

	};

	void clear() {    // функция очищения списка
		while (begin() != end())
			pop_back();
	}

	~List() {  // деструктор
		clear();
		delete base;
	}

	T deletion(const Iter & it) { // стирание текущих элементов
		if (it == end())
			throw 100;
		it.ptr->next->prev = it.ptr->prev;
		it.ptr->prev->next = it.ptr->next;
		T rtrn = it.ptr->value;
		delete it.ptr;  // очистка памяти
		return rtrn;
	}

	T pop_back() {     // стирание с конца
		return deletion(base->prev);
	}

	T pop_front() {     // стирание с начала
		return deletion(base->next);
	}

	T & back() {       // добавление значений в конец
		return base->prev->value;
	}

	T & front() {    // добавление значений в начало
		return base->next->value;
	}

	Iter begin() {
		return base->next;
	}

	Iter last() {
		return base->prev;
	}

	Iter end() {
		return base;
	}

	void push_after(const Iter & it, const T & x) {  // получение текущих значений
		Top* tmp = new Top();
		if (!tmp)
			throw 100;
		tmp->prev = it.ptr;
		tmp->value = x;
		tmp->next = it.ptr->next;
		it.ptr->next->prev = tmp;
		it.ptr->next = tmp;
	}

	void push_back(const T & x) {  // добавление в конец
		push_after(base->prev, x);
	}

	void push_front(const T & x) {  // добавление в начало
		push_after(base, x);
	}

	T & operator[](const Iter & it) { // возвращение текущего элемента
		return it.ptr->value;
	}
};

// ---------------------------------------------------------------------------
#endif
