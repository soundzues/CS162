// Linked list header file.
#ifndef __LL__
#define __LL__
#include "Integer.hpp"

struct node {
    int number; // node is composed of Integer (composition).
    node * next;
};

class LinkedList {
     node *head;
     node *tail;
    public:
    LinkedList();
    ~LinkedList();
    void print();
    void addNodeBegin();
    void addANodeSorted() ;
    void addNodeEnd();
};
#endif
