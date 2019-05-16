/*Jason Glenn
Data Structure and Algorithms
Final Project: Movie theatre
Description:
This project is a simulation of a POS system that a ticket counter and manager could use.
I implemented the use of queues, hash table with chaining, comparing objects and searching for items(transactions)
*/



#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm> //allow for searching

#include "sale.h"
#include "queue.cpp"
#include "list.cpp"
#include "seatChart.cpp"


using namespace std;

//const variables
const int NUMROW = 10;
const int NUMCOL = 10;
const char UNAVAILABLE = 'x';
const char AVAILABLE = 'o';
const int LASTMENUCHOICE = 4;
const int FIRSTMENUCHOICE = 1;

//global variables
int transaction = 1;






//validation functions
bool validateOption(int option);
bool validateRow(const int &row);
bool validateCol(const int &col);
void ticketPrice(int &rowselect, double &price);
bool validateTransaction(const int &num);
// Print a product.
void printSale(Sale &sale);
//seat chart
void seatChart(char **seat);

#undef main

int main()
{

	//theatre being open
	bool open = true;

	int option;  //menu option
	int rowselect; //slection of the row

	//sale record
	//is of type sale to access sale class
	HashTable<Sale> sold2(NUMCOL*NUMROW);

	
	
	//hold transactions that were search up for returns
	HashTable<Sale> returnedSale(NUMCOL*NUMROW);

	//initialize 2d pointer
	char **seat;

	//set first rows size
	seat = new char *[NUMROW];

	//set all seats to AVAILABLE
	for (int i = 0; i < NUMROW; i++)
	{
		//set the size of the col
		seat[i] = new char[NUMCOL];
		for (int j = 0; j < NUMCOL; j++)
		{
			seat[i][j] = AVAILABLE;
		}
	}

	//keeps loop going
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

		//used throughout for true/false validation
		bool valid;

		
		//validate option
		if (!validateOption(option))
		{
			cout << "Invalid entry please reenter your option" << endl;
		}
		else //continue if the option was valid
		{
	
			switch (option)
			{
				
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

				//adds the ticket number for each ticket to display which seat will be for which ticket
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


					//if invalid continue to ask till valid row
					while (!validateRow(reqRow))//CHANGED: from using valid
					{
						cout << "invalid row entry, please reenter valid row selection." ;
						cin >> reqRow;

						validateRow(reqRow);
					}

					cout << endl;
					
					//if invalid continue to ask till valid seat(column)
					while (!validateCol(reqCol))
					{
						cout << "invalid seat entry, please reenter valid row selection." ;
						cin >> reqCol;

						validateCol(reqCol);
					}

					
					cout << endl;

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
						cout << "Sold Ticket Price: $" << price <<endl;
						cout << "Total sale: $" << totalticketsale << endl << endl;


					}// Not AVAILABLE - already sold (#)
					else
					{
						valid = false;
						while (!valid)
						{
							// Tell user that seat is already sold
							cout << "Sorry, This seat is already taken.";
							cout << "Please choose another seat." << endl;

							//get and validate row and col
							cout << "Please select you seat for ticket #" << custQueue.front() << endl;
							cout << "please enter the row ";
							cin >> reqRow;

							cout << endl;

							cout << "Please enter the seat ";
							cin >> reqCol;

							cout << endl;
							

							//if invalid continue to ask till valid row
							while (!validateRow(reqRow))
							{
								cout << "invalid row entry, please reenter valid row selection." << endl;
								cin >> reqRow;

								validateRow(reqRow);
							}

							cout << endl;

							
							//if invalid continue to ask till valid seat(column)
							while (!validateCol(reqCol))
							{
								cout << "invalid seat entry, please reenter valid row selection." << endl;
								cin >> reqCol;
								validateCol(reqCol);
							}

							cout << endl;

							if (seat[reqRow - 1][reqCol - 1] == 'o')
							{
								//set the seat as now UNAVAILABLE
								seat[reqRow - 1][reqCol - 1] = 'x';

								//preceed to prcess payment of seat
								ticketPrice(rowselect, price);
								// Add a sold ticket price to the total sale amount (price is variable overwritten for each purchase, totalticketsale is global variable that has each price added to it)
								totalticketsale += price;

								cout << "Sold Ticket Price: $" << price <<  endl;
								cout << "Total sale: $" << totalticketsale << endl << endl;

								//sentinel change
								valid = true;

							}

						}
					}

					custQueue.del();

				}//end queue

				//add new sale
				Sale newSale;
				newSale.setTrans(size, transaction, totalticketsale);

				//adding each new sale to the hash table
				// Add to hash table and display.
				if (!sold2.add(newSale.hash(), newSale))
					cout << "No room!" << endl;
				newSale.outPut();
				cout << endl << endl;

				//increment transaction number
				transaction++;
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

				
				Sale singleSale;
				

				singleSale.setTrans(0, searchedTrans, 0.0);

				bool found;

				
				found = sold2.find(singleSale.hash(), singleSale);

				if (!found)
					cout << "No transaction found for # \"" << searchedTrans << "\"" << endl;
				else
				{
					
					cout << "Found transaction: " << searchedTrans << endl;

					//display the transaction to be removed
					singleSale.outPut();

					cout << "solds output" << endl;
					
					//add the remove item to the returns list
					returnedSale.add(singleSale.hash(), singleSale);
					sold2.del(singleSale.hash(), singleSale);
				
					cout << endl << endl;
				}

				break;
				
			}//end case 2
			case 3: //listing of the sold tickets and the returned tickets
			{
				cout << "Sales for the day" << endl;

				int search = 1;
				int returned = 1;

				
				//outputs all the sales that weren't returned
				while (search < NUMROW)
				{
					Sale singleSale;

					singleSale.setTrans(0, search, 0.0);

					bool found;

					found = sold2.find(singleSale.hash(), singleSale);

						singleSale.outPut();
						
						cout << endl << endl;
						search++;

				}

				cout << endl << endl;

				//outputs just the reurns
				cout << "the returns of the day" << endl;
				while (returned < NUMROW)
				{
					Sale singleSale;
					

					singleSale.setTrans(0, returned, 0.0);

					bool found;

	
					found = returnedSale.find(singleSale.hash(), singleSale);

				
						singleSale.outPut();
						
						cout << endl << endl;
						returned++;
					
					
				}
				
				
			}//end of case 3

			case 4:
			{
				//sets open to false
				open = false;

			}//end case for

			}//end of switch




		}//end of else



	}//end of while

	// dealocate 2d array
		for (int i = 0; i < NUMROW; i++)
			delete[] seat[i];

	delete[] seat;

	return 0;

}

