//
//  LL_ADT.hpp
//  CircularLinkedList
//

#ifndef LL_ADT_hpp
#define LL_ADT_hpp

#include "Node.hpp"
#include <iostream>

class LinkedList {
    Node * head;
public:
    LinkedList();
    void addToFront(int);
    void print();
};

#endif /* LL_ADT_hpp */
