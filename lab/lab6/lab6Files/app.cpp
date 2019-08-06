// CS162 Lab 6
// main function file, driver

#include "list.hpp"

int main()
{
	LinkedList aList;
        bool success = false;
	aList.addEvenFrontOddEnd(3);
	aList.addEvenFrontOddEnd(10);
	aList.addEvenFrontOddEnd(1);
	aList.addEvenFrontOddEnd(6);
	aList.addEvenFrontOddEnd(9);
	aList.addEvenFrontOddEnd(12);
	aList.printAscending();  // output should be: 12 6 10 3 1 9
	aList.printDescending(); // output should be: 9 1 3 10 6 12

	success = aList.remove(10);
        if(success)
            cout << "10 Successfully Removed." << endl;
	success = aList.remove(9);
        if(success)
            cout << "9 Successfully Removed." << endl;
        success = aList.remove(5); // 5 is not in the list, so success should be false.
        if(!success)
            cout << "5 is not in the list." << endl;
	success = aList.remove(12);
        if(success)
            cout << "12 Successfully Removed." << endl;

	aList.printAscending();  // output should be: 6 3 1.
	aList.printDescending(); // output should be: 1 3 6.

        aList.remove(3);
        aList.remove(1);
        aList.remove(6);
        aList.printAscending(); // The list is now empty, so your program should not crash.
        aList.printDescending();
 
	return 0;
}

