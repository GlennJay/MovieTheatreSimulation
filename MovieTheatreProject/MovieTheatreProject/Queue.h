#pragma once





template <class T>
class Queue
{
public:
	// Constructors
	Queue(int size);  // initial capacity

	// Copy constructor
	Queue(const Queue<T> &otherQueue);

	// Assignment operator
	Queue<T> &operator =(
		const Queue<T> &otherQueue);

	// Destructor
	~Queue();

	// Determine emptiness or fullness
	bool isEmpty() const;
	bool isFull() const;

	// See value at front
	T front() const;

	// Add value to rear
	inline void add(const T &val);

	// Remove value at front
	void del();

private:
	T *elements;    // Point to dynamic array that will store each person in line
	int capacity;   // Size of the line (group) in each sale
	int frontIndex; // will be for each person that is at the head of the line
	int numStored;  // Number values stored

};

