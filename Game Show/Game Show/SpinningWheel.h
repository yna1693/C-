#ifndef SPINNINGWHEEL_H
#define SPINNINGWHEEL_H

class SpinningWheel {
	private:
		static const int NUM_VALUES = 20; // size of the array
		int values[NUM_VALUES]; // the game wheel (array named value with a size of NUM_VALUES)
		int index; // Stores the last know position of the wheel
	
	public:
		SpinningWheel();
		int spin();
};

#endif