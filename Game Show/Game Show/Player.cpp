#include "Player.h"
#include "SpinningWheel.h"

using namespace std;

//Default constructor
Player::Player() {
	//initilize points to zero
	points = 0;
}//end default constructor

void Player::spin(SpinningWheel &gameWheel) {
	//adds the points together from SpinningWheel spin function 
	points += gameWheel.spin();
}

int Player::totalPoints() {
	//returns the total points
	return points;
}
