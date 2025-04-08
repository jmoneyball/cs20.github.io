#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Stack.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayStack : public Stack<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the stack
        int maxSize;

        // copy the values from the argument stack to `this`
        void copy(const ArrayStack<T>&);

    public:
        // default constructor
        ArrayStack(int = 100);

        // copy constructor
        ArrayStack(const ArrayStack<T>&);

        // overloaded assignment operator
        ArrayStack<T>& operator=(const ArrayStack<T>&);

        // destructor
        virtual ~ArrayStack();

        // remove all elements in the stack
        virtual void clear() override;

        // return the current length of the stack
        virtual int getLength() const override;

        // return the maximum size of the stack
        int getMaxSize() const;

        // determine if the stack currently empty
        virtual bool isEmpty() const override;

        // determine if the stack is currently full
        bool isFull() const;

        // remove the top element from the stack
        virtual void pop() override;

        // add the argument to the top of the stack
        virtual void push(const T&) override;

        // return the element at the top of the stack
        virtual T top() const override;
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
ArrayStack<T>::ArrayStack(int i) {
	if(maxSize <= 0) {
		cout << "Error... maxSize of stack must be positive";
		exit(-1);
	}
	else {
		buffer = new T [i];
		maxSize = i;
	}
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*   2 + 2n + 3n = 5n + 2
*       O(n)
*******************************************************************************/
template <typename T>
void ArrayStack<T>::clear() {
    for(int i = 0; i < this->length; i++) {
    	this->pop();
    	this->length--;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*   4 + 2n
*       O(n)
*******************************************************************************/
template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
	this->maxSize = copyObj.maxSize;
	this->length = copyObj.length;
	buffer = new int[maxSize];
	for(int i = 0; i < copyObj.length; i++)
		buffer[i] = copyObj.buffer[i];
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the stack.
*
*   Assume the stack is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
void ArrayStack<T>::pop() {
	if(!isEmpty()) {
	    buffer[this->length - 1] = 0;
	    this->length--;
	}
	else cout << "Error... cannot remove from an empty stack" << endl;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the stack.
*
*   Assume the stack is not full.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
void ArrayStack<T>::push(const T& elem) {
	if(!isFull()) {
	    buffer[this->length] = elem;
	    this->length++;
	}
	else cout << "Error... cannot add to a full stack" << endl;
}

/*******************************************************************************
*   Analyzing the number of accesses to the buffer.
*   Input size n is the length of the stack.
*
*   Assume the stack is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
T ArrayStack<T>::top() const {
	if(!isEmpty()) return buffer[this->length - 1];
	else {
		cout << "Error... the stack is empty" << endl;
		return 0;
	}
}
#endif
