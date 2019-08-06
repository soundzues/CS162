//Adit Kotharii
//CS 162: project2 
//Source: Project programing stragies, c++.com

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int const STR_SIZE = 256;
int const SIZE = 256;

struct dinoType {
	char name[STR_SIZE];
	char period[STR_SIZE];
	double appearDate;
	int avgWeight;
	double avgLength;
	double avgHeight;
	char note[STR_SIZE];
};

int loadDinos(dinoType dinoInfo[], ifstream &infile, int &count)
{
	char tempStr[STR_SIZE];

	while(!infile.eof())
	{
		infile.getline(dinoInfo[count].name, STR_SIZE, ',');
		infile.getline(dinoInfo[count].period, STR_SIZE, ',');
		infile.getline(tempStr, STR_SIZE, ','); //to use the delim ',', taking input as a string
		dinoInfo[count].appearDate = atof(tempStr);  //converting to double
		infile.getline(tempStr, STR_SIZE, ',');
		dinoInfo[count].avgWeight = atoi(tempStr); // avgWeight is an int!
		infile.getline(tempStr, STR_SIZE, ',');
		dinoInfo[count].avgLength = atof(tempStr);
		infile.getline(tempStr, STR_SIZE, ',');
		dinoInfo[count].avgHeight = atof(tempStr);
		infile.getline(dinoInfo[count].note, STR_SIZE);
		infile.peek();
		//		lout << "testing" <<  dinoInfo[count].name << dinoInfo[count].appearDate << dinoInfo[count].note << endl;
		count++;
	}
	return count;
}

void listDinos(dinoType dinoInfo[],int &count)
{	


	cout << endl;
	cout << setw(15) << left <<  "Name" << setw(14) << left << "Period" << setw(7) << right << "Appeared" << setw(9) << right << "Weight" << setw(9) << right << "Length" << setw(9) << right << "Height" << "    " << "Notes" <<  endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- "<<endl;
	for (int i = 0; i < count; i++)
	{
	cout << setw(15) << left <<  dinoInfo[i].name <<  setw(12)  << left << dinoInfo[i].period << setw(8) << right << dinoInfo[i].appearDate << setw(9) << right << dinoInfo[i].avgWeight << setw(9) << right<< dinoInfo[i].avgLength << setw(9) << right << dinoInfo[i].avgHeight << "      " <<  dinoInfo[i].note << endl;
	}	
}

void searchDinos(dinoType dinoInfo[], int &count)
{
	int i;
	char findDino[STR_SIZE];
	cout << "Please enter the name of the Dinosaur" << endl;
	cin.getline(findDino, STR_SIZE, '\n' );
	//cout << findDino << endl;

	for (i = 0; i < count; i++)
	{
		if(strcmp(findDino,dinoInfo[i].name) == 0)
		{
			cout << "*****Dino found*****" << endl;
			cout << "information about " << dinoInfo[i].name << "is as follows: " <<  endl;
			cout << "Period: " << dinoInfo[i].period << endl;
			cout << "First Apear: " << dinoInfo[i].appearDate << endl;
			cout << "Weight: " << dinoInfo[i].avgWeight << endl; 
			cout << "Length:  " << dinoInfo[i].avgLength << endl;
			cout << "Height: " << dinoInfo[i].note << endl; 
			break;
		}
	}
	if(strcmp(findDino,dinoInfo[i].name) < 0 || strcmp(findDino,dinoInfo[i].name) > 0)
	{
		cout << "*****dino not found in the database *****" << endl;
	}
}

void addDino(dinoType dinoInfo[],dinoType dinoTemp, int &count)
{
	if(SIZE < count)
	{
		cout << "database is full :( " << endl;
	}

	cout << "What is the name of the diosaur?"  << endl;
	cin.getline(dinoTemp.name, STR_SIZE, '\n');
	cout << "In what period did the dinosaur live in? " << endl;
	cin.getline(dinoTemp.period, STR_SIZE, '\n');
	cout << "How many years ago did the dinosaur first apear? " << endl;
	cin >> dinoTemp.appearDate;
	while(cin.fail()|| dinoTemp.appearDate <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the age when dinosaur first appeared" << endl;
		cin >> dinoTemp.appearDate;
	}

	cout << "How much on avg did the Dinosaur weigh?" << endl;
	cin >> dinoTemp.avgWeight;
	while(cin.fail()|| dinoTemp.avgWeight <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the weight" << endl;
		cin >> dinoTemp.avgWeight;
	}
	cout << "How long was the dinosaur in avg" << endl;
	cin >> dinoTemp.avgLength;
	while(cin.fail()|| dinoTemp.avgLength <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the Length" << endl;
		cin >> dinoTemp.avgLength;
	
	}
	
	cout << "How tall was the dinosaur in avg" << endl;
	cin >> dinoTemp.avgHeight;
	while(cin.fail()|| dinoTemp.avgHeight <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the Length" << endl;
		cin >> dinoTemp.avgHeight;
	
	}
	
	
	cout << "Any notes about the dinosaur?" << endl;
	cin.ignore(STR_SIZE, '\n' );
	cin.getline(dinoTemp.note, STR_SIZE, '\n');

	dinoInfo[count] = dinoTemp;
	count++;
//	cout << "test" << dinoInfo[count].name << endl;		
}

int main()
{
	dinoType dinoInfo[SIZE];
	dinoType dinoTemp;
	char filename[STR_SIZE];
	char choice = ' ';
	int count = 0;
	ifstream infile;

	cout << "Welcome to the dino collection program. What is the file name?" << endl;
	cin.getline(filename, STR_SIZE, '\n');

	infile.open(filename); //opens file

	if(!infile.is_open()) //if file not open do the following things:
	{
		do
		{
			cin.clear(); //clears buffer
	//		cin.ignore();
			cout << "File not found, please try again or enter 'quit' to quit" << endl;
//			cin.ignore(STR_SIZE, '\n' );
			cin.getline(filename, STR_SIZE, '\n');
			cout << filename << endl;
			infile.open(filename);
			if(strcmp(filename, "quit" ) == 0) //strcmp = 0, when 2 strings are equal
			{
				cout << "FILE NOT FOUND" << endl;
				return 0;
			}
		}while(!infile);

	}
	if(infile.is_open()) //if file is open
	{
		loadDinos(dinoInfo, infile, count);
		cout << count << " Dinos Loaded Succesfully" << endl;
	//	listDinos(dinoInfo, count);
	}
	do
	{
		cout << "What would you like to do? (S)earch (A)dd (L)list or (Q)uit" << endl;
		cin.get(choice);
		cin.ignore();
		//cout << choice;
		switch(choice) //switch case for menu driven language
		{
			case 'S':
				cout << "*****Searching*****" << endl;	
				searchDinos(dinoInfo , count);
				break;
			case 'A':
				cout << "*****Adding*****" << endl;
				addDino(dinoInfo, dinoTemp, count);
				break;
			case 'L':
				cout << "*****Listing*****" << endl;
				listDinos(dinoInfo, count); 
				break;
			default:
				//cout << "Invalid choice" << endl;
				break;
				//cin >> choice;
		}

	}while(choice != 'Q' );
	infile.close();
	return 0;
}	
