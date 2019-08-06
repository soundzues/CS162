#include "header.hpp"

using namespace std;

DinoCollection::DinoCollection() //constructor 
{
	countAndIndex = 0;
	flag = 0;//used in main function to notify and quit the program if file is not open
}

void DinoCollection::getFileName() //gets file name
{
	cout << "Welcome to the dino collection program. What is the file name?" << endl;
	cin.getline(fileName, STR_SIZE, '\n');

	infile.open(fileName);//opening file
	
	while(!infile.is_open())//unttil file is not found
	{
		cin.clear();
		cout << "File not found please try again or enter 'quit' to quit " << endl;
		cin.getline(fileName, STR_SIZE, '\n');
		if(strcmp(fileName, "quit") == 0)
		{
			cout << "file not found" << endl;
			flag = 1;//flag check
			break;
		}
//		cout << "test" << endl;
		infile.open(fileName);//retry to open
	}

}

int DinoCollection::loadDinos() //loads dinos
{
	char tempStr[STR_SIZE];
	
	while(!infile.eof())
	{
		infile.getline(dinoInfo[countAndIndex].name, STR_SIZE, ',');
		infile.getline(dinoInfo[countAndIndex].period, STR_SIZE, ',');

		infile.getline(tempStr, STR_SIZE, ',');//to use delimiter ',' , stores input as string
		dinoInfo[countAndIndex].appearDate = atof(tempStr);//converts to double

		infile.getline(tempStr, STR_SIZE, ',' );
		dinoInfo[countAndIndex].avgWeight = atoi(tempStr);//converts  to int

		infile.getline(tempStr, STR_SIZE, ',' );
		dinoInfo[countAndIndex].avgLength = atof(tempStr);

		infile.getline(tempStr, STR_SIZE, ',');
		dinoInfo[countAndIndex].avgHeight = atof(tempStr);
		
		infile.getline(dinoInfo[countAndIndex].note, STR_SIZE);
		infile.peek();
		
		countAndIndex++;
	}	
	return countAndIndex;

}

void DinoCollection::listDinos() //list them out - setprecision 2
{
	cout << endl;
	cout << setw(15) << left << "Name" << setw(14) << left << "Period" << setw(7) << right << "Appeared" << setw(9) << right << "Weight" << setw(9) << right << "Length" << setw(9) << right << "Height" << "    " << "Notes" << endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < countAndIndex; i++)
	{
		cout << setw(15) << left <<  dinoInfo[i].name << setw(12) << left << dinoInfo[i].period << setw(8) << right << fixed << showpoint << setprecision(2) << dinoInfo[i].appearDate << setw(9) << right  << dinoInfo[i].avgWeight << setw(9) << right << dinoInfo[i].avgLength << setw(9) << right  << dinoInfo[i].avgHeight << "     "  << dinoInfo[i].note << endl;
	}
}

bool DinoCollection::searchDinos() //will search for dinos
{
	int i;
	char findDino[STR_SIZE];
	cout << "Please enter the name of dinosaur you're looking for" << endl;
	cin.getline(findDino, STR_SIZE, '\n' );
	
	for (i = 0; i < countAndIndex; i++)
	{
		if(strcmp(findDino,dinoInfo[i].name) == 0)//comparing
		{
			check = true;
			cout << "*****DINO FOUND*****" << endl;
			cout << "information about " << dinoInfo[i].name <<  "is as follows: " << endl;
			cout << "Period:  " << dinoInfo[i].period << endl;
			cout << "First Apear: " << dinoInfo[i].appearDate << endl;
			cout << "Weight: "  << dinoInfo[i].avgWeight << endl;
			cout << "Length:  " << dinoInfo[i].avgLength << endl;
			cout << "Height: " << dinoInfo[i].avgHeight << endl;
			cout << "notes:  " << dinoInfo[i].note << endl;
			break; 
		}
	}
	if(strcmp(findDino, dinoInfo[i].name) < 0 || strcmp(findDino,dinoInfo[i].name) > 0)//if dino not found
	{
		check = false;
	}
	return check;

}

void DinoCollection::addADino() 
{
	if (countAndIndex > arraySize)//check for out of bounds
	{
		cout << "Out of Room :( " << endl;
	}
	
	cout << "What is the name of the dinosaur" << endl;
	cin.getline(dinoInfo[countAndIndex].name, STR_SIZE, '\n');
	cout << "In what period did the dinosaur live in? " << endl;
	cin.getline(dinoInfo[countAndIndex].period, STR_SIZE, '\n' );

	cout << "How many million years ago did the dinosaur first apear?" << endl;
	cin >> dinoInfo[countAndIndex].appearDate;
	while(cin.fail()|| dinoInfo[countAndIndex].appearDate <= 0 || dinoInfo[countAndIndex].appearDate < 66 || dinoInfo[countAndIndex].appearDate > 245)//dino apeared between 66 and 245
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter how many million years ago dinosaur first appeared between 66 and 245" << endl;
		cin >> dinoInfo[countAndIndex].appearDate;

	}
	
	cout << "How much on avg did the Dinosaur weigh?" << endl;
	cin >> dinoInfo[countAndIndex].avgWeight;
	while(cin.fail()|| dinoInfo[countAndIndex].avgWeight <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n' );
		cout << "Please re enter the wight " << endl;
		cin >> dinoInfo[countAndIndex].avgWeight;
	}

	cout << "How long was the diosaur?" << endl;
	cin >> dinoInfo[countAndIndex].avgLength;
	while(cin.fail()|| dinoInfo[countAndIndex].avgLength <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the length of the dinosaur" << endl;
		cin >> dinoInfo[countAndIndex].avgLength;
	}

	cout << "How tall was the dinosaur?" << endl;
	cin >> dinoInfo[countAndIndex].avgHeight;
	while(cin.fail()|| dinoInfo[countAndIndex].avgHeight <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the height of the dinosaur" << endl;	
		cin >> dinoInfo[countAndIndex].avgHeight;
	}
	
	cout << "Any special notes about the dinosaur?" << endl;
	cin.ignore(STR_SIZE, '\n' );
	cin.getline(dinoInfo[countAndIndex].note, STR_SIZE, '\n' );
	
	countAndIndex++; 
}

void DinoCollection::writeDinos()//writing to file setprecision 2
{
	outfile.open(fileName);
	for(int i = 0; i < countAndIndex; i++)
	{
		outfile << dinoInfo[i].name << "," << dinoInfo[i].period << "," << fixed << showpoint << setprecision(2) << dinoInfo[i].appearDate << "," << dinoInfo[i].avgWeight << "," << dinoInfo[i].avgLength << "," << dinoInfo[i].avgHeight << "," << dinoInfo[i].note << endl;
	}
	outfile.close();	
}
