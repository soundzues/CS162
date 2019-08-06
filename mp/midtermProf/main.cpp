// Main function for CS162 midterm proficiency.
#include "array.hpp"

using namespace std;

int main()
{
    bool success;
    int val = 0;
    int list[CAP];
    int size = 15;
    build(list, size); // build() places random numbers in list.

    display(list, size); // display() will send the entire array to the screen.

    //PLEASE PUT YOUR CODE HERE to call the functions assigned
    cout << "sum of min and max number is: " <<  addMinMax(list, size) << endl;
    
    cout << "Please enter the number you want to move" << endl;
    cin >> val;
    success =  moveToFirst(list, val, size);
    display(list, size); // This second call to display() will verify your code.
    if(!success)
    {
	cout << "failed to move first" << endl;
    }
    
    return 0;
}
// *** End of main.cpp ***
