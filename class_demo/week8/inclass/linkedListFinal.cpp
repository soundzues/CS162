#include <iostream>
using namespace std;

struct node {
    int number;
    node * next;
};

void print(node * n) {
    node * cur = n;
    if(n == nullptr) {
        cout << "The list is empty." << endl;
    }
    else {
        while(cur != nullptr) {
            cout << cur->number << endl;
            cur = cur->next; // move down to the next node.
        }
    }
}

void addANodeSorted(node * &n) {
    int num;
    node *temp, *prev, *cur;
    cout << "What number do you want to add to the list? ";
    cin >> num;
    if(n == nullptr) { // the list is empty.
        n = new node;
        n->number = num;
        n->next = nullptr;
    }
    else { // there is at least one node in the list.
           // Find where temp goes. 
        temp = new node;
        temp->number = num;
        if(temp->number < n->number) { // temp should be the new head.
            temp->next = n; // temp->next points to head.
            n = temp; // now head points to temp.
        }
        else {
            prev = n; // set prev = n (head)
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

void addANode(node * &n) {
    int num;
    node * temp;
    cout << "What number do you want to add to the list? ";
    cin >> num;
    if(n == nullptr) { // the list is empty.
        n = new node;
        n->number = num;
        n->next = nullptr;
    }
    else { // there is at least one node in the list.
           // place the node at the head. build backwards.
        temp = new node;
        temp->number = num;
        temp->next = n; // temp->next points to head.
        n = temp; // now head points to temp.
    }
}

void addANodeTail(node * &n) {
    int num;
    node * prev = n;
    node * cur = n;
    node * temp;
    cout << "What number would you like to add? ";
    cin >> num;
    if(n == nullptr) { // list is empty.
        n = new node;
        n->number = num;
        n->next = nullptr;
    }
    else { // at least one node.
        while(cur != nullptr) {
            prev = cur;
            cur = cur->next;
        }
        // After loop, cur points to tail.
        temp = new node;
        temp->number = num;
        prev->next = temp;
        temp->next = nullptr;
    }
}

void free(node * n) {
    node * temp;
    while(n != nullptr) {
        temp = n;
        n = n->next;
        delete temp;
    }
}
int main() {
    node * head = nullptr; // the list is empty.
    addANodeSorted(head);
    addANodeSorted(head);
    addANodeSorted(head);
    addANodeSorted(head);
    print(head);
    free(head);
    return 0;
}