//display of seat chart
void seatChart(char **seat)
{
	

	// Display seat table legend
	cout << "o = Seats AVAILABLE\n";
	cout << "x = Seats UNAVAILABLE\n";
	cout << "Seats ";
	for (int i = 0; i < NUMCOL; i++)
	{
		cout << setw(3) << (i + 1);
	}
	
	cout << endl;
	for (int row = 0; row < NUMROW; row++)
	{
		// Beginning of each row
		// Note: display of "row number" is added by 1, row++ increments row and stores the new value as row, row + 1 will add 1 to row and not store its new value, this adjustment is because the array begins at 0 and not 1

		cout << "Row" << setw(3) << (row + 1);

		// Content of each row
		for (int col = 0; col < NUMCOL; col++)
		{
			cout << setw(3) << seat[row][col];
		}
		// End of row
		cout << endl;
	}

}


// Print a product.
void printSale(Sale &sale)
{
	sale.outPut();
	cout << endl << endl;
}



//validate the entry of the option
bool validateOption(int option)
{

	//check if the digit is now within range
	if (option <= LASTMENUCHOICE && option >= FIRSTMENUCHOICE)//changed to and
		return true;

	return false;
}

bool validateRow(const int &row)
{
	
		//check if the range in the row is valid
		//user will enter 1 but row starts with 0 based
	if (row <= NUMROW && row > 0)//changed to and
		return true;
	

	return false;
}


bool validateCol(const int &col)
{
	
		//check if the range in the row is valid
		//user will enter 1 but row starts with 0 based
	if (col <= NUMCOL && col > 0)
		return true;
	


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

	if (num <= transaction && num >= 1)
	{
		valid = true;
		return valid;
	}


	return valid;
}