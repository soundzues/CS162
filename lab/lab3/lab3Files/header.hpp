// CS162, Spring '18
// Lab 3 Header file.

#ifndef __INVENTORY__
#define __INVENTORY__

const int STR_SIZE = 128;
const int LIST_SIZE = 100;
const bool SUCCESS = true;

// This struct can contain the information about one movie.
struct itemType {
    char itemName[STR_SIZE];
    int count;
    double price;
};

// This struct contains an array of movieType structs.
// It also contains the total movies contained in the array.
// When the program starts, totalMovies will be set to zero.
// Use totalMovies to keep track of the current index.
struct shoppingCart {
    itemType itemList[LIST_SIZE];
    int totalItems;
};

// Prototypes
// TO-DO: Implement these two functions in the functions.cpp file.
void addAnItem(shoppingCart &, const char name[], int count, double price);
void listItems(const shoppingCart &);

#endif

