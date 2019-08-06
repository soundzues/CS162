//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here
int findMinEven(int list[], int size) 
{
	int minEven = 128;
	for (int i = 0; i < size; i++)
	{
		if(list[i]%2 == 0)
		{
			if(list[i] < minEven)
			{
				minEven = list[i];
			}
		}
	}
	return minEven;

}

bool deleteIndex(int list[], int & size, int &index) 
{
	if(index < 0 || index >= size)
	{
		return false;
	}
	else
	{
		for (int i = index; i < size; i++)
		{
			list[i] = list[i+1];
		}
	size--;
 	return true;
	}

}

// *** End of array.cpp ***
