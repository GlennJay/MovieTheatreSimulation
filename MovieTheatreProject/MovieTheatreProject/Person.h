#pragma once
#include <list>
#include <iostream>


using namespace std;

template<class S>
class Person
{
public:
	//constructors

	//default 
	Person();

	Person(int size);

	//copyconstructor
	Person(const Person<S> &otherPerson);

	//assignment
	Person<S> &operator=(const Person<S> &otherPerson);


	//destructor
	~Person();

	//accessors
	int getAge() const;

	//keeps track off total
	void lineTotal(double price);

	//outputs total
	void totalOutPut();

	//mutators
	void setAge(int num);




private:
	//age of person
	int age;

	//pointer to hold group
	S *person;

	//group size
	int groupSize;

	//price totals
	double total;
};

