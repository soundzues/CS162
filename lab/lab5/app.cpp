//Adit Kotharii (Adi Kothari)
//Lab5
// Lab 5 code file. Fill in the code below to complete the lab.
// CS162 Winter '18

#include <iostream>
#include <iomanip>  // Use setw() for proper column output. I used 4.
using namespace std;

const int MAX = 128;

int main()
{
        int rows = 0, cols = 0;
	int ** table; // This is a pointer to a pointer. Use it to create
                      //   a dynamic two-dimensional array.
	
        cout << "How many rows should the table have? ";
        cin >> rows;
        while (rows < 0 || rows > MAX || cin.fail()) {
            cin.clear();
            cin.ignore(MAX, '\n');
            cout << "How many rows should the table have? ";
            cin >> rows;
        }
        cout << "How many columns should the table have? ";
        cin >> cols;
        while (cols < 0 || cols > MAX || cin.fail()) {
            cin.clear();
            cin.ignore(MAX, '\n');
            cout << "How many columns should the table have? ";
            cin >> cols;
        }



	// Write code here to allocate memory for the table
        //   Step 1: Allocate an array of pointers that has rows elements: table = new int*[rows];
	table = new int*[rows]; 
        //   Step 2: Allocate each row to have cols elements, using a loop
        //           that starts at zero and goes up to but not including rows.
	for (int i = 0; i < rows; i++)
	{
		table[i] = new int[cols];
	}
	// Write code here to populate it with required integers
        //   as per the lab assignment document. Use a nested loop
	for (int i = 0; i < rows; i++) 
	{
            	for (int j = 0; j < cols; j++)
		{
            		table[i][j] = rows + i + j;
		}
	}
	// Write code here to print the table. Use a nested loop.
	for (int i = 0; i < rows; i++) 
	{
        	for (int j = 0; j < cols; j++)
		{
            		cout << setw(4) << table[i][j] ;
	
		}
		cout << endl;
	}

	// Write code here to deallocate memory for the table.
        //   Remember to use the array version of delete.
        //   You allocated each row, so now you have to deallocate each rowi, using a loop.
        //   Then deallocate the table pointer itself, also with the array version.
	for(int i = 0; i < rows; i++ )
	{
		delete []table[i];
	} 
        // Run this program in valgrind to make sure there are no leaks.
        // Valgrind command: valgrind --leak-check=full ./lab5app
	delete []table;

	return 0;
}
