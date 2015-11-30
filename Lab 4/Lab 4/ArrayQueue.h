#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

#include "QueueInterface.h"
#include "QueueException.h"

const int MAX_QUEUE = 4;

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType> {
	private:
	ItemType items[MAX_QUEUE];   // Array of Queue items
	int front;                   // Index to front of Queue
	int back;                    // Index to back of Queue
	

	public:
	ArrayQueue();
	// Copy constructor and destructor are supplied by the compiler

	bool isEmpty() const;

	// check if the queue is full
	bool isFull() const;

	/** @throw QueueException if Queue is full. */
	void enqueue(const ItemType& newEntry);

	/** @throw QueueException if Queue is initially empty. */
	void dequeue();

	/** @throw QueueException if Queue is empty. */
	ItemType peekFront() const;

	//display the current queue
	void displayQueue() const;



};


#endif

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
		throw QueueException("QueueException: Queue full on enqueue");
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
		throw QueueException("QueueException: Queue empty on dequeue");
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

