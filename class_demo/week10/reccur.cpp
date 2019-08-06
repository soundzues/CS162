#include<iostream>
using namespace std;

long fact(long factNum)//reccursive function calls itself
{
	if(factNum == 1) //base case
	{
		return 1;
	}
	else //reccursive case
	{
		return fact(factNum-1)*factNum;
	}
}

int main()
{
	long number, result;
	cout << "what number would you like the factiruak for? " << endl;
	cin >> number;
	result = fact(number);
	cout << result << endl;
	return 0;
	
}
