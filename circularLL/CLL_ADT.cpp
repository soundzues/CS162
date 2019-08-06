//
//  CLL_ADT.cpp
//  CircularLinkedList
//

#include "CLL_ADT.hpp"

CircularLL::CircularLL() {
    head = new Node;
    head->number = 0;  // dummy value for the dummy head.
    head->next = head;
}

void CircularLL::addToFront(int num) {
    Node * temp = new Node;
    temp->number = num;
    temp->next = head->next;
    head->next = temp;
}

void CircularLL::print() {
    Node * cur = head->next;
    while(cur != head) {
        std::cout << cur->number << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}
