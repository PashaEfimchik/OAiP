//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH

template <class K, class V>  // универсальные шаблоны классов V и K
class Tree
{
protected:
	struct Top    // структура "Верхушка"
	{
		K key;      // ключ
		V value;     // значение
		int level;    // уровень
		Top* left;    // левое поддерево
		Top* right;   // правое поддерево
        Top(K Key, V Value, int Level, Top* Left, Top* Right)
		{             // конструктор
            key = Key;
			value = Value;
            level = Level;
            left = Left;
            right = Right;
        }
	} *root; // создание переменной структуры
	Top* Insert(Top* vrt, K x)   // функция вставки
    {
        if (!vrt)
            return new Top(x, V(), 1, nullptr, nullptr);
		if (x < vrt->key)      // условие для заполнения левого поддерева
            vrt->left = Insert(vrt->left, x);
		if (x > vrt->key)     // условие для заполнения правого поддерева
            vrt->right = Insert(vrt->right, x);
		vrt = Skew(vrt);    // смещение
		vrt = Split(vrt);  // разделение
        return vrt;
    }
	Top* Find(Top* vrt, K x)    // функция поиска
    {
        if (!vrt)
            return nullptr;
		if(x < vrt->key)              // поиск по левому поддереву
            return Find(vrt->left, x);
		if(x > vrt->key)              // поиск по правому поддереву
			return Find(vrt->right, x);
        return vrt;
    }
	Top* FindMore(Top* vrt, K x)
    {
        static Top* last;
        if (vrt == root)
            last = nullptr;
        if (!vrt)
            return last;
        if(x < vrt->key)
        {
            last = vrt;
			return FindMore(vrt->left, x);
        }
        if(vrt->key <= x)
        {
            return FindMore(vrt->right, x);
        }
    }
    Top* FindLess(Top* vrt, K x)
    {
        static Top* last;
        if (vrt == root)
            last = nullptr;
        if (!vrt)
            return last;
        if(x <= vrt->key)
        {
            return FindLess(vrt->left, x);
        }
        if(vrt->key < x)
        {
            last = vrt;
            return FindLess(vrt->right, x);
        }
    }
	Top* Skew(Top* vrt)    // функция сдвига
	{
        if (!vrt)
            return nullptr;
        if (!vrt->left)
            return vrt;
        if (vrt->level == vrt->left->level)
        {
            Top* rtrn = vrt->left;
            vrt->left = rtrn->right;
            rtrn->right = vrt;
            return rtrn;
        }
        return vrt;
    }
	Top* Split(Top* vrt)   // функция разделения от верхушки дерева
    {
        if (!vrt)
            return nullptr;
        if (!vrt->right)
            return vrt;
        if (!vrt->right->right)
            return vrt;
        if (vrt->level == vrt->right->right->level)
        {
            Top* rtrn = vrt->right;
            rtrn->level++;
            vrt->right = rtrn->left;
            rtrn->left = vrt;
            return rtrn;
        }
        return vrt;
    }
	Top* Erase(Top* vrt, K x)  // функция очистки
    {
        if (!vrt)
            return nullptr;
        static Top* last;
		static Top* del = nullptr;
        last = vrt;
        if(x < vrt->key)
        {
			vrt->left = Erase(vrt->left, x);       // очистка левого поддерева
        }
        else
        {
            del = vrt;
			vrt->right = Erase(vrt->right, x); // очистка правого поддерева
		}
        if(vrt == last)
        {
            if(!del || del->key != x)
                return vrt;
			del->key = vrt->key;   // удаление ключа
			del->value = vrt->value;   // удаление значения
            del = nullptr;
            vrt = vrt->right;
            delete last;
            last = nullptr;
		}
        else
		{                  // проверка на заполнение дерева
            if(((vrt->left ? vrt->left->level : 0) < vrt->level - 1) ||
                ((vrt->right ? vrt->right->level : 0) < vrt->level - 1))
            {
                vrt->level--;
                if(vrt->right && vrt->right->level > vrt->level)
                    vrt->right->level = vrt->level;
                vrt = Skew(vrt);
                if(vrt->right)
                {
                    vrt->right = Skew(vrt->right);
                    if(vrt->right->right)
                        vrt->right->right = Skew(vrt->right->right);
                }
                vrt = Split(vrt);
                if(vrt->right)
                    vrt->right = Split(vrt->right);
            }
        }
        return vrt;
    }
	void Clear(Top* vrt)   // функция очищения дерева
    {
        if (vrt)
        {
            Clear(vrt->left);
            Clear(vrt->right);
            delete vrt;
        }
    }
public:
	Tree()     // конструктор
	{
		root = nullptr;  // задает начальное значение
	}
	~Tree()     // деструктор
	{
		clear();    // очищение
    }
	void erase(K index)  // функция очистки индекса
    {
        root = Erase(root, index);
    }
	void clear()   // очистка переменной
    {
        Clear(root);
        root = nullptr;
    }
	void insert(K index) // присваивание значений переменной
	{
        root = Insert(root, index);
    }
	V & operator [] (K index)   // перегрузка операции индексирования
    {
        insert(index);
        return Find(root, index)->value;
	}

	struct iterator {   // создание нового итератора
		Top* ptr;

		iterator(Top* x){
			ptr = x;
		}
		iterator(){     // установка начального значения
			ptr = nullptr;
		}

		bool operator == (const iterator & it) const { // перегрузка оператора ==
            return this->ptr == it.ptr;
		}
		bool operator != (const iterator & it) const {  // перегрузка оператора !=
			return this->ptr != it.ptr;
		}

		K & key(){      // получение ключа
            return this->ptr->key;
        }
		V & value(){    // получение значения
            return this->ptr->value;
        }
	};
	iterator begin(){  // начальный итератор направляется на левое поддерево
	    Top* vrt = root;
	    while(vrt && vrt->left)
            vrt = vrt->left;
		return iterator(vrt);
	}
	iterator last(){  // последний - на правое поддерево
	    Top* vrt = root;
	    while(vrt && vrt->right)
            vrt = vrt->right;
		return iterator(vrt);
	}
	iterator end(){
		return iterator(nullptr);
	}
	iterator next(iterator it){  // получение следующего итератора
        return iterator(FindMore(root, it.ptr->key));
    }
	iterator prev(iterator it){  // получение предыдущего итератора
        return iterator(FindLess(root, it.ptr->key));
	}
	iterator find(K index)  // получение индекса
	{
        return iterator(Find(root, index));
	}
};

//---------------------------------------------------------------------------
#endif
