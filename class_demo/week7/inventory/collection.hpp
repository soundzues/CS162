//file should have been .hpp file lol

#ifndef __COLLECTION__ //define for all files
#define __COLLECTION__

template <class Type>

class Collection
{
	static const int SIZE = 100;//static dies when program dies
	Type items[SIZE];
	int count = 0;	
	public:
	void addItem();
	void print();
};

#endif

template <class Type>
void Collection<Type>::addItem(Type newItem)
{
	intems[count] = newitem;
	count++;
}

template <class Type>
void Collection<type>::print()
{
	for (int i = 0; i < count; i++)
	{
		cout << items[i];
	}
}
