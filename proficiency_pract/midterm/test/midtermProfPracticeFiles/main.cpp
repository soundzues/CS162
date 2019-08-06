// main function for the practice proficiency exam.
// CS162

#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
    int list[CAP];
    int countEven = 0, newInt, pos;
    bool success;
    int size = 10;
    build(list, size); // Place random numbers in list.
    display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the assigned functions 
    numOfEven(list, size); 
    insert(list, size, newInt, pos, success); 	   
    display(list, size);
//    cout << "TEST" << endl;
    return 0;
}
// *** End of main.cpp ***
