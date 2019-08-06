#include "header.hpp"
#include <iostream>
#include "cstring"
#include "string.h"
#include "stdlib.h"
using namespace std;

DinoCollection::DinoCollection()//default dinoCollection constructor
{
	tail = NULL;
	head = NULL;
	count = 0;
	flag = 0;
	check = false;//pessmestic 
}
/*
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
	
}*/

DinoInfo::DinoInfo()
{
	appearDate = 0;
	avgWeight = 0;
	avgLength = 0;
	avgHeight = 0;
}


DinoInfo::~DinoInfo()//destructor to free memory 
{
	delete []name;
	delete []period;
	delete []note;
}

/*
DinoInfo &DinoInfo:: operator=(const DinoInfo &otherDino)
{
	if(name != NULL)//need to set aside memory for c-string. need to check if c-string been already alocated if so need to deelte it. do same for period and note.
	{
		delte []name;
	}	
	strcpy(name, otherDino.name);
	strcpy(period,otherDino.period);
	strcpy(note, otherDino.note);
	
	avgWeight = otherDino.avgWeight;
	appearDate = otherDino.appearDate;
	avgLength = otherDino.avgLength;
	avgHeight = otherDino.avgHeight;
	return *this;
}*/

DinoCollection::~DinoCollection()
{
	node *cur;
	cur = head;
	while(cur != NULL)
	{
		cur = head->next;
		delete cur;
		head = cur;
	}
}



void DinoInfo::setName(char tempName[])
{
	name = new char[strlen(tempName) + 1]; //+1 for null pointer
	strcpy(name, tempName); //coppying n into name
}


void DinoInfo::setPeriod(char tempPeriod[])
{
	period = new char[strlen(tempPeriod) + 1]; //+1 for null pointer
	strcpy(period, tempPeriod); //coppying n into name
}


void DinoInfo::setNote(char tempNote[])
{
	note = new char[strlen(tempNote) + 1]; //+1 for null pointer
	strcpy(note, tempNote); //coppying n into name
}

void DinoInfo::setAppearDate(double ad)
{
	appearDate = ad;
}

void DinoInfo::setAvgWeight(int aw)
{
	avgWeight = aw;
}
void DinoInfo::setAvgLength(double al)
{
	avgLength = al;
}
void DinoInfo::setAvgHeight(double ah)
{
	avgHeight = ah;
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
{	
	node *temp, *prev, *cur;
	//temp variables will be passed as actual parameters to the constructor
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
		
		temp = new node;
		temp->next = NULL;

		temp->dino.setName(tempName);		
		temp->dino.setPeriod(tempPeriod);
		temp->dino.setAppearDate(tempDate);
		temp->dino.setAvgWeight(tempWeight);
		temp->dino.setAvgLength(tempLength);
		temp->dino.setAvgHeight(tempHeight);
		temp->dino.setNote(tempNote);
		
		if (head == NULL) //list is empty
		{
            		head = temp;
            		tail = temp;  
        	}
        	else 
		{ 
            		if (strcmp(temp->dino.getName(), head->dino.getName()) <  0)
			{
                		temp->next = head;
                		head = temp;
            		}
            		else//sort 
			{
                		prev = head;
                		cur =  head->next;
                		while (cur != NULL) 
				{
                    			if (strcmp(prev->dino.getName(),temp->dino.getName()) < 0 && strcmp(cur->dino.getName(),temp->dino.getName()) >0) 
					{
                        			prev->next = temp;
                        			temp->next = cur;
                        			break;
                    			} 
					else 
					{
                        			prev = cur;
                        			cur = cur->next;
                    			}
                		}
                		if (cur == NULL) 
				{
                    			prev->next = temp;
                   			 tail = temp;
                		}
            		}
        	}
        	this->count = this->count + 1;		
		infile.peek();
	}
	return this->count;
}

void DinoCollection::listDinos() //list them out - setprecision 2
{
	node *cur;
	cur = head;

	cout << endl;
	cout << setw(15) << left << "Name" << setw(14) << left << "Period" << setw(7) << right << "Appeared" << setw(9) << right << "Weight" << setw(9) << right << "Length" << setw(9) << right << "Height" << "    " << "Notes" << endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < this->count; i++)
	{
		cout << setw(15) << left <<  cur->dino.getName() << setw(12) << left << cur->dino.getPeriod() << setw(8) << right << fixed << showpoint << setprecision(2) << cur->dino.getAppearDate() << setw(9) << right  << cur->dino.getAvgWeight() << setw(9) << right << cur->dino.getAvgLength() << setw(9) << right  << cur->dino.getAvgHeight() << "     "  << cur->dino.getNote() << endl;
		cur = cur->next;
	}
}

