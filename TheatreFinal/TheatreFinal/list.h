

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>  // for STL List
//using namespace std;

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

	void display(int hashIndex, T &val); // (T &val);

	// Mutators
	bool add(int hashIndex, const T &val);

	// Reset
	void clear();

private:
	std::list<T> *stored;  // point to dynamic array of linked lists
	int storedSize;
};

#endif
