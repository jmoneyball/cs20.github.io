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
*       T(n) = 4
*       -->
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    maxSize = i;
    frontIndex = 0;
    backIndex = maxSize - 1;
    buffer = new T[maxSize];
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = 2n + 7
*       -->
*       T(n) = O(n)
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
*       T(n) = 4 + 2n + 7
*            = 2n + 11
*       -->
*       T(n) = O(n)
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
*       T(n) = 6
*       -->
*       T(n) = O(1)
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
*       T(n) = 1
*       -->
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
T ArrayQueue<T>::back() const {
    if (isEmpty()) {
        cout << "ERROR: queue is empty, cannot access the back\n";
        throw -1;
    }

    return buffer[backIndex];
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = 4
*       -->
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::clear() {
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize - 1;
    delete[] buffer;
    buffer = nullptr;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Assume the copy queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = 5 + 1 + 2n + 1
*            = 2n + 7
*       -->
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    frontIndex = 0;
    backIndex = maxSize - 1;
    buffer = new T[maxSize];

    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[(copyObj.frontIndex + i) % maxSize];
    }

    if (this->length > 0) {
        backIndex = this->length - 1;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = 2
*       -->
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty()) {
        cout << "ERROR: queue is empty, avoiding underflow\n";
    }
    else {
        frontIndex = (frontIndex + 1) % maxSize;
        this->length--;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Assume the queue is not full.
*
*   Asymptotic analysis:
*       T(n) = 3 OR 4
*       -->
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) {
        cout << "ERROR: queue is full, avoiding overflow\n";
    }
    else {
        if (buffer == nullptr) {
            buffer = new T[maxSize];
        }

        backIndex = (backIndex + 1) % maxSize;
        buffer[backIndex] = elem;
        this->length++;
    }
}

/*******************************************************************************
*   Analyzing the number of accesses to the buffer.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = 1
*       -->
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) {
        cout << "ERROR: queue is empty, cannot access the front\n";
        throw -1;
    }

    return buffer[frontIndex];
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = 1
*       -->
*       T(n) = O(1)
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
*       T(n) = 1
*       -->
*       T(n) = O(1)
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
*       T(n) = 1
*       -->
*       T(n) = O(1)
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
*       T(n) = 1
*       -->
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}

#endif
