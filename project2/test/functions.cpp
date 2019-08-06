// CS162 Midterm Proficiency
// array.cpp, function definition / implementation file. 

#include "array.hpp"

//put the assigned function definitions here

int findMinEven (int list[], int size) {
    int minEven = CAP + 1;
    cout << minEven << endl;
    for (int i = 0; i < size; i++) {
        if ((list[i] % 2) == 0) {
            if (list[i] < minEven)
                minEven = list[i];
        }
    }
    if (minEven == (CAP + 1)) 
        return 0;
    return minEven;
}

bool deleteIndex (int list[], int index, int & size) {
    if (index >= size || index < 0)
        return false;
    else {
        for (int i = index; i < size; i++) {
            list[i] = list[i + 1];
        }
        size--;
        return true;
    }
}


// *** End of array.cpp ***
