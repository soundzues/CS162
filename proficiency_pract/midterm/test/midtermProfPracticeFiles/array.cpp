#include <iostream>


//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here
int numOfEven(int list[], int size) 
{
	int evencount = 0;
	for (int i = 0; i < size; i++)
	{
		if(list[i]%2 == 0)
		{
			evencount++;
		}
	}
	cout << "Number of even numbers = " << evencount << endl;

}

bool insert(int list[], int & size, int newInt, int pos, bool &success) 
{
	
	success = false;

	cout << "Please enter the number you want to insert" << endl;
	cin >> newInt;
	
	cout << "Pleas enter the position you want to insert the number to" << endl;
	cin >> pos;
	
	if(pos >= 0 && pos <=  size)
	{
		size++;
		for (int i = (size - 1); i >= pos; i--)
		{
			list[i] = list[i-1];
		}   
		list[pos] = newInt;
		success = true;
	}
	return success;

}

// *** End of array.cpp ***
