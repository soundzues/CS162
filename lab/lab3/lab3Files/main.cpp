// CS162 Spring '18, main function for Lab 3
// This is a simple program to keep track of movies.
#include "header.hpp"
#include <iostream>
#include <iomanip>

int main() {
    shoppingCart myCart;
    myCart.totalItems = 0;

    addAnItem(myCart, "Bread, loaf", 2, 2.98);
    addAnItem(myCart, "Eggs, carton", 1, 3.97);
    addAnItem(myCart, "Milk, gallon", 2, 4.50);
    addAnItem(myCart, "Dish Soap, liquid", 1, 5.65);
    addAnItem(myCart, "Bananas, pound", 2 ,0.79);
    addAnItem(myCart, "Apples, each" ,5, .97);

    std::cout << "The items in the cart are:\n";
    if(myCart.totalItems > 0)
        listItems(myCart);
    else
        std::cout << "There are no items in the cart." << std::endl;
    return 0;
}
