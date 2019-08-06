//
//  CLL_ADT.hpp
//  CircularLinkedList
//

#ifndef CLL_ADT_hpp
#define CLL_ADT_hpp

#include "Node.hpp"
#include <iostream>

class CircularLL {
    Node * head;
public:
    CircularLL();
    void addToFront(int);
    void print();
};

#endif /* CLL_ADT_hpp */
