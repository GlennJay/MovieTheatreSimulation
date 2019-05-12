/*Jason Glenn
Data Structure Final Project

Class Description:
The sale class will implement a linked list structure to record transactions. Each node will save and contain a record 
of each individual transaction. The data that will be saved and recorded will be transaction Number, the total for that transaction,
the amount sold of the item(in this program I will be storing number of seats, however the variable will be generic).
*/

#pragma once
//#include "sale.h"

template<class T>
class SearchList
{
	public:

		//constructor
		SearchList();

		//copy constructor
		SearchList(const SearchList &otherSale);

		//overloaded assignment
		SearchList<T> &operator =(
			const SearchList &otherSale);


		//destructor
		~SearchList();

		// Determine emptiness or fullness
		bool isEmpty() const;
		bool isFull() const;

		// See value at front
		//void front() const;

		// Add value to rear
		 void add(const T &item);

		// Remove value at front
		//T remove();

		bool find(T &searchElement) const;

		//display of list
		void display();
		 

	private:
		template<class T>
		struct Node {
			
			T info;

			Node<T> *nextP;
		};

		//front of my list
		Node<T> *frontP;

		//keep track of the rear for easy insertion
		Node<T> *rearP;


		void clear();
		void append(const SearchList<T> &otherList);

};





