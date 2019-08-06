// Linked list header file.
#ifndef __LL__
#define __LL__

struct node {
    int number; // node is composed of Integer (composition).
    node *next;
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
    bool removeV1(int num);
    bool removeV2(int num);
};
#endif



