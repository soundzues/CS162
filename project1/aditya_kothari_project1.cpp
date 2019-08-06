/*********************************************/
//Project:1 
//Aditya Kothari
//7/2/2018
/*********************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 128;

int main()
{	
	ofstream outFile;
	char filename[SIZE];
	char name[SIZE];
	char period[SIZE];
	char notes[SIZE];
	double age = 0, length = 0, height = 0;
	int weight = 0, count = 1;
	char choice = ' ';

	cout << "*****Welcome to Dino Catlog*****" << endl;

	cout << "What file name would you like to use for your collection?" << endl;
	cin.getline(filename, SIZE );
	outFile.open(filename);

	do
	{
		cout << "what is the name of the dinosaur?" << endl;
		cin.ignore();
		cin.getline(name, SIZE);
		while(cin.fail())
		{	
			cin.clear();
			cin.ignore(SIZE, '\n' );
			cout << "Please try again" << endl;
			cout << "What is the name of the dinosaur" << endl;
			cin.getline(name, SIZE);
		}

		cout << "what period did the dinosaur live in?" << endl;
		cin.ignore();
		cin.getline(period, SIZE);	
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(SIZE, '\n');
			cout << "Please try again" << endl;
			cout << "What period did the dinosaur live in?" << endl;
			cin.getline(name, SIZE);
		}

		cout << "How many million years ago did the dinosaur first appear?" << endl;
		cin >> age;
		while(cin.fail() || age <=0 ) 
		{
			cin.clear();
			cin.ignore(SIZE, '\n');
			cout << "Please try again" << endl;
			cout << "How many million years ago did the dinosaur first appear?" << endl;
			cin >> age;
		}

		cout << "how much did the dinosaur weigh on avg, in pounds?" << endl;
		cin >> weight;
//		cout << "weight: " << weight << endl;
		while(cin.fail() || weight <= 0)
		{
			cin.clear();
			cin.ignore(SIZE, '\n');
			cout << "Please try again" << endl;
			cout << "How much did the dinosaur weigh on avg, in pounds?" << endl;
			cin >> weight;
		}
		

		cout << "how long was the dinosaur  on avg, in feet?" << endl;
		cin >> length;
//		cout << "length: " << length << endl;
		while(cin.fail() || length <= 0)
		{
			cin.clear();
			cin.ignore(SIZE, '\n');
			cout << "Please try again" << endl;
			cout << "How long was the dinosaur on avg, in feet?" << endl;
			cin >> length;
		}	

		cout << "how tall was the dinosaur on avg, in feet?" << endl;
		cin >> height;
		while(cin.fail() || height <= 0)
		{
			cin.clear();
			cin.ignore(SIZE, '\n');
			cout << "Please try again" << endl;
			cout << "How long was the dinosaur on avg, in feet?" <<endl;
			cin >> height;
		}	

		cout << "Take some notes about the dinosaur " << endl;
		cin.ignore();
		cin.getline(notes, SIZE);
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(SIZE, '\n');
			cout << "Please try again" << endl;
			cout << "Take some notes please" << endl;
			cin.getline(notes, SIZE);
		}

		outFile << name << ", "
			<< period << ", "
			<< fixed << showpoint << setprecision(1)  
			<< age << ", "
			<< weight << ", "
			<< length << ", "
			<< height << ", "
			<< notes << endl;  

		cout << "do you want to add another dinosaur to the list?(y/n)" << endl;
		cin >> choice;
		while((choice != 'y') && (choice != 'n'))
		{	
			cin.clear();
			cin.ignore(SIZE, '\n');
			cout << "Please try again" << endl;
			cout << "Do you want to add another dinosaur to the list(y/n)" << endl;
			cin >> choice;
		}
		cin.ignore(SIZE, '\n' );

		if (choice == 'n')
		{
			break;
		} 	

		count++;

	}while(choice == 'y');

	outFile.close();
	cout << "----------------------" << endl;
	cout << "you entered " << count << " dinosaurs" << endl;	
	cout << "END OF PROGRAM" << endl;

	return 0;
}
//use cin ignore with getline statements only
