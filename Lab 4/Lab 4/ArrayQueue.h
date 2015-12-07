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

