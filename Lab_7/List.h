// ---------------------------------------------------------------------------

#ifndef ListH
#define ListH

template<class T>   
class List {
protected:
	struct Top {
		T value;   
		Top* prev;  
		Top* next; 

		Top() {        
			prev = nullptr;
			next = nullptr;
		}
	};

	Top* base;  

public:
	List() {    
		base = new Top;
		if (!base)
			throw 100;
		base->prev = base;
		base->next = base;
	}

	struct Iter {   
		Top* ptr;

		Iter(Top* x) {
			ptr = x;
		}

		Iter() {    
			ptr = nullptr;
		}

		Iter & operator++() { 
			(*this) = Iter(this->ptr->next);
			return *this;
		}

		Iter & operator--() {   
			(*this) = Iter(this->ptr->prev);
			return *this;
		}

		bool operator == (const Iter & it) const {  
			return this->ptr == it.ptr;
		}

		bool operator != (const Iter & it) const {
			return this->ptr != it.ptr;
		}

	};

	void clear() {    
		while (begin() != end())
			pop_back();
	}

	~List() {  
		clear();
		delete base;
	}

	T deletion(const Iter & it) { 
		if (it == end())
			throw 100;
		it.ptr->next->prev = it.ptr->prev;
		it.ptr->prev->next = it.ptr->next;
		T rtrn = it.ptr->value;
		delete it.ptr;  
		return rtrn;
	}

	T pop_back() {    
		return deletion(base->prev);
	}

	T pop_front() {   
		return deletion(base->next);
	}

	T & back() {     
		return base->prev->value;
	}

	T & front() {    
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

	void push_after(const Iter & it, const T & x) {  
		Top* tmp = new Top();
		if (!tmp)
			throw 100;
		tmp->prev = it.ptr;
		tmp->value = x;
		tmp->next = it.ptr->next;
		it.ptr->next->prev = tmp;
		it.ptr->next = tmp;
	}

	void push_back(const T & x) { 
		push_after(base->prev, x);
	}

	void push_front(const T & x) {  
		push_after(base, x);
	}

	T & operator[](const Iter & it) { 
		return it.ptr->value;
	}
};

// ---------------------------------------------------------------------------
#endif
