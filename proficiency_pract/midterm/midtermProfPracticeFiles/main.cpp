// main function for the practice proficiency exam.
// CS162

#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
    int minEven;
    int list[CAP];
    int index = 0;
    bool success;
    int size = 10;
    build(list, size); // Place random numbers in list.
    display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the assigned functions 
    minEven = findMinEven(list, size);
    cout << "Minimum even number: " << minEven << endl;
    
    cout << "enter the index you want to delete" << endl;
    cin >> index;

    success = deleteIndex(list,size,index);	
    if(!success)
    {
	cout << "index delete failed" << endl;
    }
    else
    {
	cout << "index deleted successfuly" << endl;	
	display(list, size);
    }

    
    return 0;
}
// *** End of main.cpp ***
