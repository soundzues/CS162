#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

//ofstream to write the file
//ifstream to write the file
int iomanip()
{
	cout << fixed << showpoint << setprecision(3) << endl; //allows only 3 decimal places
	cout << setw(10); //sets width
	cout << 26.2221; //shows only 3 	
	//how to get rid of precion and width?
}

int writefile()
{
	ofstream outfile; //ofstream is used to create outfile, which will be used to create files
	outfile.open("sample.txt"); //could use get line to ge a file name, outfile.open("file name.txt")
	if(outfile.is_open())//.is_open checks if the file is open
	{
		outfile << "hello world" << endl; //using outfile insted of cout "<<" <---- operator very imp
		outfile << "wrting to file" << endl;
		outfile.close(); //always close the file that you open
	}
	else
	{
		cout << "unable to open the file" << endl;
	}
}

int readfile_numbers()
{
	int x,y;
	char line[128];
	ifstream infile; //ifstream to read, create infile
	infile.open("numbers.txt");//open the file
	if(infile.is_open())
	{
		infile >> x >> y;//any opertion you do on file, do it with infile, DO NOT USE CIN,">>" <---- IMP TO EXTRACT STUFF
		cout << x << endl;
		cout << y << endl;
		infile.close(); //always closee the file
	}

	else 
	{
		cout << "unable to open the file" << endl;
	}
}

int readfile_strings()
{
	string array[5];
	int count;
	ifstream infile;
	infile.open("sample.txt");
	
	if(!infile.is_open())
	{
		cout << "unable to open file" << endl;
	}
	
	while(!infile.eof())
	{
		infile >> array[count]; // >> <-- use extractor to get stuff from the files and not getline
		count++;
	}
	cout << "read sucessfully" << endl;
}

int main()
{
//	iomanip();
//	writefile();
//	readfile_numbers();
	readfile_strings();
	return 0;
}
