#include "header.hpp"
#include <iostream>
using namespace std;

DinoCollection::DinoCollection()//default dinoCollection constructor
{
	countAndIndex = 0;
	flag = 0;
	check = false;//pessmestic 
}

DinoInfo::DinoInfo(char n[], char p[], double ad, int aw, double al, double ah, char no[]) //parameterized constructor
{
	int nameLen = 0, periodLen = 0, noteLen = 0;//will store length of the cstrings
	//alocating dynamic memory for the c strings
	nameLen = strlen(n);//storing size of c string
	name = new char[nameLen + 1]; //+1 for null pointer
	strcpy(name, n); //coppying n into name

	periodLen = strlen(p);
	period = new char[periodLen+1];
	strcpy(period, p);
	
	noteLen = strlen(no);
	note = new char[noteLen + 1];
	strcpy(note, no);
	
	appearDate = ad;
	avgWeight = aw;
	avgLength = al;
	avgHeight = ah;
	
}

DinoInfo::~DinoInfo()//destructor to free memory 
{
	delete []name;
	delete []period;
	delete []note;
}

DinoCollection::~DinoCollection()//since used array pointer need to free all of them
{
	for (int i = 0; i < countAndIndex; i++ )
	{
		delete dinoInfo[i] ;
		dinoInfo[i] = NULL;
	}
}

const char *DinoInfo::getName()//acessor for dino info class
{
	return name;
}

const char *DinoInfo::getPeriod()
{
	return period;
}

const double DinoInfo::getAppearDate()
{
	return appearDate;
}

const int DinoInfo::getAvgWeight()
{
	return avgWeight;
}

const double DinoInfo::getAvgLength()
{
	return avgLength;
}

const double DinoInfo::getAvgHeight()
{
	return avgHeight;
}

const char *DinoInfo::getNote()
{
	return note;
}

void DinoCollection::getFileName()//gets file name
{
	cout << "Welcome to the Dino collection program" << endl;
	cout << "Please enter the name of the file" << endl;
	cin.getline(fileName, STR_SIZE, '\n' );

	infile.open(fileName);//opening file

	while(!infile.is_open())//untill file is not found
	{
		cin.clear();
		cout << "File not found, Please re-enter the file name or type 'quit' to quit" <<endl;
		cin.getline(fileName, STR_SIZE, '\n' );
//		cout << fileName << endl;
		
		if(strcmp(fileName, "quit") == 0)//if strings are equal strcmp = 0
		{
			cout << "File not found" << endl;
			flag = 1;//flag check
			break;
		}
		infile.open(fileName);//retry to open
		//flag = 0 in constructor
	}
}

const int DinoCollection::getFlag()//to access flag
{
	return flag;
}

int DinoCollection::loadDinos()
{	//temp variables will be passed as actual parameters to the constructor
	char tempName[STR_SIZE], tempPeriod[STR_SIZE], tempNote[STR_SIZE], tempStr[STR_SIZE];
	double tempDate, tempLength, tempHeight;
	int tempWeight;
	
	while(!infile.eof())
	{
		infile.getline(tempName, STR_SIZE, ',');
		
		infile.getline(tempPeriod, STR_SIZE, ',' );

		infile.getline(tempStr, STR_SIZE, ',');//using tempStr to use ',' delim
		tempDate = atof(tempStr);//converts string  to double

		infile.getline(tempStr, STR_SIZE, ',');
		tempWeight = atoi(tempStr);//converts string to int

		infile.getline(tempStr, STR_SIZE, ',');
		tempLength = atof(tempStr);

		infile.getline(tempStr, STR_SIZE, ',');
		tempHeight = atof(tempStr);

		infile.getline(tempNote, STR_SIZE);

		infile.peek();

		
		dinoInfo[countAndIndex] = new DinoInfo(tempName, tempPeriod, tempDate, tempWeight, tempLength, tempHeight, tempNote);

		countAndIndex++;
	}

	return countAndIndex;//returns number of dinos loaded
}

