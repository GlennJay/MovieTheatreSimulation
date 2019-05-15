//#pragma once
#ifndef	QUEUE_H
#define QUEUE_H



#include <iostream>

//using namespace std;

template <class T>
class Queue
{
public:
	// Constructors
	Queue(int size);  // initial capacity

	// Copy constructor
	Queue(const Queue<T> &otherQueue);

	// Assignment operator
	Queue<T> &operator =(
		const Queue<T> &otherQueue);

	// Destructor
	~Queue();

	// Determine emptiness or fullness
	bool isEmpty() const;
	bool isFull() const;

	// See value at front
	T front() const;

	// Add value to rear
	inline void addQ(const T &val);

	// Remove value at front
	void del();

private:
	T *elements;    // Point to dynamic array that will store each person in line
	int capacity;   // Size of the line (group) in each sale
	int frontIndex; // will be for each person that is at the head of the line
	int numStored;  // Number values stored

};
#endif // !1

//template<class T>
//Queue<T>::Queue(int size)
//{
//	elements = new T[size];  // allocate dynamic array
//	capacity = size;
//	frontIndex = 0;
//	numStored = 0;
//}
//
//// Copy constructor
//template<class T>
//Queue<T>::Queue(const Queue<T> &otherQueue)
//{
//	// Copy non-dynamic array members.
//	capacity = otherQueue.capacity;
//	frontIndex = otherQueue.frontIndex;
//	numStored = otherQueue.numStored;
//
//	// Allocate new array for copy of other queue.
//	elements = new T[capacity];
//
//	// Copying *all* array elements--HOW ONLY COPY
//	// THOSE OCCUPIED?
//	for (int i = 0; i < capacity; i++)
//		elements[i] = otherQueue.elements[i];
//}
//
//// Destructor
//template<class T>
//Queue<T>::~Queue()
//{
//	delete[] elements;  // Deallocate dynamic array
//	elements = NULL;     // Avoid dangling pointer
//	capacity = 0;        // Reset other members
//	frontIndex = 0;
//	numStored = 0;
//}
//
//// Assignment operator
//template<class T>
//Queue<T> &Queue<T>::operator =(
//	const Queue<T> &otherQueue)
//{
//	// Avoid copying if assigning object to self.
//	if (this != &otherQueue)
//	{
//		// Copy non-dynamic array members.
//		capacity = otherQueue.capacity;
//		frontIndex = otherQueue.frontIndex;
//		numStored = otherQueue.numStored;
//
//		// Deallocate old array.
//		delete[] elements;
//
//		// Allocate new array for copy of other queue.
//		elements = new T[capacity];
//
//		// Copying *all* array elements--HOW ONLY COPY
//		// THOSE OCCUPIED?
//		for (int i = 0; i < capacity; i++)
//			elements[i] = otherQueue.elements[i];
//	}
//
//	// Return self.
//	return *this;
//}
//
//// Accessors
//
//template<class T>
//bool Queue<T>::isEmpty() const
//{
//	return numStored == 0;
//}
//
//template<class T>
//bool Queue<T>::isFull() const
//{
//	return numStored == capacity;
//}
//
//template<class T>
//T Queue<T>::front() const
//{
//	if (numStored == 0)
//	{
//		cerr << "Queue empty: no element on front" << endl;
//		return T();
//	}
//
//	// Return element at front.
//	return elements[frontIndex];
//}
//
//// Mutators
//
//// Add value to rear
//template<class T>
//void Queue<T>::addQ(const T &val)
//{
//	if (numStored == capacity)
//	{
//		cerr << "Queue full: cannot add element" << endl;
//		return;
//	}
//
//	// ADD TO REAR (NO LONGER STORES INDEX OF REAR).
//	int newRearIndex = (frontIndex + numStored) % capacity;
//	elements[newRearIndex] = val;
//	numStored++;
//}
//
//// Remove value at front
//template<class T>
//void Queue<T>::del()
//{
//	if (numStored == 0)
//	{
//		cerr << "Queue empty: cannot delete element" << endl;
//		return;
//	}
//
//	// REMOVE ELEMENT THAT IS AT FRONT.
//	frontIndex++;
//	if (frontIndex >= capacity)  // wraparound
//		frontIndex = 0;
//	numStored--;
//}