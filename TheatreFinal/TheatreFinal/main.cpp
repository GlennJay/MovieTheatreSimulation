/*Jason Glenn
Data Structure and Algorithms
Final Project: Movie theatre
Description:
This project is a simulation of a movie theatre expierence. My goal is to make this program as close as possible to real life situations
*/



#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm> //allow for searching

#include "sale.h"
#include "queue.cpp"
#include "list.cpp"


using namespace std;

//const variables CHANGE: UPPERCASE
const int NUMROW = 10;
const int NUMCOL = 10;
const char UNAVAILABLE = 'x';
const char AVAILABLE = 'o';
const int LASTMENUCHOICE = 4;
const int FIRSTMENUCHOICE = 1;

//global variables
int transaction = 1;



template <class T> //CHANGE: to dynamic array
void seatChart(std::vector<std::vector<T>> seat)
{
	//CHANGE: create variable to output the row and seat(column)
	//int i, j;

	// Display seat table legend
	cout << "o = Seats AVAILABLE\n";
	cout << "x = Seats UNAVAILABLE\n";
	cout << "Seats:  1  2  3  4  5  6  7  8  9  10" << endl;

	for (int row = 0; row < NUMROW; row++)
	{
		// Beginning of each row
		// Note: display of "row number" is added by 1, row++ increments row and stores the new value as row, row + 1 will add 1 to row and not store its new value, this adjustment is because the array begins at 0 and not 1

		std::cout << "Row" << std::setw(3) << (row + 1);

		// Content of each row
		for (int col = 0; col < NUMCOL; col++)
		{
			std::cout << std::setw(3) << seat[row][col];
		}
		// End of row
		std::cout << std::endl;
	}



	// Loop to generate the rows
	//for (i = 0; i < row; i++) {
	//	// Beginning of each row
	//	// Note: display of "row number" is added by 1, i++ increments i and stores the new value as i, i + 1 will add 1 to i and not store its new value, this adjustment is because the array begins at 0 and not 1
	//	cout << "Row" << setw(3) << (i + 1);
	//	// Content of each row
	//	for (j = 0; col > j; j++) {
	//		cout << setw(3) << seat[i][j];
	//	}
	//	// End of row
	//	cout << endl;
	//}
}


bool validateOption(int option);
bool validateRow(const int &row);
bool validateCol(const int &col);
void ticketPrice(int &rowselect, double &price);
bool validateTransaction(const int &num);

////const variables CHANGE: UPPERCASE
//const int NUMROW = 10;
//const int NUMCOL = 10;
//const char UNAVAILABLE = 'x';
//const char AVAILABLE = 'o';
//const int LASTMENUCHOICE = 4;
//const int FIRSTMENUCHOICE= 1;





#undef main

