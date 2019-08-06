// Doubly Linked List example driver.
// CS162, Summer '18
//
#include "linkedList.hpp"
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int numToRemove = 0;
    bool success = false;
    LinkedList myNumbers;
    cout << "How many numbers? ";
    cin >> count;
    for(int i = 0; i < count; i++) {
        myNumbers.addNodeEnd();
    }
    myNumbers.print();
    cout << "What number do you want to remove? ";
    cin >> numToRemove;
    success = myNumbers.removeV2(numToRemove);
    if(success)
        cout << numToRemove << "was successfully removed from the list." << endl;
    myNumbers.print();
    return 0;
}
