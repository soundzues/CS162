// lab 2 main function.
#include "header.hpp"
#include <iostream>
using namespace std;

int main()
{
    double score;
    char grade;

    score = getAvg();
    grade = determinGrade(score);
    printMsg(grade);

    return 0;
}
