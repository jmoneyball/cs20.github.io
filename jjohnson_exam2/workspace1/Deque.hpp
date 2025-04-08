#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class Deque : public Queue<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the deque
        int maxSize;

        // the current position of the front element in the deque
        int frontIndex;

        // the current position of the back element in the deque
        int backIndex;

        // copy the values from the argument deque to `this`
        void copy(const Deque<T>&);

    public:
        // default constructor
        Deque(int = 100);

        // copy constructor
        Deque(const Deque<T>&);

        // overloaded assignment operator
        Deque<T>& operator=(const Deque<T>&);

        // destructor
        virtual ~Deque();

        // return the element at the back of the deque
        virtual T back() const override;

        // remove all elements in the deque
        virtual void clear() override;

        // remove the front element from the deque
        virtual void dequeue() override;

        // remove the back element from the deque
        void dequeueBack();

        // add the argument to the back of the deque
        virtual void enqueue(const T&) override;

        // add the argument to the front of the deque
        void enqueueFront(const T&);

        // return the element at the front of the deque
        virtual T front() const override;

        // return the current length of the deque
        virtual int getLength() const override;

        // return the maximum size of the deque
        int getMaxSize() const;

        // determine if the deque is currently empty
        virtual bool isEmpty() const override;

        // determine if the deque is currently full
        bool isFull() const;
};

template <typename T>
void Deque<T>::dequeueBack() {
    // TODO
    if (isEmpty()) {
        cout << "ERROR: deque is empty, avoiding underflow\n";
    }
    else {
        if(backIndex == 0)
        	backIndex = maxSize - 1;
        else
        	backIndex = (backIndex - 1) % maxSize;
        this->length--;
    }
}

template <typename T>
void Deque<T>::enqueueFront(const T& elem) {
    // TODO
    if (isFull()) {
        cout << "ERROR: deque is full, avoiding overflow\n";
    }
    else {
        if(buffer == nullptr)
            buffer = new T[maxSize];
        else if(frontIndex == 0)
        	frontIndex = maxSize - 1;
        else
			frontIndex = (frontIndex - 1) % maxSize;
        buffer[frontIndex] = elem;
 		this->length++;
    }
}



/*******************************************************************************
*   Methods below are the same ones as the normal array-based queue.
*   You don't need to change anything below.
*******************************************************************************/

template <typename T>
Deque<T>::Deque(int i) {
    maxSize = i;
    frontIndex = 0;
    backIndex = maxSize - 1;
    buffer = new T[maxSize];
}

template <typename T>
Deque<T>::Deque(const Deque<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
Deque<T>::~Deque() {
    clear();
}

template <typename T>
T Deque<T>::back() const {
    if (isEmpty()) {
        cout << "ERROR: deque is empty, cannot access the back\n";
        throw -1;
    }

    return buffer[backIndex];
}

template <typename T>
void Deque<T>::clear() {
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize - 1;
    delete[] buffer;
    buffer = nullptr;
}

template <typename T>
void Deque<T>::copy(const Deque<T>& copyObj) {
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

template <typename T>
void Deque<T>::dequeue() {
    if (isEmpty()) {
        cout << "ERROR: deque is empty, avoiding underflow\n";
    }
    else {
        frontIndex = (frontIndex + 1) % maxSize;
        this->length--;
    }
}

template <typename T>
void Deque<T>::enqueue(const T& elem) {
    if (isFull()) {
        cout << "ERROR: deque is full, avoiding overflow\n";
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

template <typename T>
T Deque<T>::front() const {
    if (isEmpty()) {
        cout << "ERROR: deque is empty, cannot access the front\n";
        throw -1;
    }

    return buffer[frontIndex];
}

template <typename T>
int Deque<T>::getLength() const {
    return this->length;
}

template <typename T>
int Deque<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool Deque<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool Deque<T>::isFull() const {
    return this->length == maxSize;
}

#endif
