// Lab 4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "ArrayQueue.h"

using namespace std;


int main()
{
	int answer;
	ArrayQueue<int> queue;

	while (true) {
		cout << "1) Add item to queue" << endl
			<< "2) Remove item from queue" << endl
			<< "3) Exit program" << endl
			<< "Enter your selection (1-3): ";

		cin >> answer;

		if (answer == 3) {
			break;
		}
		else if (answer == 1) {
			cout << "Enter item to insert: ";
			cin >> answer;
			queue.enqueue(answer);
		}
		else if (answer == 2) {
			queue.dequeue();
		}

		queue.displayQueue();
	}

    return 0;
}

