#include <iosream>
using namespace std;

int main()
{
	int grade;
	cout << "what is your grade? "; //int 4 bytes: -2 bil to 2 bil ,  char 1 bytes , short 2 bytes
	cin >> grade;
	
	switch(grade)
	{
		case 4:
			cout << "Great job, you got an A. " << endl;
			break; //its very imp to put break, if you dont it will fallow through 
		case 3:
			cout << "Good job, you got a B. " << endl;
			break;
		default: ; //imp to have defau	lt
	}
	return 0;
}
//its faster to manipulate a byte than a bit
