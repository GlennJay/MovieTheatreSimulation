


#include "searchList.h"
#include <iostream>
#include <algorithm>
#include <iterator>


using namespace std;


template<class T>
 SearchList<T>::SearchList()
{

	frontP = NULL;  // initially empty
	rearP = NULL;
}


// Copy constructor

 template<class T>
 SearchList<T>::SearchList(const SearchList<T> &otherList)
{
	frontP = NULL;  // initially empty
	rearP = NULL;

	// Append elements from other Sale.
	append(otherList);
}

// Destructor

 template<class T>
 SearchList<T>::~SearchList()
{
	clear();  // empty list
}

// Assignment operator
 template<class T>
SearchList<T> &SearchList<T>::operator =(
	const SearchList<T> &otherSale)
{
	// Avoid copying if assigning object to self.
	if (this != &otherSale)
	{
		// Copy non-dynamic array members (none here).

		// Remove current nodes, reset pointer.
		clear();

		// Append elements from other Sale.
		append(otherSale);
	}

	// Return self.
	return *this;
}



// Accessors

template<class T>
bool SearchList<T>::isEmpty() const
{
	return frontP == NULL;
}

template<class T>
bool SearchList<T>::isFull() const
{
	// Linked list never full since can add more
	// nodes (though could run out of memory).
	return false;
}





//
// void Sale::front() const
//{
//	if (frontP == NULL)
//	{
//		cerr << "Sale empty: no element at front" << endl;
//		return;
//	}
//
//	return frontP->info;
//}

// Mutators

// Add value to rear
template<class T>
void SearchList<T>::add(const T &item)
{
	// Allocate new node 
	Node<T> *newNodeP = new Node<T>;

	//store data in the new node
	newNodeP->info = item;
	
	//new nodes will be added at the end
	newNodeP->nextP = NULL;  // none after this node

	//start list if it is empty
	if (frontP == NULL)
	{
		//sets front and rear to new nodes position
		frontP = rearP = newNodeP;
	}
	else
	{
		//point the old rear to new node
		rearP->nextP = newNodeP;

		//set rear to new node
		rearP = newNodeP;
	}
}

// Remove value at front
//template<class T>
//T SearchList<T>::remove() 
//{
//	if (frontP == NULL)
//	{
//		cerr << "Sale empty: cannot delete element" << endl;
//		return T();
//	}
//
//	// Advance front pointer and deallocate node.
//	Node *deleteP = frontP;
//	frontP = frontP->nextP;
//	delete deleteP;
//
//	if (frontP == NULL)  // removed the only node
//		rearP = NULL;
//}

//displays the transaction summary
template<class T>
bool SearchList<T>::find(T &searchValue) const//change to find, renamer , paramet
{
		for (Node<T> *traverseP = frontP; traverseP != NULL; traverseP = traverseP->nextP)
		{
			// PERFORM LINEAR SEARCH OF LINKED LIST TO FIND VALUE.
				if (traverseP->info == searchValue)
				{
					searchValue = traverseP->info;
					return true;
				}
		}
	
	return false;
}

template<class T>
void SearchList<T>::display() 
{
	

	cout << "History:";

	/*for (Node<T> *traverseP = frontP;
		traverseP != NULL;
		traverseP = traverseP->nextP)
		cout << " " << *(traverseP);*/
	
	Node<T> traverseP = frontP;
	while (traverseP)
	{
		cout << traverseP->info;
		traverseP = traverseP->nextP;
	}

}





template<class T>
void SearchList<T>::clear()
{
	while (frontP != NULL)
	{
		// Keep temporary pointer to node about
		// to delete.
		Node<T> *deleteP = frontP;

		// Advance to next node.
		frontP = frontP->nextP;

		// Deallocate node.
		delete deleteP;
	}

	// After loop, frontP is NULL.  Set rearP
	// to NULL also.
	rearP = NULL;
}

template<class T> 
void SearchList<T>::append(const SearchList<T> &otherSale)
{
	for (Node *traverseP = otherSale.frontP; traverseP != NULL; traverseP = traverseP->nextP)
	{
		addRear(traverseP->items, traverseP->transNum, traverseP->transTotal);

	}
		
}


