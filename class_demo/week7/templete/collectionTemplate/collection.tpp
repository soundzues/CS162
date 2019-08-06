// Implementation code file for collection template class.
// CS162, Summer '18, PCC
// The extension is .tpp, can't be .cpp because this file
// is included in the header file. Don't place this file
// or the header file in the compilation command. Just
// include the header file in the other source code files.

#include "collection.hpp"
template <class Type>
Type& Collection<Type>::operator[](int index) {
        return items[index];
}

template <class Type>
void Collection<Type>::addItem(Type newItem) {
    items[count] = newItem;
    count++;
}

template <class Type>
void Collection<Type>::print() {
    for (int i = 0; i < count; i++)
        std::cout << items[i];
}