bool DinoCollection::searchDino() //will search for dinos
{
	check = false;
	int i;
	node *cur;
	cur = head;
	char findDino[STR_SIZE];
	cout << "Please enter the name of dinosaur you're looking for" << endl;
	cin.getline(findDino, STR_SIZE, '\n' );
	
	for (i = 0; i < this->count; i++)
	{
		if(strcmp(findDino,cur->dino.getName()) == 0)//comparing
		{
			check = true;//check was intilized to be false in constructor
			cout << "*****DINO FOUND*****" << endl;
			cout << "information about " << cur->dino.getName() <<  " is as follows: " << endl;
			cout << "Period:  " << cur->dino.getPeriod() << endl;
			cout << "First Apear: " << cur->dino.getAppearDate() << endl;
			cout << "Weight: "  << cur->dino.getAvgWeight() << endl;
			cout << "Length:  " << cur->dino.getAvgLength() << endl;
			cout << "Height: " << cur->dino.getAvgHeight() << endl;
			cout << "notes:  " << cur->dino.getNote() << endl;
			break; 
		}
		else
		{
			cur = cur->next;
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

	node *temp, *cur, *prev;

	temp = new node;
	temp->next = NULL;
	
	cur = head;
	prev =  NULL;		

	
	
	cout << "What is the name of the dinosaur" << endl;
	cin.getline(tempName, STR_SIZE, '\n');
	temp->dino.setName(tempName);
	
	cout << "In what period did the dinosaur live in? " << endl;
	cin.getline(tempPeriod, STR_SIZE, '\n' );
	temp->dino.setPeriod(tempPeriod);

	cout << "How many million years ago did the dinosaur first apear?" << endl;
	cin >> tempDate;
	while(cin.fail()|| tempDate <= 0 || tempDate < 66 || tempDate > 245)//dino apeared between 66 and 245
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter how many million years ago dinosaur first appeared between 66 and 245" << endl;
		cin >> tempDate;

	}
	temp->dino.setAppearDate(tempDate);	

	cout << "How much on avg did the Dinosaur weigh?" << endl;
	cin >> tempWeight;
	while(cin.fail()|| tempWeight <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n' );
		cout << "Please re enter the wight " << endl;
		cin >> tempWeight;
	}
	temp->dino.setAvgWeight(tempWeight);

	cout << "How long was the diosaur?" << endl;
	cin >> tempLength;
	while(cin.fail()|| tempLength <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the length of the dinosaur" << endl;
		cin >> tempLength;
	}
	temp->dino.setAvgLength(tempLength);

	cout << "How tall was the dinosaur?" << endl;
	cin >> tempHeight;
	while(cin.fail()|| tempHeight <= 0)
	{
		cin.clear();
		cin.ignore(STR_SIZE, '\n');
		cout << "Please re enter the height of the dinosaur" << endl;	
		cin >> tempHeight;
	}
	temp->dino.setAvgHeight(tempHeight);
	
	cout << "Any special notes about the dinosaur?" << endl;
	cin.ignore(STR_SIZE, '\n' );//using cin.ignore as extraction(>>) causes problem when used before cin.getline
	cin.getline(tempNote, STR_SIZE, '\n');
	temp->dino.setNote(tempNote);
	
	if (head == NULL) 
	{
        	head = temp;
        	tail = temp;  
    	}
    	else 
	{ 
        	if (strcmp(temp->dino.getName(), head->dino.getName()) <  0) 
		{
            		temp->next = head;
            		head = temp;
		}
        	else 
		{
            		prev = head;
            		cur =  head->next;
		}
            	while (cur != NULL) 
		{
                	if (strcmp(prev->dino.getName(),temp->dino.getName()) < 0 && strcmp(cur->dino.getName(),temp->dino.getName()) >0) 
			{
                    		prev->next = temp;
                    		temp->next = cur;
                    		break;
                	} 
			else 
			{
                    		prev = cur;
                    		cur = cur->next;
                	}
            	}
            	if (cur == NULL) 
		{
                	prev->next = temp;
                	tail = temp;
            	}		
        }
    this->count = this->count + 1;
}

bool DinoCollection::removeDino()
{
	check = false;
	
	node *cur, *prev;
	cur = head;
	prev = NULL;
		
	char findDino[STR_SIZE];
	cout << "Please enter the name of dinosaur you're looking for" << endl;
	cin.getline(findDino, STR_SIZE, '\n' );

	while (cur != NULL) //cur == NULL end of the list
	{  
        	if(strcmp(findDino, cur->dino.getName()) == 0)//found 
		{
		       check = true;//dino found and would be deleted
     		       break;
        	} 
		else //traverse through the list
		{
            		prev = cur;
            		cur = cur->next;
        	}
    	}
	if(cur == NULL)//DINO NOT FOUND
	{
		return check;
	}
	else//if dino found
	{
		if(cur == head)//dino at the head of the list
		{
			head = cur->next;
			delete cur;
		//	cur = head;
		}
		else
		{
			prev->next = cur->next;
			delete cur;
		}
		this->count = this->count - 1;
	}
	return check;
}

void DinoCollection::writeDinos()//writing to file setprecision 2
{
	node *cur;
	cur = head;
	
	outfile.open(fileName);
	for(int i = 0; i < this->count; i++)
	{
		outfile << cur->dino.getName() << "," << cur->dino.getPeriod() << "," << fixed << showpoint << setprecision(2) << cur->dino.getAppearDate() << "," << cur->dino.getAvgWeight() << "," << cur->dino.getAvgLength() << "," << cur->dino.getAvgHeight() << "," << cur->dino.getNote() << endl;//outfile -> wrting to file defined as ofstream
	
	cur = cur->next;
	}
	outfile.close();//closing file
}


