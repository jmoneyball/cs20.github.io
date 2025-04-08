#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayQueue : public Queue<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the queue
        int maxSize;

        // the current position of the front element in the queue
        int frontIndex;

        // the current position of the back element in the queue
        int backIndex;

        // copy the values from the argument queue to `this`
        void copy(const ArrayQueue<T>&);

    public:
        // default constructor
        ArrayQueue(int = 100);

        // copy constructor
        ArrayQueue(const ArrayQueue<T>&);

        // overloaded assignment operator
        ArrayQueue<T>& operator=(const ArrayQueue<T>&);

        // destructor
        virtual ~ArrayQueue();

        // return the element at the back of the queue
        virtual T back() const override;

        // remove all elements in the queue
        virtual void clear() override;

        // remove the front element from the queue
        virtual void dequeue() override;

        // add the argument to the back of the queue
        virtual void enqueue(const T&) override;

        // return the element at the front of the queue
        virtual T front() const override;

        // return the current length of the queue
        virtual int getLength() const override;

        // return the maximum size of the queue
        int getMaxSize() const;

        // determine if the queue is currently empty
        virtual bool isEmpty() const override;

        // determine if the queue is currently full
        bool isFull() const;
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
	buffer = new T [i];
	maxSize = i;
	frontIndex = backIndex = -1;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of accesses to the buffer.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
	if(backIndex == -1) return 0;
	else return buffer[backIndex];
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::clear() {
	// TODO
    this->length = 0;
    frontIndex = backIndex = -1;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Assume the copy queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(n)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
	for(int i = 0; i < copyObj.maxSize; i++)
		this->buffer[i] = copyObj.buffer[i];
	this->length = copyObj.length;
	this->frontIndex = copyObj.frontIndex;
	this->backIndex = copyObj.backIndex;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
	if(!isEmpty()) {
		if(frontIndex == backIndex)
			frontIndex = backIndex = -1;
		else
			frontIndex = frontIndex + 1 % maxSize;
		this->length--;
	}
	else
		cout << "UNDERFLOW ERROR: the queue is currently empty...\n";
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Assume the queue is not full.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
	//TODO
	if(!isFull()) {
		if(frontIndex == -1)
			frontIndex = 0;
		backIndex = backIndex + 1 % maxSize;
		buffer[backIndex] = elem;
		this->length++;
	}
	else
		cout << "OVERFLOW ERROR: the queue is currently full...\n";
}

/*******************************************************************************
*   Analyzing the number of accesses to the buffer.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
	if(frontIndex == -1) return 0;
	else return buffer[frontIndex];
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}

#endif
