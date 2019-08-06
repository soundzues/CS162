//Adit Kotharii
//LAB6
#include "list.hpp"
// Implementation file for lab 6, CS162.
//put your implementation of LinkedList class here

// LinkedList constructor. Set head and tail to nullptr.
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

// AddEvenFrontOddEnd method. You must add even nodes to the head and odd nodes to the tail.
//  Suppose you use temp as a pointer and create a new node using temp. If head = nullptr,
//  set head = tail = temp. Temp will be the first node. To add to the head,
//  make head->prev point to temp, temp->next point to head, and head = temp.
//  To add to the tail, make tail->next point to temp, temp->prev point to tail,
//  and tail = temp. If you add to the head, make temp->prev = nullptr.
//  If you add to the tail, then temp->next = nullptr.
void LinkedList::addEvenFrontOddEnd(int val) 
{
	Node *temp = new Node;
    	temp->data = val;
    	temp->prev = NULL;
    	temp->next = NULL;
    	
	if (head == NULL) 
	{
        	head = temp;
        	tail = head;
    	}
    	else 
	{
		if(temp->data % 2 != 0) {
        		tail->next = temp;
        		temp->prev = tail;
    	  		tail = temp;
		}
		if(temp->data % 2 == 0)
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
	}
}

// Print the list in forward order. If the list is empty, return immediately.
//  Otherwise, create a temporary pointer that starts at head,
//  and then moves down the linked list: cur = head, while cur != nullptr, cur = cur->next.
void LinkedList::printAscending() const {
	if(head != NULL)
	{
		Node *cur;
		cur = head;
		while(cur != NULL)
		{
			cout << cur->data << endl;
			cur = cur->next;
		}
		
	}
}

// printDescending function. This function is complete, do not modify.
// This function passes the head pointer to printDescendingRecursive.
void LinkedList::printDescending() const {
    printDescendingRecursive(head);
	if(head != NULL)
	{
		Node *cur;
		cur = tail;
		while(cur != NULL)
		{
			cout << cur->data << endl;
			cur = cur->prev;
		}
	}
	
}

// Print the list in reverse order using head recursion.
//  *** Base Case: if cur is equal to nullptr, return.
//  *** Recursive case: if cur is not equal to nullptr, call printDescendingRecursive(cur->next).
//  After the two cases, output cur->data.
void LinkedList::printDescendingRecursive(Node * cur) const {

}

// Place the remove method here. If the val argument is not found in the list, or if the list is
//  empty, return false. Otherwise, create a temporary pointer, perhaps called cur.
//  If the number to remove is the head, set cur = head, set head->next->prev = nullptr,
//   head = head->next, then delete cur. You must check if head->next is not equal to nullptr first.
//  If the number to remove is the tail, set cur = tail, set tail->prev->next = nullptr,
//   tail = tail->prev, then delete cur. Check to see if tail->prev is not equal to nullptr first.
//  Lastly, if the node is somewhere in the middle, then cur->prev->next = cur->next,
//   cur->next->prev = cur->prev, and then delete cur.
//  If you removed a node, return true.
bool LinkedList::remove(int val) {
	bool success = false;
	if(head != NULL)
	{
		Node *cur, *temp ;
		cur = head;
		while(cur != NULL)
		{
			if(cur->data == val)
			{
				temp = cur;
				if(cur->prev != nullptr) { // cur is not head.
					cur->prev->next = cur->next;
				}
				else {
					if(cur->next != nullptr) {
						cur->next->prev = nullptr;
					}
					head = head->next;

				}
				if(cur->next != nullptr) {
					cur->next->prev = cur->prev;
				}
				else {
					if(cur->prev != nullptr) {
						cur->prev->next = nullptr;
					}
					tail = tail->prev;
				}
				success = true;
				delete cur;
				break;
			}
			else { // move down the list.
				cur = cur->next;
			}
		}
	}	
	return success;
}

