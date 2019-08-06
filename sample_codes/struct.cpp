#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//struct: collection of components, each of different type, accessed by names


const int SIZE = 128;

struct infoType{ //struct defines a datatype - info, no memory allocated. creates new data type called infoType which can be used to declare variables
	char name[SIZE];
	char major[SIZE];
	int iq;
	double gpa;
	
}; //struct ends with semi colon

struct famInfoType{
	char momname[SIZE]; 
	char fathername[SIZE];
	int numberfam;
	double famsal;
};

struct person{ //struct inside a struct;
	infoType personalInfo;
	famInfoType famInfo;
}; 

//& used to define it as pass by reference value
int struct_function(infoType &basic, infoType &morebasic) //you use datatype varname ---> infotpe (data type created using struct) varname
{

	//assigning components values and stuff.. individually, no aggregate I/P O/P allowed
	strcpy(basic.name, "Adit Kotharii"); //basic.name = Adit Kotharii wont work, only str.cpy works
	strcpy(basic.major, "Electrical and Computer Engineering");
	basic.gpa = 3.6;
	basic.iq =  129;
	
	//if you want to print them out do so individually
	cout << basic.name << endl;
	cout << basic.major << endl;
	cout << basic.gpa << endl;
	cout << basic.iq << endl;
	
	//assigning one struct to another is straight forward: dont need to do it individiually component wise.
	basic = morebasic;
	
}

int structinArray(infoType structArray[])
{
	for (int i = 0; i < 3; i++) //i acts as a counter
	{
	  cout << "please enter name:" << endl;
	  cin.ignore();
	  cin.getline(structArray[i].name, SIZE, '\n' );
	  
	  cout << "please enter your major" << endl;
	  cin.getline(structArray[i].major, SIZE, '\n');
	  
	  cout << "please enter you gpa" << endl;
	  cin >> structArray[i].gpa;
	  
	  cout << "please enter your iq" << endl;
	  cin >> structArray[i].iq;
	}
	
}

int printstructArray(infoType structArray[])
{
	for(int i = 0; i < 3; i++) //churns stuff out of the array
	{
		cout << structArray[i].name << endl;
		cout << structArray[i].major << endl;
		cout << structArray[i].gpa << endl;
		cout << structArray[i].iq << endl;		
	}	
}

int main()
{
	infoType basic; //declares a stuct variable basic of infotype
	infoType morebasic;
	infoType structArray[3];
	int counter = 0;
	
//	struct_function(basic, morebasic);
	
//	structinArray(structArray);
//	printstructArray(structArray);

	strcpy(person.famInfo.fathername,"adit");
	person.personalInfo.iq = 140;
	cout << person.famInfo.fathername << endl;
	cout << person.personalInfo.iq << endl; //always start with struct name
	
	return 0;
}
