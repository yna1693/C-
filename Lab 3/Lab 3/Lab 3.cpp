// Lab 3.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Node.h"

using namespace std;

int main() {

	int input = 0;
	int count = 1;
	Node<int> *list;
	Node<int> *cur;
	Node<int> *prev;

	
	cout << "Enter the numbers and enter -1 to finish" << endl;

	cur = new Node<int>();
	cin >> input;
	cur->setItem(input);
	prev = cur;
	list = cur;


	while (input != -1) {
		cur = new Node<int>();
		cin >> input;
		if (input == -1)
			break;
		cur->setItem(input);
		prev->setNext(cur);
		prev = prev->getNext();
		count++;
	} 

	cur = list;
	for (int i = 0; i < count; i++) {
		cout << cur->getItem() << " ";
		cur = cur->getNext();
	}
	cout << endl;
	list->mergeSort(list);

	

	//loop and output

	cur = list;

	for (int i = 0; i < count; i++) {
		cout << cur->getItem() << " ";
		cur = cur->getNext();
	}

	cout << endl;
	system("pause");
	return 0;
}
