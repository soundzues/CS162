#include <iostream>
using namespace std;


/* To not define a type again and again we use a template
bool addThem(int num1, int num2,int num3 = 0)//arguments => Signature
{
	return num1 + num2 + num3 ;
}

 

bool addThem(double num1, double num2,double num3 = 0)//arguments => Signature
{
	return num1 + num2 + num3 ;
}
*/

template <class Type> //cannot be precompiled into a object file should be in the same file 
bool isBigger(Type first, Type second)
{
	return first > second;
}

int main()
{
	bool result;
	result = isBigger(4.0, 2.5);
	result = isBigger('a','c');
	result = isBigger(3.0,4.0); 


	return 0;	
}