void DinoCollection::listDinos() //list them out - setprecision 2
{
	cout << endl;
	cout << setw(15) << left << "Name" << setw(14) << left << "Period" << setw(7) << right << "Appeared" << setw(9) << right << "Weight" << setw(9) << right << "Length" << setw(9) << right << "Height" << "    " << "Notes" << endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < countAndIndex; i++)
	{
		cout << setw(15) << left <<  dinoInfo[i]->getName() << setw(12) << left << dinoInfo[i]->getPeriod() << setw(8) << right << fixed << showpoint << setprecision(2) << dinoInfo[i]->getAppearDate() << setw(9) << right  << dinoInfo[i]->getAvgWeight() << setw(9) << right << dinoInfo[i]->getAvgLength() << setw(9) << right  << dinoInfo[i]->getAvgHeight() << "     "  << dinoInfo[i]->getNote() << endl;
	}
}

bool DinoCollection::searchDino() //will search for dinos
{
	int i;
	char findDino[STR_SIZE];
	cout << "Please enter the name of dinosaur you're looking for" << endl;
	cin.getline(findDino, STR_SIZE, '\n' );
	
	for (i = 0; i < countAndIndex; i++)
	{
		if(strcmp(findDino,dinoInfo[i]->getName()) == 0)//comparing
		{
			check = true;//check was intilized to be false in constructor
			cout << "*****DINO FOUND*****" << endl;
			cout << "information about " << dinoInfo[i]->getName() <<  "is as follows: " << endl;
			cout << "Period:  " << dinoInfo[i]->getPeriod() << endl;
			cout << "First Apear: " << dinoInfo[i]->getAppearDate() << endl;
			cout << "Weight: "  << dinoInfo[i]->getAvgWeight() << endl;
			cout << "Length:  " << dinoInfo[i]->getAvgLength() << endl;
			cout << "Height: " << dinoInfo[i]->getAvgHeight() << endl;
			cout << "notes:  " << dinoInfo[i]->getNote() << endl;
			break; 
		}
	}
	//if dino not found check remains false <-- as in constructor
	return check;
}

void DinoCollection::addADino() 
{
	char tempName[STR_SIZE], tempPeriod[STR_SIZE], tempNote[STR_SIZE], tempStr[STR_SIZE];
	double tempDate, tempLength, tempHeight;
	int tempWeight;
	

	
	if (countAndIndex > ARRAY_SIZE)//check for out of bounds
	{
		cout << "Out of Room :( " << endl;
	}
	
	cout << "What is the name of the dinosaur" << endl;
	cin.getline(tempName, STR_SIZE, '\n');
	
	cout << "In what period did the dinosaur live in? " << endl;
	cin.getline(tempPeriod, STR_SIZE, '\n' );

	cout << "How many million years ago did the dinosaur first apear?" << endl;
	cin >> tempDate;
	while(cin.fail()|| tempDate <= 0 || tempDate < 66 || tempDate > 245)//dino apeared between 66 and 245
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter how many million years ago dinosaur first appeared between 66 and 245" << endl;
		cin >> tempDate;

	}
	
	cout << "How much on avg did the Dinosaur weigh?" << endl;
	cin >> tempWeight;
	while(cin.fail()|| tempWeight <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n' );
		cout << "Please re enter the wight " << endl;
		cin >> tempWeight;
	}

	cout << "How long was the diosaur?" << endl;
	cin >> tempLength;
	while(cin.fail()|| tempLength <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the length of the dinosaur" << endl;
		cin >> tempLength;
	}

	cout << "How tall was the dinosaur?" << endl;
	cin >> tempHeight;
	while(cin.fail()|| tempHeight <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the height of the dinosaur" << endl;	
		cin >> tempHeight;
	}
	
	cout << "Any special notes about the dinosaur?" << endl;
	cin.ignore(STR_SIZE, '\n' );//using cin.ignore as extraction(>>) causes problem when used before cin.getline
	cin.getline(tempNote, STR_SIZE, '\n' );
	
	dinoInfo[countAndIndex] = new DinoInfo(tempName, tempPeriod, tempDate, tempWeight, tempLength, tempHeight, tempNote);

	countAndIndex++; 
}

void DinoCollection::writeDinos()//writing to file setprecision 2
{
	outfile.open(fileName);
	for(int i = 0; i < countAndIndex; i++)
	{
		outfile << dinoInfo[i]->getName() << "," << dinoInfo[i]->getPeriod() << "," << fixed << showpoint << setprecision(2) << dinoInfo[i]->getAppearDate() << "," << dinoInfo[i]-> getAvgWeight() << "," << dinoInfo[i]->getAvgLength() << "," << dinoInfo[i]->getAvgHeight() << "," << dinoInfo[i]->getNote() << endl;//outfile -> wrting to file defined as ofstream
	}
	outfile.close();//closing file
}

