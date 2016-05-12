#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

// the class itself
class ArrayQueue
{
public:
	/* MEMBERS */
	int front, rear, capacity, size;
	char* data;

	/* FUNCTIONS */

	// constructor
	ArrayQueue(const int&);

	// destructor
	~ArrayQueue();

	// enqueue
	bool enqueue(const char&);

	// dequeue
	bool dequeue(char& letter);

	// peek  
	bool peek(char&);

	// isEmpty
	bool isEmpty();

	// isFull
	bool isFull();
};
#endif