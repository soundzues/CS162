#include "header.hpp"
#include <iostream> 

using namespace std;

int main()
{
	DinoCollection dinos;
	bool success;
	int countDinos = 0;
	char choice  = ' ';
		
	dinos.getFileName();
	if(dinos.flag == 1)//flag used
	{
		cout << "Bye" << endl;
		return 0;
	}
	countDinos = dinos.loadDinos();//returning countAndIndex - number of dinos loaded
	cout << "Loaded " << countDinos << " dinos sucessfully " << endl;
	dinos.listDinos();
	
	
	do
	{
		cout << "What would you like to do? (S)earch (A)dd (L)ist or (q)uit" << endl;
		cin.get(choice);
		choice = tolower(choice);//even if the user enters lower case program will work
		cin.ignore();
	
		switch(choice)
		{
			case 's': 
				cout << "*****Searching*****" << endl;
				success = dinos.searchDinos();
				if(!success)
				{
					cout << "*****DINO NOT FOUND*****" << endl;
				}
				break;
			case 'a':
				cout << "*****Adding*****" << endl;
				dinos.addADino();
				break;
			case 'l':
				cout << "*****Listing*****" << endl;
				dinos.listDinos();
				break;
			case 'q'://writes to file  when program terminates
				dinos.writeDinos();
				break;
		}
	} 
	while(choice != 'q' );
	
	cout << "*****END OF PROGRAM*****" << endl;
	return 0;
}


