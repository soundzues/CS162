#include <iostream>

const int strSize = 256;
const int names = 3;
const int rows = 10;
const int cols = 10;
const int size  = 10;

void fillArra

int main()
{
	char nameStr[strSize];
	char fullName[names][strSize]; //first, midlle and last
	int numbers[size];
	int towD[rows][cols];
	cout << "what is your first name? ";
	cin.getline(fullName[0], strSize)//starSize is the size of the string, third argument is the delimiter  
	cout << "what is your last name? ";
	cin.getline(fullName[2], strSize);
}
