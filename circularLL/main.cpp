//
//  main.cpp
//  CircularLinkedList
//

#include <iostream>
#include "CLL_ADT.hpp"
#include "LL_ADT.hpp"

int main(int argc, const char * argv[]) {
    LinkedList list1;
    CircularLL list2;
    list1.addToFront(7);
    list1.addToFront(5);
    list1.addToFront(3);
    
    list2.addToFront(7);
    list2.addToFront(5);
    list2.addToFront(3);
    
    list1.print();
    list2.print();
    
    return 0;
}
