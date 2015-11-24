#include "SpinningWheel.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Default Constructor
SpinningWheel::SpinningWheel() {
	
	index = 0;			//set index to zero
	srand(time(NULL));	//randomize the seed
	int temp;			//creates temp 

	//fill in the values of the array with the 5 increment
	for (int i = 0; i < NUM_VALUES; i++) {
		values[i] = (i + 1) * 5;
	}

	//randomize the array using a randomized swap function
	for (int i = 0; i < NUM_VALUES; i++) {
		int randomIndex = rand() % NUM_VALUES; // choose random index from 0-19
		temp = values[i];
		values[i] = values[randomIndex];
		values[randomIndex] = temp;
	}	
}// end default constructor

//spin function
int SpinningWheel::spin() {
	//randomize the seed
	srand(time(NULL));
	
	//sets the position of the wheel to the last known position
	int current = index;
	
	//chooes a random number from 22 to 42
	int randomSpin = rand() % 20 + 22;
	
	//display the numbers that pass through during spin
	for (int i = 0; i < randomSpin; i++) {
		// resets current location at end of array
		if (current % 20 == 0) {
			current = 0;
			cout << values[current] << " ";
		}
		else {
			cout << values[current] << " ";
		}
		current++;
	}

	//sets the last index of spin as the beggining of the next spin
	index = current;

	//returns the player spin result value
	return values[index-1];
}


