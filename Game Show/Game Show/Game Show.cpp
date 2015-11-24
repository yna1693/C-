#include <iostream>
#include <cstdlib>
#include "SpinningWheel.h"
#include "Player.h"

using namespace std;

int main() {
	char answer;		//stores the answer if want to spin again
	int player = 1;		//the index of player
	int play = 0;		//store the number of plays a player plays
	bool spinAgain = true;	//spin twice checker
	int result[3];		//array that store the player results/points

	SpinningWheel spinWheel;	//SpinningWheel object
	Player player1;				//Player object player 1
	Player player2;				//Player object player 2
	Player player3;				//Player objectplayer 3

	cout << "Hello and Welcome to the Game Show!\n" << endl;
	
	//while loop that limits to 3 players only
	while (player < 4) {

		cout << endl << "Player " << player << " Spins this round" << endl;
		//run if statement when it's the player's first spin
		if (play == 0) {
			cout << "First Spin:	";
			spinAgain = true;
		}
		//run else if statemtn when it is the second spin
		else if (play == 1)
			cout << "SecondSpin:	";

		//outputs the spin result/points for player 1
		if (player == 1) {
			player1.spin(spinWheel);
			
			//outputs the over 100 message if the player total points is over 100
			if (player1.totalPoints() > 100) {
				cout << endl << "Your Total Points (" << player1.totalPoints() << ") is over 100." << endl;
				spinAgain = false;
			}
			//outputs normal message for player total points
			else {
				cout << endl << "Player 1 total Points: " << player1.totalPoints() << endl;
			}

			//puts player1 points into the points array called result
			result[player - 1] = player1.totalPoints();
		}

		// outputs the spin result/points for player 2
		else if (player == 2) {
			player2.spin(spinWheel);

			if (player2.totalPoints() > 100) {
				//outputs the over 100 message if the player total points is over 100
				cout << endl << "Your Total Points (" << player2.totalPoints() << ") is over 100." << endl;
				spinAgain = false;
			}
			else {
				//outputs normal message for player total points
				cout << endl << "Player 2 total Points: " << player2.totalPoints() << endl;
			}
			//puts player 2 points into the points array called result
			result[player - 1] = player2.totalPoints();
		}

		//outputs the spin result/points for player 3
		else if (player == 3) {
			player3.spin(spinWheel);

			if (player3.totalPoints() > 100) {
				//outputs the over 100 message if the player total points is over 100
				cout << endl << "Your Total Points (" << player3.totalPoints() << ") is over 100." << endl;
				spinAgain = false;
			}
			else {
				//outputs normal message for player total points
				cout << endl << "Player 3 total Points: " << player3.totalPoints() << endl;
			}
			//puts player 3 points into the points array called result
			result[player - 1] = player3.totalPoints();

			//breaks the loop when player 1 and player 2 both go over 100 points. Sets player 3 the winner
			if (player1.totalPoints() > 100 && player2.totalPoints() > 100)
				break;
		}

		//if already spinned/played twice then player cannot spin again
		if (play == 1)
			spinAgain = false;

		//asks if player wants to spin the second time if player only spinned once
		if (play < 2) {
			if (spinAgain == true) {
				cout << "Would you want to spin again? (y/n): ";
				cin >> answer;
				cout << endl;
				//if player wants to spin again, set the play to 1
				if (answer == 'Y' || answer == 'y')
					play = 1;
				//if player does not want to spin again
				else if (answer == 'N' || answer == 'n') {
					play = 0; //resets the play value
					player++; // goes to next player
				}
			}
			//if second spin is not desired, then go to the nextplayer
			else {
				play = 0;
				player++;
				spinAgain = false;
			}
		}
	}
	
	// Start of points/results check system

	//if any player's score is larger then 100, set them into -1 so they loose
	for (int i = 0; i < 3; i++) {
		if (result[i] > 100)
			result[i] = -1;
	}
	
	//checks for ties
	if (result[0] == result[1] && result[1] == result[2] && result[0] != -1) {
		cout << endl << "They all win!" << endl;
		system("Pause");
		return 0;
	}
	else if (result[0] == result[1] && result[0] != -1) {
		cout << endl << "Player 1 and Player 2 wins!" << endl;
		system("Pause");
		return 0;
	}
	else if (result[1] == result[2] && result[1] != -1) {
		cout << endl << "Player 2 and Player 3 wins!" << endl;
		system("Pause");
		return 0;
	}
	else if (result[0] == result[2] && result[0] != -1) {
		cout << endl << "Player 1 and Player 3 wins!" << endl;
		system("Pause");
		return 0;
	}		
	
	//checks who wins, store it into winner	
	int max = result[0];
	int winner = 1;
	for (int i = 1; i < 3; i++) {
		if (result[i] > max) {
			max = result[i];
			winner = i + 1;
		}
			
	}

	//displays winner
	cout << endl << "Player " << winner << " wins!" << endl;

	system("pause");
	return 0;
}