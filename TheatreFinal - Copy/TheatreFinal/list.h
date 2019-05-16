/*Jason Glenn
Data Structure and Algorithms
Final Project: Movie theatre
Description:
This project is a simulation of a POS system that a ticket counter and manager could use.
I implemented the use of queues, hash table with chaining, comparing objects and searching for items(transactions)
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>  // for STL List


template<class T>
class HashTable
{
public:

	// Constructors
	HashTable(int size);  // give size for hashtable

	// Copy constructor
	HashTable(const HashTable<T> &otherTable);

	// Assignment operator
	HashTable<T> &operator =(
		const HashTable<T> &otherTable);

	// Destructor
	~HashTable();

	// Accessors
	bool find(int hashIndex, T &val) const;
	

	void display(int hashIndex, T &val); 

	// Mutators
	bool add(int hashIndex, const T &val);

	//deletion of the val at the index
	inline void del(int hashIndex, T &val)const;

	
	// Reset
	void clear();

private:
	std::list<T> *stored;  // point to dynamic array of linked lists
	int storedSize;  //stores the size of the array

	
};


#endif
