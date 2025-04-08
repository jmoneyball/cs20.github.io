#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayList : public List<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the list
        int maxSize;

        // copy the values from the argument list to `this`
        void copy(const ArrayList<T>&);

    public:
        // constructor with the maximum size as the argument
        ArrayList(int = 100);

        // copy constructor
        ArrayList(const ArrayList<T>&);

        // overloaded assignment operator
        ArrayList<T>& operator=(const ArrayList<T>&);

        // destructor
        virtual ~ArrayList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // return the maximum size of the list
        int getMaxSize() const;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // determine if the list currently full
        bool isFull() const;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        /***********************************************************************
        *   Analyzing the number of output operations.
        *   Input size n is the length of the list.
        *
        *   Scenario #1, the if block executes:
        *       T(n) = 1
        *
        *   Scenario #2, the else block executes:
        *       T(n) = 2n + 1
        *
        *   Asymptotic analysis:
        *       T(n) = O(n)
        ***********************************************************************/
        friend ostream& operator<<(ostream& outStream, const ArrayList& myObj) {
            if (myObj.isEmpty()) {
                outStream << "List is empty, no elements to display.\n";
            }
            else {
                for (int i = 0; i < myObj.length; i++) {
                    outStream << myObj.buffer[i] << ' ';
                }

                outStream << endl;
            }

            return outStream;
        }
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   T(n) = 2
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
ArrayList<T>::ArrayList(int i) {
    maxSize = i;
    buffer = new T[maxSize];
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   T(n) = 2n + 4
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Scenario #1, the if block does not execute:
*       T(n) = 0
*
*   Scenario #2, the if block executes:
*       T(n) = 2 + 2n + 4
*            = 2n + 6
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

/*******************************************************************************
*   Analyzing the number of delete operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Scenario #1, the if block executes:
*       T(n) = 0
*
*   Scenario #2, the else block executes and the buffer is a nullptr:
*       T(n) = 3
*
*   Scenario #3, the else block executes and the buffer is not nullptr:
*       T(n) = 2
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (isFull()) {
        cout << "ERROR: list is full\n";
    }
    else {
        if (buffer == nullptr) {
            buffer = new T[maxSize];
        }

        buffer[this->length] = elem;
        this->length++;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   T(n) = 2
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void ArrayList<T>::clear() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   T(n) = 3 + 1 + 2n
*        = 2n + 4
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];

    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

/*******************************************************************************
*   Analyzing the number of buffer accesses.
*   Input size n is the length of the list.
*
*   Scenario #1, the if block executes:
*       T(n) = 0
*
*   Scenario #2, the if block does not execute:
*       T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
        throw -1;
    }

    return buffer[position];
}

/*******************************************************************************
*   Analyzing the number of attribute accesses.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

/*******************************************************************************
*   Analyzing the number of accesses.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is 0 and the list is not full.
*
*   T(n) = 1 + 2n + 2
*        = 2n + 3
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else if (isFull()) {
        cout << "ERROR: list is full\n";
    }
    else {
        for (int i = this->length; i > position; i--) {
            buffer[i] = buffer[i - 1];
        }
        
        buffer[position] = elem;
        this->length++;
    }
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is 0.
*
*   T(n) = 1 + 2(n - 1) + 1
*        = 2n
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void ArrayList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else {
        for (int i = position; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1];
        }

        this->length--;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Scenario #1, the if block executes:
*       T(n) = 0
*
*   Scenario #2, the else block executes:
*       T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else {
        buffer[position] = elem;
    }
}

#endif
