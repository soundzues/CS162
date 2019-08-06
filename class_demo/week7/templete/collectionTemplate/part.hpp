// Header file for operator overloading example.
// CS162 Summer '18, PCC

#ifndef __PART__
#define __PART__

#include <cstring>
#include <iostream>
using namespace std;

const int STR_SIZE = 200;

class Part {
    char name[STR_SIZE];
    int count;
    public:
    Part();
    Part(const char [], int);
    int getCount() const;
    const char * getName() const;
    void setCount(int);
    void setName(const char []);
    //friend Part operator+(Part &, Part &);
    Part operator+(const Part &) const;
    friend ostream& operator<<(ostream & out, Part & p);
    Part operator++(); // pre-increment (no args).
    Part operator++(int); // post-increment (dummy arg).
    bool operator==(Part &);
};

#endif
