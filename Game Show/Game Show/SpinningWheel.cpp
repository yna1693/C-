// Game.h.cpp : Defines the entry point for the console application.
//

#include "SpinningWheel.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Default Constructor
SpinningWheel::SpinningWheel() {
	
	index = 0;			//set index to zero
	srand(time(NULL));	//randomizetheseed
	int temp;			//create a temp

	//fillin the values array with the 5 increment
	for (int i = 0; i < NUM_VALUES; i++) {
		values[i] = (i + 1) * 5;
	}

	//randomize the array by swapping randomly
	for (int i = 0; i < NUM_VALUES; i++) {
		int randomIndex = rand() % NUM_VALUES;
		temp = values[i];
		values[i] = values[randomIndex];
		values[randomIndex] = temp;
	}	
}

//spin function
int SpinningWheel::spin() {
	//randomize the seed
	srand(time(NULL));
	
	//set the position ofthe wheel from index
	int current = index;
	
	//spin a random number
	int randomSpin = rand() % 20 + 22;
	
	//display the numbers that pass through during spin
	for (int i = 0; i < randomSpin; i++) {
		if (current % 20 == 0) {
			current = 0;
			cout << values[current] << " ";
		}
		else {
			cout << values[current] << " ";
		}
		current++;
	}

	//set the index up for the next spin
	index = current;

	//return the player spin result value
	return values[index-1];
}


