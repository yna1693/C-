#include <iostream>
using namespace std;

#ifndef _NODE_
#define _NODE_

template<typename ItemType>

class Node {
	private:
	ItemType item; // A data item
	Node<ItemType>* next; // Pointer to next node
	public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	void mergeSort(Node<ItemType>*& head);
	Node<ItemType>* merge(Node<ItemType>*& head1, Node<ItemType>*& head2);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
}; // end Node

#endif

template<typename ItemType>
Node<ItemType>::Node() :next(nullptr) {

} // end default constructor

template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem) {

	item(anItem);
	next(nullptr);

} // end constructor

template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) {

	item(anItem);
	next(nextNodePtr);

} // end constructor

template<typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {

	item = anItem;

} // end setItem

template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {

	next = nextNodePtr;

} // end setNext

template<typename ItemType>
ItemType Node<ItemType>::getItem() const {

	return item;

} // end getItem

template<typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {

	return next;

} // end getNext

template<typename ItemType>
void Node<ItemType>::mergeSort(Node<ItemType>*& head) {

	Node<ItemType>*countptr = head;
	Node<ItemType>*left = head;
	Node<ItemType>*right = head;
	Node<ItemType>*leftTail = head;
	int length = 1;

	while (countptr->getNext() != nullptr) {
		length++;
		countptr = countptr->getNext();
	}
		
		int middle = length / 2;
		
		

		//put head in the next one and cut list
		if (middle > 1) {
			for (int i = 0; i < middle - 1; i++) {
				leftTail = leftTail->getNext();	
			}
			right = leftTail->getNext();
			leftTail->setNext(nullptr);
		}
		else if (middle == 1){		
			right = leftTail->getNext();	//if there is only two element
			leftTail->setNext(nullptr);
		}
		else {
			return;	//if there is only one element in the list
		}

			
		/*
		//////////////////////DEBUG///////////////////////
		leftTail = left;

		while (true) {
			cout << leftTail->getItem() << " ";
			if (leftTail->getNext() == nullptr)
				break;
			else {
				leftTail = leftTail->getNext();
			}
		}
		cout << "\t";
		/////////////////////DEBUG////////////////////////

		leftTail = right;

		while (true) {
			cout << leftTail->getItem() << " ";
			if (leftTail->getNext() == nullptr)
				break;
			else {
				leftTail = leftTail->getNext();
			}
		}
		cout << endl;
		//////////////////////DEBUG///////////////////////
		*/
		mergeSort(left);
		mergeSort(right);

	

		head = merge(left, right);

}

template<typename ItemType>
Node<ItemType>* Node<ItemType>::merge(Node<ItemType>*& head1, Node<ItemType>*& head2) {

	Node<ItemType>*head = nullptr;
	Node<ItemType>*cur = nullptr;

	


	//set the first element
	if (head1->getItem() >= head2->getItem()) {
		head = head2;
		if (head2->getNext() != nullptr)
			head2 = head2->getNext();
		else
			head2 = nullptr;
	}
	else {
		head = head1;
		if (head1->getNext() != nullptr)
			head1 = head1->getNext();
		else
			head1 = nullptr;
	}

	cur = head;
	
	
		while (true) {
			if (head1 == nullptr && head2 == nullptr)
					break;
			else if (head1 == nullptr && head2 != nullptr) {
				cur->setNext(head2);
				cur = cur->getNext();
				if (head2->getNext() != nullptr)
					head2 = head2->getNext();
				else
					head2 = nullptr;
			}
			else if (head2 == nullptr && head1 != nullptr) {
				cur->setNext(head1);
				cur = cur->getNext();
				if (head1->getNext() != nullptr)
					head1 = head1->getNext();
				else
					head1 = nullptr;
			}
			else if (head1->getItem() >= head2->getItem()) {
				cur->setNext(head2);
				cur = cur->getNext();
				if (head2->getNext() != nullptr)
					head2 = head2->getNext();
				else
					head2 = nullptr;
			}
			else if (head1->getItem() <= head2->getItem()) {
				cur->setNext(head1);
				cur = cur->getNext();
				if (head1->getNext() != nullptr)
					head1 = head1->getNext();
				else
					head1 = nullptr;
			}
			else
				break;
	}
	
	


	return head;
}
