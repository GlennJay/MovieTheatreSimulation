#include "MovieQueue.h"
#include <iostream>
#include <iomanip>

using namespace std;


//template<class Q>
//MovieQueue<Q>::MovieQueue()
//{
//	size = 2;
//	frontIndex = 
//}

//constructors


template<class Q>
MovieQueue<Q>::MovieQueue(int size)
{
	maxSize = size;
	patron = new Q[size];
	frontIndex = 0;
	stored = 0;
}

template<class Q>
MovieQueue<Q>::MovieQueue(const MovieQueue<Q>& otherQueue)
{
	//copy data members
	maxSize = otherQueue.maxSize;
	frontIndex = otherQueue.frontIndex;
	stored = otherQueue.stored;

	//allocate the new array
	patron = new Q[maxSize];

	//copy array
	for (int i = 0; i < maxSize; i++)
	{
		patron[i] = otherQueue.patron[i];
	}
}

template<class Q>
MovieQueue<Q> & MovieQueue<Q>::operator=(const MovieQueue<Q>& otherQueue)
{
	//prevent self assignment
	if (this != otherQueue)
	{
		//copy data members
		maxSize = otherQueue.maxSize;
		frontIndex = otherQueue.frontIndex;
		stored = otherQueue.stored;

		//deallocate old array
		delete[] patron;

		//allocate the new array
		patron = new Q[maxSize];

		//copy array
		for (int i = 0; i < maxSize; i++)
		{
			patron[i] = otherQueue.patron[i];
		}

	}

	//returns object
	return *this;
}

template<class Q>
MovieQueue<Q>::~MovieQueue()
{
	//deallocate array and reset data members
	delete[] patron;
	patron = NULL;
	maxSize = 0;
	frontIndex = 0;
	stored = 0;
}

template<class Q>
bool MovieQueue<Q>::isFull() const
{
	//returns true if
	return maxSize == stored;
}

template<class Q>
bool MovieQueue<Q>::isEmpty() const
{
	//returns true if 
	return stored == 0;
}

template<class Q>
Q MovieQueue<Q>::front() const
{
	//if empty
	if (isEmpty())
	{
		cout << "The line is empty" << endl;
		return Q();
	}

	return patron[frontIndex];
	
}

template<class Q>
void MovieQueue<Q>::add(const Q & newPatron)
{
	//can not add if full
	if (stored == maxSize)
	{
		cout << " line is full" << endl;
		return;
	}

	//create and store for rear
	int rearIndex = (frontIndex + stored) % maxSize;
	patron[rearIndex] = newPatron;
	stored++;
}

template<class Q>
Q MovieQueue<Q>::remove()
{

	if (stored == maxSize)
	{
		cout << "full " << endl;
		return Q();
	}

	frontIndex++;
		if (frontIndex >= maxSize)
			frontIndex = 0;
}
