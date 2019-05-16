//#ifndef SEATCHART_CPP
//#define SEATCHART_CPP
//
//#include <iostream>
//#include "seatChart.h"
//
//
//
//template<class T>
//seatChart<T>::seatChart(int size)
//{
//	stored = new T[size];  // allocate dynamic array
//	used = new bool[size] {false}; //allocate dynamic array and initialize elements to false
//	storedSize = size;
//	clear();
//}
//
//
//
//
//// COPY CONSTRUCTOR
//template<class T>
//seatChart<T>::seatChart(const seatChart<T> &otherSeatChart)
//{
//	// Copy non-dynamic array members.
//	storedSize = otherSeatChart.storedSize;
//
//	// Allocate new array for copy of other seatChart.
//	stored = new T[storedSize];
//
//	for (int i = 0; i < storedSize; i++)
//		stored[i] = otherSeatChart.stored[i];
//}
//
//// Destructor
//template<class T>
//seatChart<T>::~seatChart()
//{
//	std::cout << "In destrucotr: stored[0] =" << stored[0] << std::std::endl;
//	std::cout << "In destructor: used[0] =" << used[0] << std::std::endl;
//	delete[] stored;  // deallocate dynamic array
//	delete[] used;	  // deallocate dynamic array
//	stored = NULL;     // prevent dangling pointer
//	used = NULL;		//prevent dangling pointer
//	storedSize = 0;    // reset other member
//}
//
//// WRITE ASSIGNMENT OPERATOR
//template<class T>
//seatChart<T> &seatChart<T>::operator =(const seatChart<T> &letterHistory)
//{
//	if (this != &letterHistory)
//	{
//		//deallocate old array
//		delete[] stored;
//		stored = new T[letterHistory.storedSize];
//
//		//allocate new array for copy of seatChart
//		storedSize = letterHistory.storedSize;
//
//		for (int i = 0; i < letterHistory.storedSize; i++)
//			stored[i] = letterHistory.stored[i];
//		//return *this;
//	}
//	return *this ;
//}
//
//
//// Accessors
//
//template<class T>
//T seatChart<T>::get(int i) const
//{
//	if (i >= 0 && i < storedSize)
//		return stored[i];
//	else
//	{
//		std::cerr << "Invalid seatChart index: " << i << std::std::endl;
//		return T();
//	}
//}
//
//
//template<class T>
//void seatChart<T>::output() const
//{
//	std::cout << "seatChart:";
//
//	for (int i = 0; i < storedSize; i++)
//		if (used[i] == true) 
//			std::cout << " " << stored[i];
//}
//
//// Mutators
//
//template<class T>
//void seatChart<T>::add(const T &val)
//{
//	for (int i = 0; i < storedSize; i++)
//		if (used[i] == false)
//		{
//			stored[i] = val;
//			used[i] = true;
//
//			break;
//		}
//
//
//}
//
//// Clear price seatChart (default value entries signals unused entries).
//template<class T>
//void seatChart<T>::clear()
//{
//	for (int i = 0; i < storedSize; i++)
//	{
//		stored[i] = T();
//		//used[i] = false;
//	}
//}
//#endif