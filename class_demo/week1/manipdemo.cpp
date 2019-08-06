#include<iostream>
#include<iomanip>
#include<fstream> //need to write out or use files
using namespace std;

const int SIZE = 128;

int main()
{	
	//	char filename[SIZE]; //char*---> cstring
	//	cin >> filename; do not use this it will cause buffer overflow use getline
	//	cin.getline(filename,SIZE);

	char state1[] = "California", state2[] = "Oregon";//state 2 = 7 due to the null terminator 
	int state1pop = 60000000;
	int state2pop = 300000;

	cout << left << setw(20) << state1 << setw(20) << state1pop << right << endl; //setw is  used to set field width 
	cout << left << setw(20) << state2 << setw(20) << state2pop << right <<  endl;


	//	ofstream outfile;
	//	outfile.open();
	//	cout << fixed << showpoint << setpericion(3);

	//	ifstream infile; //infile and outfile are objects, ifstream - only open for input
	//	ofstream outfile; //ofstream is only for output
	//	cout << stew(20) << "widgets" << setw(15) << "5" << endl; //always have set precion stuff beforehand

}
