#include "part.hpp"
#include <iostream>
using namespace std;

int main() {
    Part p1("widget", 10); // Constructor with arguments.
    Part p4("widget", 5);
    Part p2("cogs", 10);
    Part p3;
    p3 = p4 + ++p1;
    cout << p1 << p2 << p3 << endl;
    return 0;
}
