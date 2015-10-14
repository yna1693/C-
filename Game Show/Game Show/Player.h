#ifndef PLAYER_H
#define PLAYER_H
#include "SpinningWheel.h"

class Player {
	private:
		int points;		//total number of points for a given player

	public:
		Player();
		void spin(SpinningWheel &gameWheel);
		int totalPoints();
};

#endif