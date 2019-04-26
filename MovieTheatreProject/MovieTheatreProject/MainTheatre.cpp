/*Jason Glenn
Data Structure and Algorithms 
Final Project: Movie theatre
Description:
This project is a simulation of a movie theatre expierence. My goal is to make this program as close as possible to real life situations
*/



#include <iostream>
#include <iomanip>
#include <iterator>
#include "Person.cpp"
#include "MovieQueue.cpp"
#include "MovieList.cpp"

// 12 years old and under
const double CHILD_TICKET = 10.69;
//13 years of old to 64
const double ADULT_TICKET = 13.69;
//ages 65 and over
const double SENIOR_TICKET = 12.69;

using namespace std;

int main()
{


	//get initial size of the group
	int groupSize = 0;

	cout << "Welcome to the Showcase DeGlenn " << endl;
	cout << "How many people are in you party?  ";

	cin >> groupSize;
	cin.get(); //eats line
	
	Person<int> person(groupSize);

	//while in line get ages for ticket prices
	int tickets = 1;
	MovieQueue<int> ticketLine(groupSize);
	while (!ticketLine.isFull() && tickets <= groupSize)
	{
		
		int age = 0;
		

		cout << "how old is the person for ticket #" << tickets << endl;
		cin >> age;
		person.setAge(age);

		if (person.getAge() <= 12)
		{
			person.lineTotal(CHILD_TICKET);
			tickets++;
		}
		else if (person.getAge() >= 13 && person.getAge() <= 64)
		{
			person.lineTotal(ADULT_TICKET);
			tickets++;
		}
		else
		{
			person.lineTotal(SENIOR_TICKET);
			tickets++;
		}



	}

	 person.totalOutPut();

	 //concession stand 
	 MovieQueue<int> concessionLine = ticketLine;

	 while (!concessionLine.isFull())
	 {
		 cout << "hope your hungry " << endl;

	 }
	
	
	
	return 0;
}

