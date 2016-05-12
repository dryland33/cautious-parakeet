#ifndef intARRAYQUEUE_H
#define intARRAYQUEUE_H

// the class itself
class intArrayQueue
{
public:
	/* MEMBERS */
	int front, rear, capacity, size;
	int* data;

	/* FUNCTIONS */

	// constructor
	intArrayQueue(const int&);

	// destructor
	~intArrayQueue();

	// enqueue
	bool enqueue(const int&);

	// dequeue
	bool dequeue(int& num);
	bool dequeue();

	// peek  
	bool peek(int&);

	// isEmpty
	bool isEmpty();

	// isFull
	bool isFull();

	int get_front();

	int get_size();
};

int intArrayQueue::get_front(){
	return front;
}

int intArrayQueue::get_size(){
	return size;
}


intArrayQueue::intArrayQueue(const int& capacity)
{
	data = new int[capacity];
	front = rear = size = 0;
	this->capacity = capacity;
}

intArrayQueue::~intArrayQueue()
{
	delete data;
}

bool intArrayQueue::enqueue(const int& num)
{
	if (isFull())
		return false;

	data[rear] = num; // write where rear is
	++rear %= capacity; // move read, allowing for past the end condition
	++size;
	return true;
}

bool intArrayQueue::dequeue(int& num)
{
	if (isEmpty())
		return false;

	num = data[front];
	++front %= capacity;
	--size;
	return true;
}

//overloads bool equeue(int& num)
//used for simply emptying the queue
bool intArrayQueue::dequeue() 
{
	if (isEmpty())
		return false;

	++front %= capacity;
	--size;
	return true;
}

bool intArrayQueue::peek(int& num)
{
	if (isEmpty())
		return false;

	num = data[front];
	return true;
}

bool intArrayQueue::isEmpty()
{
	return size == 0;
}

bool intArrayQueue::isFull()
{
	return size == capacity;
}

#endif