#include <iostream>
#include <iomanip>

using namespace std;

const int cap = 15;
int main()
{
	int newInt = 0;
	int pos = 0;
	int size = 10;
	int list[cap]= {3,4,5,6,11,23};  
//	int newInt = 7
//	int pos = 2;

	cout << "enter number you want to insret" << endl;
	cin >> newInt;
	
	cout << "enter the position you want to enter it into" << endl;
	cin >> pos;

//inserting a number in random postion
	size++; //increasing size by 1 making room for last index to be moved into
 	for(int  j = size-1 ; j >= pos ; j--) //size-1, index starts at last position; untill its bigger than or equal to position you want to insert; j goes on decrescing untill it hits pos
	{
//		int temp = size - j;
//		cout << temp << endl;
		list[j] = list[j-1];//coppying value in second last index in the last index
//		list[j+1] = list[j];	//same as above
	}
	list[pos] = newInt;//inserting


	
	for(int i = 0; i < size; i++) //listing
	{
		cout << list[i] << endl;
	}


}
