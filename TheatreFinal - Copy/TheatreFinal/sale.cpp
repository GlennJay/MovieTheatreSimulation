/*Jason Glenn
Data Structure and Algorithms
Final Project: Movie theatre
Description:
This project is a simulation of a POS system that a ticket counter and manager could use.
I implemented the use of queues, hash table with chaining, comparing objects and searching for items(transactions)
*/

#include <iostream>
#include <iomanip>

#include "sale.h"



Sale::Sale() {

	//initailize variables
	transNum = 0;
	transTotal = 0.0;
	items = 0;
}

//adding the values to data memeber
Sale::Sale(int itemCount, int newTransNum, double newTransTotal)
{
	//using set instead of extra code
	setTrans(itemCount, newTransNum, newTransTotal);

}

//accessor functions
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

	return transNum;//key
}

void Sale::setTrans(int itemCount, int newTransNum, double newTransTotal)
{
	items = itemCount;
	transNum = newTransNum;
	transTotal = newTransTotal;
}

void Sale::outPut() const
{
	//returns if there is nothing to return 
	//this is useful for the out of the returns in main function
	if (items == 0 && transTotal == 0)
	{
		return;
	}
	//transaction header

	std::cout << "********************" << std::endl;
	std::cout << "*Tranaction Summary*" << std::endl;
	std::cout << "********************" << std::endl;

	std::cout << "Transaction Number: " << transNum << std::endl;
	std::cout << "Transaction Total:  " << transTotal << std::endl;
	std::cout << "Seats sold:         " << items << std::endl;


}


//comaprison operators
bool operator==(const Sale & prod1, const Sale & prod2)
{
	return prod1.getTransNum() == prod2.getTransNum();
}

bool operator<(const Sale & prod1, const Sale & prod2)
{
	return prod1.getTransNum() < prod2.getTransNum();
}

//ostream is used to output the sale object by inserting the get(mutator functions)
std::ostream& operator <<(std::ostream& out, const Sale &sale)
{
	

	out << "********************\n"  
		<< "*Tranaction Summary*\n" 
	    << "********************\n" 

	 << "Transaction Number: " << sale.getTransNum() << "\n" 
	 << "Transaction Total:  " << sale.getTotal() << " \n"
	 << "Seats sold:         " << sale.getItemCount();

	return out;
}