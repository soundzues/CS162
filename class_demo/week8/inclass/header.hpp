//Linked list header file.
#ifndef __HEADER__//name does not matter
#define __HEADER__
struct node 
{
    int number;
    node *next;
};

class LinkedList
{
	node *head;//point to the first node in the linked list
	
	public:
	void print();
	void addNodeBegin();
	void addANodeSorted();
	void addNodeEnd();
	void free();

};
#endif
