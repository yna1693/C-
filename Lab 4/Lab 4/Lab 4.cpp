// Lab 4.cpp : Defines the entry point for the console application.
//used Method 2 from http://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp because Method 3 won't compile!

#include <iostream>
#include"ArrayQueue.h"
#include "ArrayQueue.cpp"

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

		if (answer >= 3) {
			break;
		}
		else if (answer == 1) {
			cout << "Enter item to insert: ";
			cin >> answer;
			try {
				queue.enqueue(answer);
			}
			catch (QueueException exception) {
				cout << exception.what() << endl;
			}
		}
		else if (answer == 2) {
			try {
				queue.dequeue();
			}
			catch (QueueException exception) {
				cout << exception.what() << endl;
			}
		}

		queue.displayQueue();
	}

    return 0;
}

