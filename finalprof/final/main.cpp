#include "list.hpp"
using namespace std;

int main()
{
    int total;
    node * head = NULL;
    build(head); // After this call, 10 to 20 nodes, starting at head.
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the functions assigned.
    total = sumEvenNodes(head);
    cout << "the sum of the list = " << total << endl;	
    
    removeOddNodes(head);
		
    display(head);
    destroy(head);
    
    return 0;
}
