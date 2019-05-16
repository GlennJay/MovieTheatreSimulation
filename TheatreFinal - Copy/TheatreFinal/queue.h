/*Jason Glenn
Data Structure and Algorithms
Final Project: Movie theatre
Description:
This project is a simulation of a POS system that a ticket counter and manager could use.
I implemented the use of queues, hash table with chaining, comparing objects and searching for items(transactions)
*/

#ifndef	QUEUE_H
#define QUEUE_H



#include <iostream>



template <class T>
class Queue
{
public:
	// Constructors
	Queue(int size); 

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
	T *elements;    // Point to dynamic array that will store each element (person in line)
	int capacity;   // Size of the line (group) in each sale
	int frontIndex; // will be for element(each person that is at the head of the line)
	int numStored;  // Number values stored

};
#endif 