int main()
{



	//theatre being open
	bool open = true;

	int option;
	int rowselect;

	//sale record
	//is of type sale to access sale class
	//SearchList<Sale> sold;
	HashTable<Sale> sold2(NUMCOL*NUMROW);

	//list<Sale> history;
	
	//vector to hold transactions that were search up for returns
	HashTable<Sale> returnedSale(NUMCOL*NUMROW);

	//initialize 2d vector for seating
	vector<vector<char>> seat(NUMROW, vector<char>(NUMCOL));

	//set all seats to AVAILABLE
	for (int i = 0; i < NUMROW; i++)
	{
		for (int j = 0; j < NUMCOL; j++)
		{
			seat[i][j] = AVAILABLE;
		}
	}


	while (open)
	{
		//display seating chart
		seatChart(seat);


		// Display Menu selections
		cout << "\nTicket Sales Menu:\n\n";
		cout << "1)  Purchase Ticket\n";
		cout << "2)  Returns Search\n";
		cout << "3)  List Transaction Report\n";
		cout << "4)  Exit\n\n";
		cout << "=========================\n";
		cout << "Enter Menu Choice: ";
		cin >> option;
		cout << endl << endl;

		bool valid;

		valid = validateOption(option);
		//validate option
		if (!valid)
		{
			cout << "Invalid entry please reenter your option" << endl;
		}
		else //continue if the option was valid
		{
			//cout << "before switch " << endl;
			switch (option)
			{
				//cout << "switch" << endl;
				//option 1 will change the AVAILABLE seats to UNAVAILABLE. if chosen seat is UNAVAILABLE it will display a resubmission
			case 1: {

				double totalticketsale = 0.00;

				//group size
				int size;

				//user requested row 
				int reqRow;

				//user requested col
				int reqCol;

				//display transaction number
				cout << "Transaction number: " << transaction << endl;

				//get group size to know how many in the line
				cout << "How many tickets will you need? ";
				cin >> size;

				cout << endl << endl;

				//initiale queue
				//sets size for queue
				int ticketNum = 1;
				Queue<int> custQueue(size);

				while (!custQueue.isFull() && ticketNum <= size)
				{
					custQueue.addQ(ticketNum);
					ticketNum++;
				}

				// go through the line getting price of each person in line
				while (!custQueue.isEmpty())
				{
					//price of seat
					double price = 0;

					//get and validate row and col
					cout << "Please select you seat for ticket #" << custQueue.front() << endl;
					cout << "please enter the row ";
					cin >> reqRow;

					cout << "Please enter the seat ";
					cin >> reqCol;

					cout << endl;

					valid = validateRow(reqRow);//= reqRow;
					//cout << "after validate row\n";

					//if invalid continue to ask till valid row
					while (!valid)//!validateRow(reqRow))
					{
						cout << "invalid row entry, please reenter valid row selection." << endl;
						cin >> reqRow;

						valid = validateRow(reqRow);
					}

					//validate selection
					valid = validateCol(reqCol);
					//cout << "after validate col\n";
					//if invalid continue to ask till valid seat(column)
					while (!valid)//!validateCol(reqCol))
					{
						cout << "invalid row entry, please reenter valid row selection." << endl;
						cin >> reqCol;
						validateCol(reqCol);
						valid = reqCol;
					}

					bool validSeat;

					//validSeat = seat[reqRow - 1][reqCol - 1];

					//buy tickets if it is AVAILABLE 'o'
					//user will enter based on 1 as the start
					//decrement the request to validate in vector 0 based
					if (seat[reqRow - 1][reqCol - 1] == 'o')
					{
						//set the seat as now UNAVAILABLE
						seat[reqRow - 1][reqCol - 1] = 'x';

						//preceed to prcess payment of seat
						ticketPrice(reqRow, price);
						// Add a sold ticket price to the total sale amount (price is variable overwritten for each purchase, totalticketsale is global variable that has each price added to it)
						totalticketsale += price;
						cout << "Sold Ticket Price: $" << price << endl;
						cout << "Total sale: $" << totalticketsale << endl << endl;


					}// Not AVAILABLE - already sold (#)
					else
					{
						validSeat = false;
						while (!validSeat)
						{
							// Tell user that seat is already sold
							cout << "Sorry, This seat is already taken.";
							cout << "Please choose another seat." << endl;

							//get and validate row and col
							cout << "Please select you seat for ticket #" << custQueue.front() << endl;
							cout << "please enter the row ";
							cin >> reqRow;

							cout << "Please enter the seat ";
							cin >> reqCol;

							valid = validateRow(reqRow);//= reqRow;
							//cout << "after validate row\n";

							//if invalid continue to ask till valid row
							while (!valid)//!validateRow(reqRow))
							{
								cout << "invalid row entry, please reenter valid row selection." << endl;
								cin >> reqRow;

								valid = validateRow(reqRow);
							}

							//validate selection
							valid = validateCol(reqCol);
							//cout << "after validate col\n";
							//if invalid continue to ask till valid seat(column)
							while (!valid)//!validateCol(reqCol))
							{
								cout << "invalid row entry, please reenter valid row selection." << endl;
								cin >> reqCol;
								validateCol(reqCol);
								valid = reqCol;
							}

							if (seat[reqRow - 1][reqCol - 1] == 'x')
							{
								//set the seat as now UNAVAILABLE
								seat[reqRow - 1][reqCol - 1] = 'o';

								//preceed to prcess payment of seat
								ticketPrice(rowselect, price);
								// Add a sold ticket price to the total sale amount (price is variable overwritten for each purchase, totalticketsale is global variable that has each price added to it)
								totalticketsale += price;

								cout << "Sold Ticket Price: $" << price << endl;
								cout << "Total sale: $" << totalticketsale << endl << endl;




								validSeat = true;

							}

						}
					}

					//add this groups sale to the day
					//sold.addRear(size, transaction, totalticketsale);

					custQueue.del();

				}//end queue

				//add new sale
				Sale newSale;
				newSale.setTrans(size, transaction, totalticketsale);

				// Add to hash table and display.
				if (!sold2.add(newSale.hash(), newSale))
					cout << "No room!" << endl;
				newSale.outPut();
				cout << endl << endl;

				//history.push_front(newSale);

				//sold.add(newSale);
				//sold2.addlist(newSale);

				//newSale.outPut();

				//sold.display();

				//increment transaction number
				transaction++;
				//cout << "end queue " << endl;

				break;
			}//end case 1
			case 2: {

				//transaction number
				int searchedTrans;

				//Transaction search
				cout << "Please enter the transaction number: ";
				cin >> searchedTrans;

				cout << endl;

				//validate search
				validateTransaction(searchedTrans);

				while (!validateTransaction(searchedTrans))
				{
					cout << "invalid transaction number.";

					cout << "Please enter the transaction number You want to look up: ";
					cin >> searchedTrans;

					cout << endl;
					//validate search
					validateTransaction(searchedTrans);
				}

				//SearchList<Sale> sales;
				Sale singleSale;
				//findSale.addRear(0, searchedTrans, 0);

				singleSale.setTrans(0, searchedTrans, 0.0);

				bool found;

				//found = sold.find(singleSale);
				found = sold2.find(singleSale.hash(), singleSale);

				if (!found)
					cout << "No transaction found for # \"" << searchedTrans << "\"" << endl;
				else
				{
					//CHANGE: to remove the sale from single sale
					cout << "Found transaction: " << searchedTrans << endl;
					singleSale.outPut();
					returnedSale.add(singleSale.hash(), singleSale);
					//cout << returnedSale.front();
					//CHANGE: remove the transaction from the linked list to only hold sales that weren't returned
					cout << endl << endl;
				}

				break;
				//cout << "end case 2 " << endl;
			}//end case 2
			case 3: //listing of the sold tickets and the returned tickets
			{
				cout << "Sales for the day" << endl;

				int search = 1;
				int returned = 1;

				

				while (search < NUMROW)
				{
					Sale singleSale;
					//findSale.addRear(0, searchedTrans, 0);

					singleSale.setTrans(0, search, 0.0);

					bool found;

					//found = sold.find(singleSale);
					found = sold2.find(singleSale.hash(), singleSale);

					if (!found)
					{
						//cout << "No transactions \"" << search << "\"" << endl;
						break;
					}
					else
					{
						//CHANGE: to remove the sale from single sale
						//cout << "Found transaction: " << search << endl;
						singleSale.outPut();
						//returnedSale.push_back(singleSale);
						//CHANGE: remove the transaction from the linked list to only hold sales that weren't returned
						cout << endl << endl;
						search++;
					}

					//break;

				}



				cout << "the returns of the day" << endl;
				while (returned < NUMROW)
				{
					Sale singleSale;
					//findSale.addRear(0, searchedTrans, 0);

					singleSale.setTrans(0, returned, 0.0);

					bool found;

					//found = sold.find(singleSale);
					found = returnedSale.find(singleSale.hash(), singleSale);

					if (!found)
					{
						//cout << "No transactions \"" << returned << "\"" << endl;
						//break;
						returned++;
						
					}
					else
					{
						//CHANGE: to remove the sale from single sale
						//cout << "Found transaction: " << search << endl;
						singleSale.outPut();
						//returnedSale.push_back(singleSale);
						//CHANGE: remove the transaction from the linked list to only hold sales that weren't returned
						cout << endl << endl;
						returned++;
					}
					
				}
				
				
			}//end of case 3


			}//end of switch




		}//end of else



	}//end of while


	return 0;

}






