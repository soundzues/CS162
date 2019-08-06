#ifndef __COLLECTION__
#define __COLLECTION__

// Template class example, CS162 Summer '18, PCC

template <class Type>
class Collection {
    static const int SIZE = 100;
    Type items[SIZE];
    int count = 0;
    public:
    // operator[] caused an error when printing in class,
    //  because I needed to return a reference.
    //  Now it returns Type& instead of Type. 
    Type& operator[](int);
    void addItem(Type newItem);
    void print();
};

// The source code file is included here.
//   I had to change the name from cpp to tpp
//   to avoid multiple compilation.
#include "collection.tpp"
#endif
