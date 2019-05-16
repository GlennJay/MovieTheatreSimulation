/*Jason Glenn
Data Structure and Algorithms
Final Project: Movie theatre
Description:
This project is a simulation of a POS system that a ticket counter and manager could use.
I implemented the use of queues, hash table with chaining, comparing objects and searching for items(transactions)
*/

#ifndef	QUEUE_CPP
#define QUEUE_CPP

#include "queue.h"
#include <iostream>

//using namespace std;

template<class T>
Queue<T>::Queue(int size)
{
	elements = new T[size];  // allocate dynamic array
	capacity = size; //initialize data members
	frontIndex = 0;
	numStored = 0;
}

// Copy constructor
template<class T>
Queue<T>::Queue(const Queue<T> &otherQueue)
{
	// Copy non-dynamic array members.
	capacity = otherQueue.capacity;
	frontIndex = otherQueue.frontIndex;
	numStored = otherQueue.numStored;

	// Allocate new array for copy of other queue.
	elements = new T[capacity];

	// Copy the other elements
	for (int i = 0; i < capacity; i++)
		elements[i] = otherQueue.elements[i];
}

// Destructor
template<class T>
Queue<T>::~Queue()
{
	delete[] elements;  // Deallocate dynamic array
	elements = NULL;     // Avoid dangling pointer
	capacity = 0;        // Reset other members
	frontIndex = 0;
	numStored = 0;
}

// Assignment operator
template<class T>
Queue<T> &Queue<T>::operator =(
	const Queue<T> &otherQueue)
{
	// Avoid copying if assigning object to self.
	if (this != &otherQueue)
	{
		// Copy non-dynamic array members.
		capacity = otherQueue.capacity;
		frontIndex = otherQueue.frontIndex;
		numStored = otherQueue.numStored;

		// Deallocate old array.
		delete[] elements;

		// Allocate new array for copy of other queue.
		elements = new T[capacity];

		// Copy the other elements
		for (int i = 0; i < capacity; i++)
			elements[i] = otherQueue.elements[i];
	}

	
	return *this;
}

// Accessor functions

template<class T>
bool Queue<T>::isEmpty() const
{
	return numStored == 0;
}

template<class T>
bool Queue<T>::isFull() const
{
	return numStored == capacity;
}

template<class T>
T Queue<T>::front() const
{
	if (numStored == 0)
	{
		std::cerr << "Queue empty: no element on front" << std::endl;
		return T();
	}

	// Return element at front.
	return elements[frontIndex];
}

// Mutator functions

// Add value to rear
template<class T>
void Queue<T>::addQ(const T &val)
{
	if (numStored == capacity)
	{
		std::cerr << "Queue full: cannot add element" << std::endl;
		return;
	}

	// adding to the real using %
	int newRearIndex = (frontIndex + numStored) % capacity;
	elements[newRearIndex] = val;
	numStored++;
}

// Remove value at front
template<class T>
void Queue<T>::del()
{
	if (numStored == 0)
	{
		std::cerr << "Queue empty: cannot delete element" << std::endl;
		return;
	}

	// will remove the element at the front of the line
	frontIndex++;
	if (frontIndex >= capacity) 
		frontIndex = 0;
	numStored--;
}
#endif