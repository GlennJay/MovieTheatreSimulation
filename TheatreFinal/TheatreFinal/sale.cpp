#include <iostream>
#include <iomanip>

#include "sale.h"



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

int Sale::hash() const
{
	int sum = 0;

	// Add up all the characters in id as hash value--
	// NOT NECESSARILY A GOOD HASHING METHOD.
	//for (unsigned i = 0; i < trans; i++)
	//	sum += transNum[i];

	return transNum;//sum;
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
	std::cout << "********************" << std::endl;
	std::cout << "*Tranaction Summary*" << std::endl;
	std::cout << "********************" << std::endl;

	std::cout << "Transaction Number: " << transNum << std::endl;
	std::cout << "Transaction Total:  " << transTotal << std::endl;
	std::cout << "Seats sold:         " << items << std::endl;


}



bool operator==(const Sale & prod1, const Sale & prod2)
{
	return prod1.getTransNum() == prod2.getTransNum();
}

bool operator<(const Sale & prod1, const Sale & prod2)
{
	return prod1.getTransNum() < prod2.getTransNum();
}

////std::ostream& operator <<(std::ostream& out, const Sale sale)
std::ostream& operator <<(std::ostream& out, const Sale &sale)
{
	//out << sale.getTotal();

	out << "********************\n"  
		<< "*Tranaction Summary*\n" 
	    << "********************\n" 

	 << "Transaction Number: " << sale.getTransNum() << "\n" 
	 << "Transaction Total:  " << sale.getTotal() << " \n"
	 << "Seats sold:         " << sale.getItemCount();

	return out;
}