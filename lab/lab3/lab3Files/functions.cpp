//Adit Kotharii (adi kothari)
//lab3



// This is the functions file for lab3.
// Implement the functions listed.
#include "header.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
// addAMovie().
// This function will add a new item to myCart.
// The item has a name, count (how many), and a price, in that order, passed in.
// Use the shoppingCart member called totalItems to place the new item in the array.
// NOTE: Because you don't know the size of name, use strncpy() to copy name to itemName.
// Remember to explicitly null terminate the movieName c-string.
void addAnItem(shoppingCart & myCart, const char name[], int count, double price) {
	
	if(myCart.totalItems < LIST_SIZE )
	{
		strncpy(myCart.itemList[myCart.totalItems].itemName, name, STR_SIZE);
		myCart.itemList[myCart.totalItems].count = count;
		myCart.itemList[myCart.totalItems].price = price; 
		myCart.totalItems++;
	}	
	else
	{
		cout << "The list is full" << endl;
	}
}


// listMovies().
// Place the code here to print the movies list in movies.
void listItems(const shoppingCart & myCart){
	for (int i = 0; i < myCart.totalItems; i++)
	{
		cout <<	 myCart.itemList[i].itemName << " " <<  myCart.itemList[i].count << ", "<<  myCart.itemList[i].price << endl; 

	}
}
