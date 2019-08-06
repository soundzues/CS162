//download th new version 
#include "linkedList.hpp"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = tail = nullptr;
}

bool LinkedList::removeV2(int num)//get v2 from the professor's lab
{
	node *cur = head;
	node *prev = head;
	node *temp;
	bool success = false;
	//if same as v1
	
} 

bool LinkedList::removeV1(int num)
{
	node *cur = head;//starts at the beginning
	node *temp;	//used to delete a node
	bool success = false;
	
	if(head != nullptr)//cant derefernce a nullptr or a grabage pointer
	{
	//case 2: the node to remove is the head
	if(head->number == num)//draw it out 
	{
		temp = head;//temp will point to head
		head = head->next; //will point to the node next to the first node
		delete temp;
		success = true;
	}	
	
	//case 3a: remove some node in the list, 3b: to remove node at tail
	//we havent got to the node, travers.
	//or we are at the end of the node and num is not in the list
	else
	{
	while(cur->next != nullptr)//to traverse througth the list
	{
		if(cur->next->number = num)
		{
			temp = cur->next;
			cur->next = temp->next;
//			cur->next = cur->next->next;//connecting nodes, same as upper statement
			delete temp;
			success = true;
			break;
		}
		else//didn't find the number, move down
		{
			cur = cur->next;
		}
	}
	}

	}
	else
	{
		//case 1: the list is empty
		cout << "The lis is empty" << endl;
	}
	return success;
}

void LinkedList::print() {
    node * cur = head;
    if(head == nullptr) {
        cout << "The list is empty." << endl;
    }
    else {
        while(cur != nullptr) {
            cout << cur->number << endl;
            cur = cur->next; // move down to the next node.
        }
    }
}

void LinkedList::addANodeSorted() {
    int num;
    node *temp, *prev, *cur;
    cout << "What number do you want to add to the list? ";
    cin >> num;
    if(head == nullptr) {
        head = new node;
        head->number = num; 
        head->next = nullptr;
    }
    else { // there is at least one node in the list.
           // Find where temp goes. 
        temp = new node;
        temp->number = num;
        if(temp->number < head->number) { // temp should be the new head.
            temp->next = head; // temp->next points to head.
            head = temp; // now head points to temp.
        }
        else {
            prev = head; // set prev = n (head)
            cur = prev->next;
            while(cur != nullptr) {
                if(prev->number <= temp->number && cur->number >= temp->number) {
                    prev->next = temp;
                    temp->next = cur;
                    break;
                }
                else { // not the right spot, move down.
                    prev = cur;
                    cur = cur->next;
                }
            }
            if(cur == nullptr) { // We are at the end of the list.
                prev->next = temp;
                temp->next = nullptr; // Now we have a new tail.
            }
        }
    }
}

void LinkedList::addNodeBegin() {
    int num;
    node * temp;
    cout << "What number do you want to add to the list? ";
    cin >> num;
    if(head == nullptr) { // the list is empty.
        head = new node;
        head->number = num;
        head->next = nullptr;
    }
    else { // there is at least one node in the list.
           // place the node at the head. build backwards.
        temp = new node;
        temp->number = num;
        temp->next = head; // temp->next points to head.
        head = temp; // now head points to temp.
    }
}

void LinkedList::addNodeEnd() {
    int num;
    node * temp;
    cout << "What number would you like to add? ";
    cin >> num;
    if(head == nullptr) { // list is empty.
        head = new node;
        head->number = num;
        head->next = nullptr;
        tail = head;
    }
    else { // at least one node.
        temp = new node;
        temp->number = num;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
}

LinkedList::~LinkedList() {
    node * temp;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

