// CS162 Midterm Proficiency
// array.cpp, function definition / implementation file. 

#include "array.hpp"

//put the assigned function definitions here

int addMinMax(int list[], int size)
{
	int max = list[0];
	int min = list[0];
	for(int i = 0; i < size; i++)
	{
		if (list[i] < min)
		{
			min = list[i];
		}
		if (list[i] > max)
		{
			max = list[i];
		}
	}
//	cout << min << endl;
//	cout << max << endl;
	return min+max;
}

int moveToFirst(int list[], int val, int size)
{	
	int temp;
	int i;
	int valIndex = 0;
	for ( i = 0; i < size; i++)
	{
		if(val == list[i])
		{
		//	cout << "number found" << endl;
			valIndex = i;
//			cout << valIndex << endl;
		}
			
	}
        if(valIndex == 0)	
	{
		cout << "number not found" << endl;
		return false;
	}

    
	for (int j = 0; j < size; j++)
	{
		
		list[j] = list[j+1];
	//	cout << list[j] << endl;
	}
	
	list[0] = val;
	return true;
}


		
	


// *** End of array.cpp ***
