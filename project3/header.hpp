#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

const int STR_SIZE = 256;
const int arraySize = 256;

 struct DinoInfo {//struct
	char name[STR_SIZE];
	char period[STR_SIZE];
	double appearDate;
	int avgWeight;
	double avgLength;
	double avgHeight;
	char note[STR_SIZE];
};

class DinoCollection {//class
	DinoInfo dinoInfo [arraySize];
	int countAndIndex;
	char fileName[STR_SIZE];
	bool check;
	
       public:
	int flag;//notify if file is open or closed in main
	ifstream infile;//read file
	ofstream outfile;//writefile
	DinoCollection();//constructor
	void getFileName();
	int loadDinos();
	void writeDinos();
	void addADino();
	bool searchDinos();
	void listDinos();
}; 

#endif
