#include "Player.h"
#include "SpinningWheel.h"
#include <iostream>

using namespace std;


Player::Player() {
	//initilize point to zero
	points = 0;
}

void Player::spin(SpinningWheel &gameWheel) {
	//add the points together 
	points += gameWheel.spin();
}

int Player::totalPoints() {
	//return the total points
	return points;
}
