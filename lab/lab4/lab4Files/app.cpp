// Lab 4 app.cpp, Summer '18
// This is the driver for the member functions in the PlayerType class.
#include "player.hpp"
using namespace std;

int main() {
	PlayerType player1("Mookie Betts", "Boston Red Socks", 0.352, 4); // Testing your constructor with arguments.
	PlayerType player2("Nick Markakis", "Atlanta Braves", 0.322, 12);

	player1.print();
	player2.print();

	if(player1.higherAvg(player2)) {  // Testing your isWinner code.
		cout << "Great job on higherAvg code!" << endl;
	} else {
		cout << "Hmm, higherAvg code is not quite right." << endl;
	}

	if(player2.moreTime(player1)) {  // Testing your higherStanding code.
		cout << "Great job on moreTime code!" << endl;
	} else {
		cout << "Hmm, your moreTime code is not quite right." << endl;
	}

	return 0;
}
