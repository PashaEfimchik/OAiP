// ---------------------------------------------------------------------------

#include "List.h"

#ifndef HashH
#define HashH

template<class T>
class Hash {
protected:
	int TSize;
	List<T> *Table;

	int(*HashF)(const T & x); 

	int GetHash(const T & x) {  
		return ((HashF(x) % TSize) + TSize) % TSize;
	}

public:
	Hash(int tSize, int(*hashF)(const T&)) { 
		HashF = hashF;
		TSize = tSize;
		Table = new List<T>[TSize];
		if (!Table)
			throw;
	}

	void clear() {    
		for (int i = 0; i < TSize; i++)
			Table[i].clear();
	}

	~Hash() {   
		clear();
		delete[]Table;
	}

	void insert(const T & x) {  
		int i = GetHash(x);
		Table[i].push_back(x);
	}

	void deletion(const T & x) { 
		int i = GetHash(x);
		for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
			if (x == Table[i][it]) {
				Table[i].deletion(it);
				return;
			}
	}

	bool contain(const T & x) {  
		int i = GetHash(x);
		for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
			if (x == Table[i][it])
				return true;
		return false;
	}
};

// ---------------------------------------------------------------------------
#endif
