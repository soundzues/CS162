// Implementation file for the Part class.
// CS162 Summer '18, PCC

#include "part.hpp"

Part::Part() {
    name[0] = '\0';
    count = 0;
}

Part::Part(const char nameArg[], int num) {
    strncpy(name, nameArg, STR_SIZE);
    name[STR_SIZE - 1] = '\0';
    count = num;
}
        

const char * Part::getName() const {
    return name;
}

int Part::getCount() const {
    return count;
}

void Part::setName(const char nameArg[]) {
    strncpy(name, nameArg, STR_SIZE);
    name[STR_SIZE - 1] = '\0';
}

void Part::setCount(int num) {
    if(num > 0) {
        count += num;
    }
}

bool Part::operator==(Part & otherPart) {
    bool isEqual = false;
    if(strcmp(otherPart.name, name)  == 0) {
        isEqual = true;
    }
    return isEqual;
}

/*Part operator+(Part & p1, Part & p2) {
    Part retPart;
    retPart.count = p1.count + p2.count;
    strcpy(retPart.name, p1.name);
    return retPart;
}*/

Part Part::operator+(const Part & otherPart) const {
    Part retPart;
    strcpy(retPart.name, name);
    retPart.count = count + otherPart.count;
    return retPart;
}

ostream& operator<<(ostream & out, Part & p) {
    out << p.name << ": " << p.count << endl;
    return out;
}

Part Part::operator++() {
    count++;
    return *this;
}

Part Part::operator++(int u) {
    Part temp = *this; // snapshot. p1++; temp = p1;
    count++;
    return temp;
}



