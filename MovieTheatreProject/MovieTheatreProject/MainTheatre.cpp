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


#include "Queue.cpp"
#include "searchList.cpp"
#include "Sale.h"

template <class T> //CHANGE: to dynamic array
void seatChart(vector<vector<T>> seat, const int &row, const int &col)
{
	//CHANGE: create variable to output the row and seat(column)
	int i, j;

	// Display seat table legend
	cout << "o = Seats Available\n";
	cout << "x = Seats Unavailable\n";
	cout << "Seats:  1  2  3  4  5  6  7  8  9  10" << endl;

	// Loop to generate the rows
	for (i = 0; i < row; i++) {
		// Beginning of each row
		// Note: display of "row number" is added by 1, i++ increments i and stores the new value as i, i + 1 will add 1 to i and not store its new value, this adjustment is because the array begins at 0 and not 1
		cout << "Row" << setw(3) << (i + 1);
		// Content of each row
		for (j = 0; col > j; j++) {
			cout << setw(3) << seat[i][j];
		}
		// End of row
		cout << endl;
	}
}


bool validateOption(int option);
bool validateRow(const int &row);
bool validateCol(const int &col);
void ticketPrice(int &rowselect, double &price);
bool validateTransaction(const int &num);

//const variables CHANGE: UPPERCASE
const int numRow = 10;
const int numCol = 10;
const char unavailable = 'x';
const char available = 'o';
const int lastMenuChoice = 4;
const int firstMenuChoice = 1;

//global variables
int transaction = 1;



using namespace std;

int main()
{

	//initialize variables



	//total of the ticket
	//double ticketTotal;

	//theatre being open
	bool open = true;

	int option;
	//int i, j;
	//char rowUI, colUI;
	//int row, col;
	int rowselect;

	//sale record
	//is of type sale to access sale class
	SearchList<Sale> sold;

	//vector to hold transactions that were search up for returns
	vector<Sale> returnedSale;


	//initialize 2d vector for seating
	vector<vector<char>> seat(numRow, vector<char>(numCol));

	//set all seats to available
	for (int i = 0; i < numRow; i++)
	{
		for (int j = 0; j < numCol; j++)
		{
			seat[i][j] = available;
		}
	}


	while (open)
	{
		//display seating chart
		seatChart(seat, numRow, numCol);


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
				//option 1 will change the available seats to unavailable. if chosen seat is unavailable it will display a resubmission
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
					custQueue.add(ticketNum);
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

					//buy tickets if it is available 'o'
					//user will enter based on 1 as the start
					//decrement the request to validate in vector 0 based
					if (seat[reqRow - 1][reqCol - 1] == 'o')
					{
						//set the seat as now unavailable
						seat[reqRow - 1][reqCol - 1] = 'x';

						//preceed to prcess payment of seat
						ticketPrice(reqRow, price);
						// Add a sold ticket price to the total sale amount (price is variable overwritten for each purchase, totalticketsale is global variable that has each price added to it)
						totalticketsale += price;
						cout << "Sold Ticket Price: $" << price << endl;
						cout << "Total sale: $" << totalticketsale << endl << endl;

						
					}// Not available - already sold (#)
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
								//set the seat as now unavailable
								seat[reqRow - 1][reqCol - 1] = 'o';

								//preceed to prcess payment of seat
								ticketPrice(rowselect, price);
								// Add a sold ticket price to the total sale amount (price is variable overwritten for each purchase, totalticketsale is global variable that has each price added to it)
								totalticketsale += price;

								cout << "Sold Ticket Price: $" << price << endl ;
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
				newSale.setTrans(size,transaction,totalticketsale);

				sold.add(newSale);

				 sold.display();

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

				found = sold.find(singleSale);

				if (!found)
					cout << "No transaction found for # \"" << searchedTrans << "\"" << endl;
				else
				{
					//CHANGE: to remove the sale from single sale
					cout << "Found transaction: " << searchedTrans << endl;
					singleSale.outPut();
					returnedSale.push_back(singleSale);
					cout << endl << endl;
				}

				break;
				//cout << "end case 2 " << endl;
			}//end case 2
			case 3: //listing of the sold tickets and the returned tickets
			{
				cout << "case 3" << endl;
			
				

				 //print out all the transactions in sold
				//while (!sold.isEmpty())
				//{
					sold.display();
				//}

				//print out all the returns 
				cout << "end case 3" << endl;
			}//end of case 3


			}//end of switch




		}//end of else


		
	}//end of while
		
	
	return 0;
	
}



////get initial size of the group
//int groupSize = 0;
//
//
//
//cin >> groupSize;
//cin.get(); //eats line
//
////initialize object with size
//Person<int> person(groupSize);
//
////while in line get ages for ticket prices
//
//
//
//
////get input for the movie
//
//
//
///



//seat display for any type of vector
//template<typename T>
//void seatChart(vector<vector<T>> seat, const int &row, const int &col)
//{
//	int i, j;
//
//	// Display seat table legend
//	cout << "o = Seats Available\n";
//	cout << "x = Seats Unavailable\n";
//	cout << "Seats:  1  2  3  4  5  6  7  8  9  10" << endl;
//
//	// Loop to generate the rows
//	for (i = 0; i < row; i++) {
//		// Beginning of each row
//		// Note: display of "row number" is added by 1, i++ increments i and stores the new value as i, i + 1 will add 1 to i and not store its new value, this adjustment is because the array begins at 0 and not 1
//		cout << "Row" << setw(3) << (i + 1);
//		// Content of each row
//		for (j = 0; numCol > j; j++) {
//			cout << setw(3) << seat[i][j];
//		}
//		// End of row
//		cout << endl;
//	}
//}

//validate the entry of the option
bool validateOption(int option)
{
		//bool valid = false;

		//check if the digit is now within range
		if (option <= lastMenuChoice || option >= firstMenuChoice)
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
		if (row <= numRow || row > 0)
			return true;
			//valid = true;
	
	return false;
}


bool validateCol(const int &col)
{
	//bool valid = false;

	
		//check if the range in the row is valid
		//user will enter 1 but row starts with 0 based
		if (col <= numCol || col > 0)
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