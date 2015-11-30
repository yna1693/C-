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
	// places inputed numbers into a node
	//precondition: node has to exist
	//postcontition: anItem will be put into a node

	item = anItem;

} // end setItem

template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
	//sets the address of the next node 
	//precondition: address can be a node or nullptr

	next = nextNodePtr;

} // end setNext

template<typename ItemType>
ItemType Node<ItemType>::getItem() const {
	//gets the item from the current node
	//precondition: a node must exist
	//postcondition: returns current node item

	return item;

} // end getItem

template<typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
	// gets the next node address
	//precondition: a node must exist and it must not be a nullptr
	//postcondition: gets the next node address

	return next;

} // end getNext

template<typename ItemType>
void Node<ItemType>::mergeSort(Node<ItemType>*& head) {
	//sorts the link list pointed to by head
	//precondition: head pointd to a linked list of items
	//postcondition : head points to a sorted linked list, containing the items
	//that were in the original linked list but in sorted order
	
	Node<ItemType>*countptr = head;
	Node<ItemType>*left = head;
	Node<ItemType>*right = head;
	Node<ItemType>*leftTail = head;
	int length = 1;

	//counts the length of the list
	while (countptr->getNext() != nullptr) { 
		length++;
		countptr = countptr->getNext();
	}
		
	//find the middle node index of the list
		int middle = length / 2;
		
		

		//if left list has more than 1 element
		if (middle > 1) {
			//find the end of left list
			for (int i = 0; i < middle - 1; i++) {
				leftTail = leftTail->getNext();	
			}
			right = leftTail->getNext(); //set the right list head
			leftTail->setNext(nullptr);  //cut the list
		}
		else if (middle == 1){		
			right = leftTail->getNext();	//if there is only two element
			leftTail->setNext(nullptr);		//cut the list
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
		mergeSort(left);	//recursive left list
		mergeSort(right);	//recursive right list

	

		head = merge(left, right); //merge the list

}

template<typename ItemType>
Node<ItemType>* Node<ItemType>::merge(Node<ItemType>*& head1, Node<ItemType>*& head2) {

	/* returns a pointer to a sorted linked list that results from merging the sorted
	 * linked list pointed to by head1 and head2.
	 * Preconditions: head1 and head2 point to sorted linked list.
	 * Postconditions: returns a pointer to a sorted linked list containing the nodes
	 *					that used to be in the sorted linked lists pointed to by head1
	 *					and head2; 
	 *                  head1 and head2 have the value nullptr.
	 */
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
	//return cur to begining of list
	cur = head;
	
	//while either list is not empty
	//do comparison and append to list
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
