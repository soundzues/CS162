//Adit Kotharii (Adi Kothari)
//Project5
//Source: project 5 stratagies

#ifndef _HEADER_
#define _HEADER_

#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cctype>

using namespace std;

const int STR_SIZE = 256;
const int ARRAY_SIZE = 256;

class DinoInfo{
	char *name;//char pointers
	char *period;
	double appearDate;
	int avgWeight;
	double avgLength;
	double avgHeight;
	char *note;
	public:
	DinoInfo();//default constructor 
//	DinoInfo(char [], char[], double, int, double, double, char[]);//parametrized constructor
	~DinoInfo(); // destructor
	const char *getName();//accessors making them pointers because it returns a char pointer (please correct me if I am wrong)
	const char *getPeriod();//const will make sure nothing can be modified inside the member function
	const double getAppearDate();
	const int getAvgWeight();
	const double getAvgLength();
	const double getAvgHeight();
	const char *getNote();

		
	void setName(char[]);	
	void setPeriod(char[]);	
	void setAppearDate(double ad);	
	void setAvgWeight(int aw);	
	void setAvgLength(double al);	
	void setAvgHeight(double ah);	
	void setNote(char[]);	

	DinoInfo &operator=(const DinoInfo &otherDino);
}; 

struct node
{
	DinoInfo dino;
	node *next;
};

class DinoCollection{
	node *head;
	node *tail;
	int count;
	char fileName[STR_SIZE];
	int flag;//to notify me if the file is open or closed
	bool check;

	public:
	ifstream infile;//read file
	ofstream outfile;//write file
	DinoCollection();//constructor
	int loadDinos();
	void writeDinos();
	void addADino();
	bool removeDino();
	bool searchDino();
	void listDinos();
	void getFileName();
	const int getFlag();
	~DinoCollection();//destructor
};

#endif

