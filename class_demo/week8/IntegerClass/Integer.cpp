#include "Integer.hpp"

int Integer::getNumber() {
    return number;
}

void Integer::setNumber(int n) {
    number = n;
}

Integer::Integer(int n) {
    number = n;
}

Integer::Integer() {
    number = 0;
}
