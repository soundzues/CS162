
#include "header.hpp"

int main() {
    List groceries; // instance, or an object
    List inventory;
    //inventory = groceries;  // Aggregate copy example.

    char choice;
    do {
        cout << "What would you like to do, (a)dd, (p)rint, or (q)uit: ";
        cin.get(choice);
        cin.ignore(); // get rid of the newline.
        switch(choice)
        {
            case 'a':
                groceries.addAnItem();
                break;
            case 'p':
                groceries.printTheList();
                break;
            case 'q':
                cout << "Program finished.";
                break;
            default:
                cout << "Not a valid choice." << endl;
        }
    }while(choice != 'q');
    
    return 0;
}

