/*Jason Glenn
Data Structure and Algorithms
Final Project: Movie theatre
Description:
This project is a simulation of a POS system that a ticket counter and manager could use.
I implemented the use of queues, hash table with chaining, comparing objects and searching for items(transactions)
*/

#pragma once

#include <iostream>

//my object class


class Sale
{


public:

	//use of the ostream operator
	friend std::ostream& operator <<(std::ostream &out, const Sale &sales);

	// Equality operator so that the sales can be compared.
	friend bool operator ==(const Sale &prod1,
		const Sale &prod2);
	

	// Less than operator so that sales can be compared.
	friend bool operator <(const Sale &prod1,
		const Sale &prod2);
	

	//constructor
	Sale();
	Sale(int items, int transNum, double transToatal);

	//no copying or assignment needed

	//accessors
	double getTotal() const;
	int getTransNum() const;
	int getItemCount() const;
	void outPut() const;

	// Give back hash value for this product.
	int hash() const;

	//mutator
	void setTrans(int items, int transNum, double transToatal);


	

	

private:
	//for the each item
	int items;

	//transaction number (unique identifier)
	int transNum;

	//total for the transaction
	double transTotal;


};
