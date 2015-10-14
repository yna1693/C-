#include <iostream>
#include <cstdlib>
#include "SpinningWheel.h"
#include "Player.h"

using namespace std;

int main() {
	char answer;		//stores the answer if want to spin again
	int player = 1;		//the index of player
	int play = 0;		//store the number of plays a player plays
	bool again = true;	//spin twice checker
	int result[3];		//array that store the player result

	SpinningWheel spinWheel;	//SpinningWheel object
	Player player1;				//Player object player 1
	Player player2;				//Player object player 2
	Player player3;				//Player objectplayer 3

	cout << "Hello and Welcome to the Game Show!\n" << endl;
	
	//Limit to 3 players only
	while (player < 4) {

		cout << endl << "Player " << player << " Spins this round" << endl;
		//run if when it's the first spin
		if (play == 0) {
			cout << "First Spin:	";
			again = true;
		}
		//run else if when it is the secondspin
		else if (play == 1)
			cout << "SecondSpin:	";

		//output the spin result
		if (player == 1) {
			player1.spin(spinWheel);
			
			//output the over 100 message if the player total points is over 100
			if (player1.totalPoints() > 100) {
				cout << endl << "Your Total Points (" << player1.totalPoints() << ") is over 100." << endl;
				again = false;
			}
			//output normal message for player total points
			else {
				cout << endl << "Player 1 total Points: " << player1.totalPoints() << endl;
			}

			//put the player1 points into the points array called result
			result[player - 1] = player1.totalPoints();
		}

		else if (player == 2) {
			player2.spin(spinWheel);
			if (player2.totalPoints() > 100) {
				//output the over 100 message if the player total points is over 100
				cout << endl << "Your Total Points (" << player2.totalPoints() << ") is over 100." << endl;
				again = false;
			}
			else {
				//output normal message for player total points
				cout << endl << "Player 2 total Points: " << player2.totalPoints() << endl;
			}
			//put the player2 points into the points array called result
			result[player - 1] = player2.totalPoints();
		}

		else if (player == 3) {
			player3.spin(spinWheel);
			if (player3.totalPoints() > 100) {
				//output the over 100 message if the player total points is over 100
				cout << endl << "Your Total Points (" << player3.totalPoints() << ") is over 100." << endl;
				again = false;
			}
			else {
				//output normal message for player total points
				cout << endl << "Player 3 total Points: " << player3.totalPoints() << endl;
			}
			//put the player3 points into the points array called result
			result[player - 1] = player3.totalPoints();

			if (player1.totalPoints() > 100 && player2.totalPoints() > 100)
				break;
		}

		//if already played twice then again is false
		if (play == 1)
			again = false;

		//if only played once, then ask if second spin is desired
		if (play < 2) {
			if (again == true) {
				cout << "Would you want to spin again? (y/n): ";
				cin >> answer;
				cout << endl;
				//if spin again, set the play to 1
				if (answer == 'Y' || answer == 'y')
					play = 1;
				//if not spin again, reset the play value, and go to next player
				else if (answer == 'N' || answer == 'n') {
					play = 0;
					player++;
				}
			}
			//if second spin is not desired, then go to the nextplayer
			else {
				play = 0;
				player++;
				again = false;
			}
		}
	}

	//if any player's score is larger then 100, set them into -1 so they loose
	for (int i = 0; i < 3; i++) {
		if (result[i] > 100)
			result[i] = -1;
	}
	
	//check for ties
	if (result[0] == result[1] && result[1] == result[2] && result[0] != -1) {
		cout << "They all win!" << endl;
		system("Pause");
		return 0;
	}
	else if (result[0] == result[1] && result[0] != -1) {
		cout << "Player 1 and Player 2 wins!" << endl;
		system("Pause");
		return 0;
	}
	else if (result[1] == result[2] && result[1] != -1) {
		cout << "Player 2 and Player 3 wins!" << endl;
		system("Pause");
		return 0;
	}
	else if (result[0] == result[2] && result[0] != -1) {
		cout << "Player 1 and Player 3 wins!" << endl;
		system("Pause");
		return 0;
	}		
	
	//check who wins, store it into winner	
	int max = result[0];
	int winner = 1;
	for (int i = 1; i < 3; i++) {
		if (result[i] > max) {
			max = result[i];
			winner = i + 1;
		}
			
	}

	//display winner
	cout << endl << "Player " << winner << " wins!" << endl;

	system("pause");
	return 0;
}