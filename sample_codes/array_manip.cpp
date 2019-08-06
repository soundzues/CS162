#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int array_basic(int a[])
{
	a[3] = 5; //sets the 3rd index, 4th spot in array to 5, manualy adding data data
	cout << a[3] << endl;
}

void array_add(int b[])
{
	for (int i = 0; i < 10; i++)
	{
		b[i] = i*2;
	}
	
}

int array_print(int b[])
{
	for (int i = 0; i < 10; i++) //i = index, 10 = number of elements
	{
		cout << b[i] << endl;
	}
}

int largest_element(int b[])
{
	int largest = 0;
	int maxindex = 0;
	for (int i = 0; i < 10; i++)
	{
		if(b[maxindex] < b [i]) //b[0] !< b[0], b[0] < b[1]
		{
			maxindex = i; //changes max index to that of the largest number
			largest = b[maxindex]; // pulls out the largest number
			
		}
	}
	cout << "The largest = " << largest << endl; // prints
}

int copy_array(int b[], int c[])
{
	for (int i = 0; i < 10; i++)
	{
		c[i] = b[i];
	}
	//prints the copied array
	for (int j = 0; j < 10; j++)
	{
		cout << c[j] << endl;
	}
}

int sequential_sort(int b[]) //compare the item to every element in the array until, element is found or no items are left
{
	int number, numberFound;
	cout << "what number are you looking for?" << endl;
	cin >> number;
	
	for (int i = 0; i < 10; i++)
	{
		if (number == b[i])
		{
			numberFound = number;
			cout << "number found: " << numberFound << endl;
			break;
		}
	}
}
// can also use selection sort funciton ==> selectionsort(arrayname, search item)

int main()
{	
	int c[10];
	int b[10]; //intilizing an array
//	array_basic(b); //its okay if this and the formal parmeter name dont match, but the data type should
	
//array basic:	cout << "array are pass by reference only: " << a[3] << endl; 


	array_add(b);

/*	
	array_print(b);

	largest_element(b);	
*/ 

//	copy_array(b, c);

	sequential_sort(b);
	
	return 0;
 } 
