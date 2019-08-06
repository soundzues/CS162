#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 10;

int main()
{
	char choice = ' ' ;
	bool goAgain = true;
	char numstr[SIZE];
	int number = 0, sum = 0 ;

	do
	{
		cout << "what is your number? ";
		cin >> number;
		sum += number;	
		cout << "do you want to add another number? ";
		cin >> choice;
		choice = tolower(choice);
	}while(goAgain);
	
	for (int i = 0; i < 5; i++ )
	{
		cout << "Hello ";
	} 


	cout << "Type a number " << endl;
	cin.getline(numstr, SIZE);
	number = atoi(numstr); //atoi ascii to integer 

		
	while(number <= 0)
	{
		cout << "Try again: " << endl;
		cin.getline(numstr, SIZE);
	}
				

	return 0;
}
//dd to delete a line and p to paste it in visual mode
//do while vs while ---> do while will exec atleast once 
//always intilize a integer 
// choice = tolower(choice) -------> used to convert from upper to lower case, can be used a check.
//for loop used if number of iterations are known
//break can be used in loop structure
