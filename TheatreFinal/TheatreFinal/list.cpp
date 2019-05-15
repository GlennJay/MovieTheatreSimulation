/*
 * Name: YOUR NAME
 * HashTable Implementation File
 * Course: CSI218 (Spring 2019)
 * Lecture: Hashing
 * Date: April 16, 2019
 * Description: HashTable member function definitions.
 *				Table implemented with array of linked
 *				list to achieve chaining.
 */

#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include <iostream>
#include "list.h"
//using namespace std;

// HashTable member function definitions.

// Constructors

template<class T>
HashTable<T>::HashTable(int size)
{
	stored = new std::list<T>[size];  // allocate dynamic array of lists
	storedSize = size;
}

// Copy constructor
template<class T>
HashTable<T>::HashTable(const HashTable<T> &otherTable)
{
	// Copy non-dynamic array members.
	storedSize = otherTable.storedSize;

	// Allocate new array for copy of other hashtable.
	stored = new std::list<T>[storedSize];

	// Copy lists from other table.
	for (int i = 0; i < storedSize; i++)
		stored[i] = otherTable.stored[i];
}

// Destructor
template<class T>
HashTable<T>::~HashTable()
{
	delete[] stored;  // Deallocate dynamic array
	stored = NULL;     // Avoid dangling pointer
	storedSize = 0;    // Reset other member
}

// Assignment operator
template<class T>
HashTable<T> &HashTable<T>::operator =(
	const HashTable<T> &otherTable)
{
	// Avoid copying when assign object to self.
	if (this != &otherTable)
	{
		// Copy non-dynamic array members.
		storedSize = otherTable.storedSize;

		// Deallocate old array.
		delete[] stored;

		// Allocate new array for copy of other hashtable.
		stored = new T[storedSize];

		// Copy lists from other table.
		for (int i = 0; i < storedSize; i++)
			stored[i] = otherTable.stored[i];
	}

	// Return self.
	return *this;
}

// Accessors

template<class T>
bool HashTable<T>::find(int hashIndex, T &val) const
{
	// Determine list in which would be stored.
	int hashi = hashIndex % storedSize;

	// PERFORM LINEAR SEARCH OF LINKED LIST TO FIND VALUE.
	for (typename std::list<T>::const_iterator iter = stored[hashi].begin();
		iter != stored[hashi].end(); iter++)
		if (*iter == val)
		{
			val = *iter;
			return true;
		}


	return false;
}

template<class T>
void HashTable<T>::display(int hashIndex, T &val) //(T &val)
{
	
	// Determine list in which would be stored.
	int hashi = hashIndex % storedSize;

	while (hashi <= storedSize)
	{
		// PERFORM LINEAR SEARCH OF LINKED LIST TO FIND VALUE.
		for (typename std::list<T>::const_iterator iter = stored[hashi].begin();
			iter != stored[hashi].end(); iter++)
			if (*iter == val)
			{
				std::cout << *iter << std::endl;
			}
		hashi++;
	}



}

// Mutators

template<class T>
bool HashTable<T>::add(int hashIndex, const T &val)
{
	// Determine list in which would be stored.
	int hashi = hashIndex % storedSize;

	// ADD TO LINKED LIST.
	stored[hashi].push_back(val);

	// Always room unless program runs out of memory.
	return true;
}

// Clear table (by clearing all linked lists).
template<class T>
void HashTable<T>::clear()
{
	for (int i = 0; i < storedSize; i++)
		stored[i].clear();
}

#endif