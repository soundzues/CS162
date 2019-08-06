#include <iostream>
#include <iomanip>
#include <cstring> //use include< cstring

using namespace std;

//cstring always termineted by the null chcaracter '\0', 'hello' is repesented by 6 charcters
//>> does not work with cstrings as it stops inputing once it encounters a white space
int cstring_inbuilt (char myname[], int len)
{
	strcpy(myname, "adit kotharii"); //strcpy(s1,s2) coppies s2 in s1
	cout << myname << endl;
	
	len = strlen(myname);//strlen(s) gives you the length including white space as well
	cout << len << endl;
	
	int cmp = strcmp("adit","aditya"); //returns 0 if equal, value < -0 - if s2 is bigger, value > 0 - if s1 is bigger
	cout << cmp << endl;	
}

int input(char myname[], int len)
{
	char yourname[16];
/* using >> before getline causes problems, therfore as arule of thumb always use cin.ignore(size, delim('\n'))while inputing cstrings
	cout << "enter a number" << endl;
	cin >> len;
	cout << len << endl;
	
	cout << "enter your name" << endl;
	cin.getline(myname, 16, '\n'); //cin.getline(string, size, delim)
	cout << myname << endl;
 fix:- */

	cout << "enter a number" << endl;
	cin >> len;
	cout << len << endl;
	
	cout << "enter your name" << endl;
	cin.ignore();
	cin.getline(myname, 16, '\n'); //cin.getline(string, size, delim)
	cout << myname << endl;

	cout << "enter a name" << endl;
//	cin.ignore(); //putting cin.ingore() here will cause problems therfore use it right after you use cin >> the extractor
	cin.getline(yourname, 16, '\n');
	cout << yourname << endl;

}


int main()
{
	char myname[16];
	int len;

//	cstring_inbuilt(myname, len);
	input(myname, len);
	
	return 0;
}
