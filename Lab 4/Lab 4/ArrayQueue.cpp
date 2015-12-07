#include "ArrayQueue.h"
#include <iostream>

using namespace std;

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(0) {
	for (int i = 0; i < MAX_QUEUE; i++) {
		items[i] = NULL;
	}
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
	if (front == back && items[front] == NULL)
		return true;
	else
		return false;
}

template<class ItemType>
bool ArrayQueue<ItemType>::isFull() const {
	if (front == (back + 1) % MAX_QUEUE)
		return true;
	else
		return false;
}

/** @throw QueueException if Queue is full. */
template<class ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry) {
	if (isFull())
		throw QueueException("Unable to insert into full queue");
	else {
		if (isEmpty() && items[back] == NULL) {
			items[back] = newEntry;
		}
		else {
			back = (back + 1) % MAX_QUEUE;
			items[back] = newEntry;
		}
	}
}

/** @throw QueueException if Queue is initially empty. */
template<class ItemType>
void ArrayQueue<ItemType>::dequeue() {
	if (isEmpty())
		throw QueueException("Unable to remove item from empty queue");
	else if (front == back)
		items[front] = NULL;
	else {
		items[front] = NULL;
		front = (front + 1) % MAX_QUEUE;
	}
}

/** @throw QueueException if Queue is empty. */
template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {
	if (isEmpty())
		throw QueueException("QueueException: Queue empty on peekFront");
	else
		return items[front];
}

template<class ItemType>
void ArrayQueue<ItemType>::displayQueue() const {

	cout << "Queue contents: ";

	if (isEmpty()) {
		cout << endl;
		cout << endl;
		return;
	}
	else {
		int cur = front;
		do {
			cout << items[cur] << " ";
			cur = (cur + 1) % MAX_QUEUE;
		} while (cur != (back + 1) % MAX_QUEUE);
	}

	cout << endl << endl;

}
