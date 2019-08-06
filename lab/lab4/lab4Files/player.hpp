// Header file for lab 4.
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int STR_SIZE = 100;

class PlayerType {
    char name[STR_SIZE];
    char team[STR_SIZE];
    double avg;
    int year;
    public:
    void print() const; // Already implemented in player.cpp.
    // Implement the following functions in player.cpp
    PlayerType(const char nameArg[], const char teamArg[], double avgArg, int yearArg);
    bool higherAvg(const PlayerType & otherPlayer) const;
    bool moreTime(const PlayerType & otherPlayer) const;
};
#endif
