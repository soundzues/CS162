// Header file for CS162 Midterm Proficiency

#ifndef ARRAY_H
#define ARRAY_H

//array.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int CAP = 100;
// These functions are already written and are located in supplied.o
void build(int list[], int size);
void display(int list[], int size);

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:
int addMinMax(int list[], int size);
int moveToFirst(int list[], int val, int size);

#endif
