//Adit Kotharii (adi kothari)
//Lab 4
// Implementation file for lab
#include "player.hpp"

void PlayerType::print() const {
    cout << "Player Name: " << name << ", Player Team: " << team << ", Batting Average: " << avg << ", Year: " << year << endl;
}

// Place your member function definitions here:
// 1: The constructor.
PlayerType::PlayerType(const char nameArg[], const char teamArg[], double avgArg, int yearArg)
{
	strcpy(name, nameArg);
	strcpy(team, teamArg);
	avg = avgArg;
	year = yearArg;
}
// 2: Function definition for higherAvg.
bool PlayerType::higherAvg(const PlayerType &player2) const
{
	if(avg > player2.avg)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// 3: Function definition for moreTime.
bool PlayerType::moreTime(const PlayerType &player2) const
{
	if(year > player2.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}
