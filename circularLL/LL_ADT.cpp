//
//  LL_ADT.cpp
//  CircularLinkedList
//

#include "LL_ADT.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::addToFront(int num) {
    Node * temp = new Node;
    temp->number = num;
    temp->next = nullptr;
    
    if(head == nullptr) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void LinkedList::print() {
    Node * cur = head;
    while(cur != nullptr) {
        std::cout << cur->number << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}
