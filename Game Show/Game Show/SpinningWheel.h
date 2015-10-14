#ifndef SPINNINGWHEEL_H
#define SPINNINGWHEEL_H

class SpinningWheel {
	private:
		static const int NUM_VALUES = 20;
		int values[NUM_VALUES];
		int index;
	
	public:
		SpinningWheel();
		int spin();
};

#endif