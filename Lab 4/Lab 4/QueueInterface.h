#ifndef _QUEUE_INTERFACE
#define _QUEUE_INTERFACE

template<class ItemType>
class QueueInterface {
	public:
	/** Sees whether this Queue is empty.
	@return true if the Queue is empty, or false if not. */
	virtual bool isEmpty() const = 0;


	/** Adds a new entry to the back of this Queue.
	@post newEntry is at the back of the Queue.
	@param newEntry The object to be added as a new entry.
	@throw QueueException if Queue is full. */
	virtual void enqueue(const ItemType& newEntry) = 0;

	/** Removes the front of this Queue.
	@post The front of the Queue is removed.
	@throw QueueException if Queue is initially empty. */
	virtual void dequeue() = 0;

	/** Returns a copy of the front of this Queue.
	@post A copy of the front of the Queue is returned, and
	the Queue is unchanged.
	@return A copy of the front of the Queue.
	@throw QueueException if Queue is initially empty. */
	virtual ItemType peekFront() const = 0;
};
#endif
