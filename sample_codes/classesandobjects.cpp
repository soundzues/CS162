#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//class is collection of a fixed number of components, that are called members
//members variables, functions - prototypes - can be acessed- objectName.memberName
//three members of a class - private - only class, public -outside class and protected
//no arethmetic operations are permited on classes

class clockType{ //creating a class datatype - clockType
	public:
		void setTime(int, int, int); //member function gets the prototype
		void printTime();
		bool equaltine(const clockType&) const;
	private:
		int hr;
		int min;
		int sec;
		void testprivate(); //won't be able to acess this in main function using myClock.testprivate()
//myclock.hr = 10 --> is illegeal since hr is prive and can only be accessed through a member function setTime			
};

int main()
{
	clockType myClock; //creating  an object - a class variable - myclock - classobject
	clockType yourClock;
	
	myClock.setTime(5,2,30); //only acess public members - classobjectname.membername
//  myClock.hr //is ilegal since hr is private
//	myClock = yourClock; //youClock.hr = myClock.hr .... so on for min and sec
	myClock.printTime();
}

void clockType::setTime(int a, int b, int c) //:: is the cope resolution operator 
//void className::memberFunctionName(formal parameters) *its okay if formal and actual dont match
{ 
	hr = a;
	min = b;
	sec = c;
}

void clockType::printTime()
{
	cout << "hours: " << hr << endl;
	cout << "mins: " << min << endl;
	cout << "sec: "  << sec << endl;
}
