// Example code file for Part and Collection classes.
// Collection is a template class.
// CS162 Summer '18, PCC
// The compilation command should not include the
//   Collection files, because we are including the header file here,
//   and the header file includes the source code file (.tpp).

#include "part.hpp"
#include "collection.hpp"
#include <iostream>
using namespace std;

int main() {
    Collection<Part> inventory;
    Collection<int> myNumbers;
    myNumbers.addItem(3);
    myNumbers.addItem(7);
    Part p1("widget", 10); // Constructor with arguments.
    Part p2("widget", 5);
    Part p3("cogs", 10);
    inventory.addItem(p1);
    inventory.addItem(p2);
    inventory.addItem(p3);
    inventory.print();
    cout << "The third part is: " << inventory[2] << endl;
    cout << endl;
    myNumbers.print();
    return 0;
}
