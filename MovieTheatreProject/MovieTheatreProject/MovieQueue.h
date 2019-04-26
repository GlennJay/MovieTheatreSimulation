#pragma once
template <class Q>
class MovieQueue
{
public:
	//constructors
	//MovieQueue(); //default

	MovieQueue(int size);

	//copy
	MovieQueue(const MovieQueue<Q> &otherQueue);

	//assignment
	MovieQueue<Q> & operator=(const MovieQueue<Q> &otherQueue);

	//destructor
	~MovieQueue();

	//determines full or empty
	bool isFull() const;
	bool isEmpty() const;

	//access front
	Q front() const;

	//mutators
	void add(const Q &newPatron);

	Q remove();

private:
	Q *patron; //dynamic array
	int maxSize;	//size of array
	int frontIndex; //acces to front index
	int stored; //amount stored in array
	
};

