//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH

template <class K, class V>  
class Tree
{
protected:
	struct Top   
	{
		K key;      
		V value;    
		int level;  
		Top* left;  
		Top* right; 
        Top(K Key, V Value, int Level, Top* Left, Top* Right)
		{            
            key = Key;
			value = Value;
            level = Level;
            left = Left;
            right = Right;
        }
	} *root; 
	Top* Insert(Top* vrt, K x)   
    {
        if (!vrt)
            return new Top(x, V(), 1, nullptr, nullptr);
		if (x < vrt->key)      
            vrt->left = Insert(vrt->left, x);
		if (x > vrt->key)     
            vrt->right = Insert(vrt->right, x);
		vrt = Skew(vrt);    
		vrt = Split(vrt); 
        return vrt;
    }
	Top* Find(Top* vrt, K x)   
    {
        if (!vrt)
            return nullptr;
		if(x < vrt->key)        
            return Find(vrt->left, x);
		if(x > vrt->key)        
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
	Top* Skew(Top* vrt) 
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
	Top* Split(Top* vrt)  
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
	Top* Erase(Top* vrt, K x) 
    {
        if (!vrt)
            return nullptr;
        static Top* last;
		static Top* del = nullptr;
        last = vrt;
        if(x < vrt->key)
        {
			vrt->left = Erase(vrt->left, x);      
        }
        else
        {
            del = vrt;
			vrt->right = Erase(vrt->right, x);
		}
        if(vrt == last)
        {
            if(!del || del->key != x)
                return vrt;
			del->key = vrt->key;   
			del->value = vrt->value;   
            del = nullptr;
            vrt = vrt->right;
            delete last;
            last = nullptr;
		}
        else
		{               
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
	void Clear(Top* vrt)   
    {
        if (vrt)
        {
            Clear(vrt->left);
            Clear(vrt->right);
            delete vrt;
        }
    }
public:
	Tree()     
	{
		root = nullptr;  
	}
	~Tree()    
	{
		clear();    
    }
	void erase(K index)  
    {
        root = Erase(root, index);
    }
	void clear()   
    {
        Clear(root);
        root = nullptr;
    }
	void insert(K index) 
	{
        root = Insert(root, index);
    }
	V & operator [] (K index)  
    {
        insert(index);
        return Find(root, index)->value;
	}

	struct iterator {   
		Top* ptr;

		iterator(Top* x){
			ptr = x;
		}
		iterator(){     
			ptr = nullptr;
		}

		bool operator == (const iterator & it) const { 
            return this->ptr == it.ptr;
		}
		bool operator != (const iterator & it) const {  
			return this->ptr != it.ptr;
		}

		K & key(){     
            return this->ptr->key;
        }
		V & value(){   
            return this->ptr->value;
        }
	};
	iterator begin(){ 
	    Top* vrt = root;
	    while(vrt && vrt->left)
            vrt = vrt->left;
		return iterator(vrt);
	}
	iterator last(){ 
	    Top* vrt = root;
	    while(vrt && vrt->right)
            vrt = vrt->right;
		return iterator(vrt);
	}
	iterator end(){
		return iterator(nullptr);
	}
	iterator next(iterator it){ 
        return iterator(FindMore(root, it.ptr->key));
    }
	iterator prev(iterator it){  
        return iterator(FindLess(root, it.ptr->key));
	}
	iterator find(K index)  
	{
        return iterator(Find(root, index));
	}
};

//---------------------------------------------------------------------------
#endif
