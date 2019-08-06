#include "linkedList.hpp"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = tail = nullptr;
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
int main() {
    int count = 0;
    LinkedList myNumbers;
    cout << "How many numbers? ";
    cin >> count;
    for(int i = 0; i < count; i++) {
        myNumbers.addNodeEnd();
    }
    myNumbers.print();
    return 0;}
