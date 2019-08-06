#include "header.hpp"
#include <iostream>
#include <cstring>//cstring was missing

using namespace std;

double getAvg()
{
    double finalAvg;

    cout << "Please enter your final average: ";
    cin >> finalAvg;
    while(!cin)
    {
        cin.clear();
        cin.ignore(MAX_CHAR, '\n');
        cout << "input has to be numerical!" << endl;
        cin >> finalAvg;
    }
    cin.ignore(MAX_CHAR, '\n');
    return finalAvg;
}

char determinGrade(double finalAvg)
{
    char grade = 'F';//deleted g	
    if (finalAvg >=  MIN_A)
    {
         grade = 'A';	
    }
    else if(finalAvg >= MIN_B)
    {
        grade = 'B';
    } 
    else if (finalAvg >=  MIN_C) //removed semicolon
    {
         grade = 'C';
    }
    return grade;
}

void printMsg(char grade)
{
    char msg[MAX_CHAR];
    switch(grade)
    {
        case 'A':
            strcpy(msg, "A, Excellent!");
	    break;//break was missing
        case 'B':
            strcpy(msg, "B, Good job!");
            break;
        case 'C':
            strcpy(msg, "C, You've passed!");
	    break; //break was missing
        default:
            strcpy(msg, "No pass, time to study!");
            break;
    }
    cout << msg << endl;
}

