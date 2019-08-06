//check for input failure
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype> //if it starts with c that means its from C
#include <cmath> 

using namespace std;


const int SIZE = 128;

int main()
{
	int number = 0;
	cout << "type a number" << endl;
	cin >> number; //eip - 11a, 11 would be stored in number and a would be thrown out, eip - 11.5


	while (cin.fail()) //cin.fail sort of error handling 
	{
		cout << "Try again " << endl;
		cin.clear(); // back to good state
		cin.ignore(SIZE, '\n');
		cin >> number;
	}

	cout << "your number is " << number << endl;
	return 0;
}
