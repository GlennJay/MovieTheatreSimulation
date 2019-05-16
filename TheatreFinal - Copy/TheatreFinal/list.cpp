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

#include <algorithm>
#include <iostream>
#include <vector>
 /*Jason Glenn
 Data Structure and Algorithms
 Final Project: Movie theatre
 Description:
 This project is a simulation of a POS system that a ticket counter and manager could use.
 I implemented the use of queues, hash table with chaining, comparing objects and searching for items(transactions)
 */

#include "list.h"


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
		// searches for the element and displays
		for (typename std::list<T>::const_iterator iter = stored[hashi].begin();
			iter != stored[hashi].end(); iter++)
			if (*iter == val)
			{
				std::cout << *iter << std::endl;
			}
		hashi++;//incrementing so i can go through each hash table and down the line of linked list
	}



}

// Mutators

template<class T>
bool HashTable<T>::add(int hashIndex, const T &val)
{
	// Determine list in which would be stored.
	int hashi = hashIndex % storedSize;

	// adds to the list
	stored[hashi].push_back(val);

	return true;
}

//deletion of the value at the index
template<class T>
inline void HashTable<T>::del(int hashIndex, T & val)const
{
	//determine where in list value is stored
	int hashi = hashIndex % storedSize;

	stored[hashi].remove(val);

}

// Clear table (by clearing all linked lists).
template<class T>
void HashTable<T>::clear()
{
	for (int i = 0; i < storedSize; i++)
		stored[i].clear();
}

#endif



