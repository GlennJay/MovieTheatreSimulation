#include "Person.h"


#include <iostream>
#include <iomanip>

using namespace std;

//constructors

template<class S> //default
Person<S>::Person()
{
	groupSize = 2;
	person = new S[groupSize];
}

template<class S>
Person<S>::Person(int size)
{
	groupSize = size;
	person = new S[size];
	age = NULL;
}

template<class S>
Person<S>::Person(const Person<S>& otherPerson)
{
	//copy data members
	age = otherPerson.age;
	total = otherPerson.total;
	groupSize = otherPerson.groupSize;

	//allocate array
	person = new S[groupSize];

	for (int i = 0; i < groupSize; i++)
	{
		person[i] = otherPerson[i];
	}



}

template<class S>
Person<S>& Person<S>::operator=(const Person<S>& otherPerson)
{
	//copy data members
	age = otherPerson.age;
	total = otherPerson.total;
	groupSize = otherPerson.groupSize;

	delete[] person;

	//allocate array
	person = new S[groupSize];

	for (int i = 0; i < groupSize; i++)
	{
		person[i] = otherPerson[i];
	}
}




template<class S>
Person<S>::~Person()
{
	//reset data members and deallocate array
	groupSize = 0;
	total = 0;
	age = 0;

	delete[] person;
	person = NULL;



}

template<class S>
int Person<S>::getAge() const
{
	return age;
}

template<class S>
void Person<S>::lineTotal(double price)
{
	total += price;
}

template<class S>
void Person<S>::totalOutPut()
{
	cout << "the total is " <<  total;
}

template<class S>
void Person<S>::setAge(int num)
{
	//automatically sets num to one if under 1 years old
	if (num <= 0)
	{
		age = 1;
	}
	else
	{
		age = num;
	}

	//add age to person
	for (int i = 0; i <= groupSize; i++)
	{

		if (person[i] == S())
		{
			person[i] = age;
			break;
		}
	}

}


