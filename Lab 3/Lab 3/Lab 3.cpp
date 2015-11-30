// Lab 3.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <iostream>
#include<sstream>
#include <time.h>
#include "Node.h"

using namespace std;

int main() {

	stringstream ss;
	string entered;
	int input = 0;
	int count = 1;
	Node<int> *list;
	Node<int> *cur;
	Node<int> *prev;

	
	cout << "Enter the numbers to be sorted: ";

	getline(cin, entered);
	ss << entered;

	ss >> input;
	cur = new Node<int>();
	cur->setItem(input);
	prev = cur;
	list = cur;
	

	


	while (ss >> input) {
		cur = new Node<int>();
		cur->setItem(input);
		prev->setNext(cur);
		prev = prev->getNext();
		count++;
	} 

	cur = list;
	
	list->mergeSort(list);

	

	//loop and output
	cout << "Sorted numbers: ";

	cur = list;

	for (int i = 0; i < count; i++) {
		cout << cur->getItem() << " ";
		cur = cur->getNext();
	}

	cout << endl;
	system("pause");
	return 0;
}
