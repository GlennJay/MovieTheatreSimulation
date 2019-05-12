#include <iostream>
#include <iomanip>

#include "Sale.h"

Sale::Sale() {

	//initailize variable
	transNum = 0;
	transTotal = 0.0;
	items = 0;
}

Sale::Sale(int itemCount, int newTransNum, double newTransTotal)
{

	items = itemCount;
	transNum = newTransNum;
	transTotal = newTransTotal;

	//using set to make sure that the values are valid
	//setTrans(items, transNum, transTotal);

}


double Sale::getTotal() const
{
	return transTotal;
}

int Sale::getTransNum() const
{
	return transNum;
}

int Sale::getItemCount() const
{
	return items;
}

void Sale::setTrans(int itemCount, int newTransNum, double newTransTotal)
{
	items = itemCount;
	transNum = newTransNum;
	transTotal = newTransTotal;
}

void Sale::outPut() const
{
	//transaction header
			cout << "********************" << endl;
			cout << "*Tranaction Summary*" << endl;
			cout << "********************" << endl;

			cout << "Transaction Number: " << transNum << endl;
			cout << "Transaction Total:  " << transTotal << endl;
			cout << "Seats sold:         " << items << endl;
			

}



bool operator==(const Sale & prod1, const Sale & prod2)
{
	return prod1.getTransNum() == prod2.getTransNum();
}

bool operator<(const Sale & prod1, const Sale & prod2)
{
	return prod1.getTransNum() < prod2.getTransNum();
}
