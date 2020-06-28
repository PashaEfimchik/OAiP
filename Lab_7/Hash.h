// ---------------------------------------------------------------------------

#include "List.h"

#ifndef HashH
#define HashH

template<class T>
class Hash {
protected:
	int TSize;
	List<T> *Table;

	int(*HashF)(const T & x); // выделение памяти

	int GetHash(const T & x) {   // функция получения всех данных памяти
		return ((HashF(x) % TSize) + TSize) % TSize;
	}

public:
	Hash(int tSize, int(*hashF)(const T&)) { // конструктор класса Hash
		HashF = hashF;
		TSize = tSize;
		Table = new List<T>[TSize];
		if (!Table)
			throw;
	}

	void clear() {     // функция очищения таблицы
		for (int i = 0; i < TSize; i++)
			Table[i].clear();
	}

	~Hash() {    // деструктор
		clear();
		delete[]Table;
	}

	void insert(const T & x) {  // функция вставки данных в таблицу
		int i = GetHash(x);
		Table[i].push_back(x);
	}

	void deletion(const T & x) {  // функция стирания данных из таблицы
		int i = GetHash(x);
		for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
			if (x == Table[i][it]) {
				Table[i].deletion(it);
				return;
			}
	}

	bool contain(const T & x) {   // проверка на наличие элементов в таблице
		int i = GetHash(x);
		for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
			if (x == Table[i][it])
				return true;
		return false;
	}
};

// ---------------------------------------------------------------------------
#endif
