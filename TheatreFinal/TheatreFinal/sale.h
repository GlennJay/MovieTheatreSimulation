#pragma once

#include <iostream>

//using namespace std;


class Sale
{


public:

	/*friend std::ostream& operator <<(std::ostream& out, const Sale sales);*/
	friend std::ostream& operator <<(std::ostream &out, const Sale &sales);

	// Equality operator so that products can be compared.
	friend bool operator ==(const Sale &prod1,
		const Sale &prod2);
	// Postcondition: Compare as equal if have same id.

	// Less than operator so that products can be compared.
	friend bool operator <(const Sale &prod1,
		const Sale &prod2);
	// Postcondition: Compare as less than if id of first is
	// less than id of second.

	//constructor
	Sale();
	Sale(int items, int transNum, double transToatal);

	//copy constructor

	//assingment

	//accessors
	double getTotal() const;
	int getTransNum() const;
	int getItemCount() const;
	// Give back hash value for this product.
	int hash() const;

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
