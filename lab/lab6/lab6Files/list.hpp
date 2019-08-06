// CS162 Lab 6 Header File
// Doubly Linked List

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
};

class LinkedList
{
    private:
	Node * head, * tail;
public:
	LinkedList();
	void addEvenFrontOddEnd(int val); // Add odd nodes to the end, and even nodes to the front.
	bool remove(int val);
	void printAscending() const;  // print the list in forward order.
        void printDescending() const; // start printDescendingRecursive. Code in list.cpp is complete (done).
	void printDescendingRecursive(Node * cur) const; // print the list in reverse order recursively.
};


#endif
