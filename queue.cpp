#include "queue.hpp"

ArrayQueue::ArrayQueue(const int& capacity)
{
	data = new char[capacity];
	front = rear = size = 0;
	this->capacity = capacity;
}

ArrayQueue::~ArrayQueue()
{
	delete data;
}

bool ArrayQueue::enqueue(const char& letter)
{
	if (isFull())
		return false;

	data[rear] = letter; // write where rear is
	++rear %= capacity; // move read, allowing for past the end condition
	++size;
	return true;
}

bool ArrayQueue::dequeue(char& letter)
{
	if (isEmpty())
		return false;

	letter = data[front];
	++front %= capacity;
	--size;
	return true;
}

bool ArrayQueue::peek(char& letter)
{
	if (isEmpty())
		return false;

	letter = data[front];
	return true;
}

bool ArrayQueue::isEmpty()
{
	return size == 0;
}

bool ArrayQueue::isFull()
{
	return size == capacity;
}