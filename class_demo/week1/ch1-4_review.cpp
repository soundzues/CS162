//chapter 1 to 4 rev 
//REVISE POST VS PREINCREMENT 
// revise manipulator


#include <iostream>
#include <iomanip> //allows to manipulate stuff
using namespace std;

int main()
{
	int num = 3;
	int change = 81;
	float changeinfloat;
	double dnum = 12.3537;

	cout << "Give me a number: ";
	cin >> num;
 	cout << "you chose: " << num << endl;

	cout << "Quarters:  " << change/25 << endl;
	cout << "change in float: " << change/25 << endl;
	cout << "Leftovers: " << change%25 << endl;

	cout << "Numbers: " << 4.0 / 3 << endl; //its gonaa convert 3 to floating poiint 3.0 and then perform the followin operation - folows pemdas 
 	
	int num1 = 3, int num2 = 4, num3;
	num3 = num1 + ++num2; //++ in the begining therfore add first 
	//num2 = num2 + 1  = 5
	//num3 = num2 + num1 = 8 
	
	num3 = num1 + num2++; //++ in the end therfore add later
	//num3 = num1 + num2
	//num2 = num2 + 1	

	cout << fixed << showpoint << setprecision(3); //will round to 12.354
	cout << dnum << endl;

	return 0; //integer type therfore it has to return a value ~ 0
}
//:w to save files
//:q to quit
//:wq to write and quit
//:set number to set lines 

