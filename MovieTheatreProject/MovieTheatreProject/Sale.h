#pragma once

#ifndef SALE_H
#define SALE_H

using namespace std;


class  Sale {
	

public:

	//constructor
	Sale();
	Sale(int items, int transNum, double transToatal);

	//copy constructor

	//assingment

	//accessors
	double getTotal() const;
	int getTransNum() const;
	int getItemCount() const;

	void setTrans(int items, int transNum, double transToatal);
	

	void outPut() const;

	//int findTrans(const SearchList &transNum1, const SearchList &transNum2);

private:
	//for the each item
	int items;

	//transaction number (unique identifier)
	int transNum;

	//total for the transaction
	double transTotal;

	
};

// Equality operator so that products can be compared.
bool operator ==(const Sale &prod1,
	const Sale &prod2);
// Postcondition: Compare as equal if have same id.

// Less than operator so that products can be compared.
bool operator <(const Sale &prod1,
	const Sale &prod2);
// Postcondition: Compare as less than if id of first is
// less than id of second.

#endif // !SALE_H