#include "list.h"
using namespace std;

int main()
{ 
    int num, pos;
    node * head = NULL;
    build(head);    // build() and display() are provided by supplied.o.
    display(head);  // Don't try to write the function definitions for them.

    //PLEASE PUT YOUR CODE HERE to call the functions assigned.
    cout << "The sum of the list is:  ";
    cout << sumOfList(head) << endl; //2 implement in main than go to implementiaon file

    cout << "What number would you like to add to the list?" << endl;
    cin >> num; 

    cout << "where should it go?" << endl;
    cin >> pos;
  
    insert(head, pos, num);     

    display(head);
    destroy(head);  // destroy() is also provided by supplied.o.
    return 0;
}