//validate the entry of the option
bool validateOption(int option)
{
	//bool valid = false;

	//check if the digit is now within range
	if (option <= LASTMENUCHOICE || option >= FIRSTMENUCHOICE)
		return true;
	//valid = true;

	return false;
}

bool validateRow(const int &row)
{
	//bool valid = false;

	//check if entry is a digit


		//check if the range in the row is valid
		//user will enter 1 but row starts with 0 based
	if (row <= NUMROW || row > 0)
		return true;
	//valid = true;

	return false;
}


bool validateCol(const int &col)
{
	//bool valid = false;


		//check if the range in the row is valid
		//user will enter 1 but row starts with 0 based
	if (col <= NUMCOL || col > 0)
		return true;
	//valid = true;


	return false;
}

//Prices for each row of the theater.
void ticketPrice(int &rowselect, double &price) {
	// Change price based on row...the closer the row, the more expensive
	switch (rowselect) {
	case 1: {
		price = 80.00;
		break;
	}

	case 2: {
		price = 75.00;
		break;
	}

	case 3: {
		price = 70.00;
		break;
	}

	case 4: {
		price = 65.00;
		break;
	}

	case 5: {
		price = 60.00;
		break;
	}

	case 6: {
		price = 55.00;
		break;
	}

	case 7: {
		price = 50.00;
		break;
	}

	case 8: {
		price = 45.00;
		break;
	}

	case 9: {
		price = 40.00;
		break;
	}

	case 10: {
		price = 35.00;
		break;
	}
	}

}

//validate searched transaction number
bool validateTransaction(const int &num)
{
	//validate if it is a digit
	bool valid = false;

	//check if the digit is now within range

	if (num <= transaction || num >= 1)
	{
		valid = true;
		return valid;
	}

	//if there is no transaction history 
	if (num <= 0)
	{
		return valid;
	}


	return valid;
}