#include "linkedList.hpp"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = tail = nullptr;
}

bool LinkedList::removeV2(int num) {
    node * cur = head; // start at the beginning.
    node * prev = head;
    node * temp;       // used to delete a node.
    bool success = false;
    if(head != nullptr) {
        // Case 2: the node to remove is the head.
        if(head->number == num) {
            temp = head;
            head = head->next;
            delete temp;
            success = true;
        }
        // Case 3a and 3b.
        // we haven't gotten to the node, traverse.
        // or we are at the end, and num is not in the list.

        else { // The number is not at the head.
            cur = cur->next;
            while(cur != nullptr) {
                if(cur->number == num) {
                    temp = cur;
                    prev->next = cur->next;
                    delete temp;
                    success = true;
                    break;
                }
                else { // didn't find the number, move down.
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
    }

    // Case 3a: remove some node in the list,
    //  case 3b: or remove the tail.
    else {
        // Case 1: the list is empty.
        cout << "The list is empty." << endl;
    }
    return success;
}


bool LinkedList::removeV1(int num) {
    node * cur = head; // start at the beginning.
    node * temp;       // used to delete a node.
    bool success = false;
    if(head != nullptr) {
        // Case 2: the node to remove is the head.
        if(head->number == num) {
            temp = head;
            head = head->next;
            delete temp;
            success = true;
        }
        // Case 3a and 3b.
        // we haven't gotten to the node, traverse.
        // or we are at the end, and num is not in the list.

        else { // The number is not at the head.
            while(cur->next != nullptr) {
                if(cur->next->number == num) {
                    temp = cur->next;
                    cur->next = temp->next;
                    delete temp;
                    success = true;
                    break;
                }
                else { // didn't find the number, move down.
                    cur = cur->next;
                }
            }
        }
    }

    // Case 3a: remove some node in the list,
    //  case 3b: or remove the tail.
    else {
        // Case 1: the list is empty.
        cout << "The list is empty." << endl;
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

