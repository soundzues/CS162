// Main function for CS162 midterm proficiency.
#include "array.hpp"

using namespace std;

int main()
{
    int list[CAP];
    int size = 15;
    int minEven, index;
    bool deleteSuccess;
    build(list, size); // build() places random numbers in list.

    display(list, size); // display() will send the entire array to the screen.

    //PLEASE PUT YOUR CODE HERE to call the functions assigned

   minEven = findMinEven(list, size);
   cout << "The minimum even number is " << minEven << ". \n";
   	findMinEven(list, size);

    do {
        cout << "Which index you want to delete? ";
        cin >> index;
        while (!cin) {
            cin.clear();
            cin.ignore();
        }
        deleteSuccess = deleteIndex(list, index, size);
        if (!deleteSuccess)
            cout << "Invalid index. Try again. \n";
    } while (!deleteSuccess);
    
    cout << "The list after deletion: ";
    display(list, size); // This second call to display() will verify your code.
    
    return 0;
}
// *** End of main.cpp ***
